/**
    Group #: 08  (2 digits)

    GAN, KRISTINE CLAIRE        S09
    MESA, MONICA                S09
    VILLARIN, NICOLAI PAOLO     S09 

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <string.h>

#include "graph.h"

/*
    a. Name of Programmer(s):  Nicolai Paolo Villarin
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will search for a vertex ID in the adjacency-list array 
    and return its corresponding array index.
    e. Return: The index of the matching vertex, or -1 if the vertex is not found.
    f. Parameters: @a is the array of adjacency lists, @numVer is the number of vertices,
    and @vertexID is the vertex ID being searched.
*/
int findVertexIndex(AdjacencyList a[], int numVer, ID vertexID) {
    int index = -1;

    for (int i = 0; i < numVer; i++) {
        if (strcmp(a[i].name, vertexID) == 0) {
            index = i;
            break;
        }
    }

    return index;
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan, Nicolai Paolo Villarin
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will generate the expected output for the fifth
    output file. It will perform a Breadth First Search starting from the 
    specified vertex and will visit the lowest available vertex ID first.
    f. Parameters: @fn is used for creating the output#5 filename, @a is the array of
    adjacency lists, @numVer is the number of vertices in the file, and @startVertex is 
    the BFS starting vertex ID.
*/
void outputTXT5(Filename fn, AdjacencyList a[], int numVer, ID startVertex) {
    FILE* new5;
    Filename output5fn;
    int queue[MAX_NUM_VERTICES];
    int visited[MAX_NUM_VERTICES] = {0};
    int traversal[MAX_NUM_VERTICES];
    int front = 0;
    int rear = 0;
    int traversalCount = 0;
    int startIndex = findVertexIndex(a, numVer, startVertex);

    //Generate output#5 name format
    if (startIndex >= 0) {
        strcpy(output5fn,fn);
        strcat(output5fn,"-BFS.TXT");

        //Open or create new text file for output file#5
        new5=fopen(output5fn,"w");
    } else 
        new5 = NULL;

    if (new5 != NULL) {
        //Mark selected start vertex as visited by assigning it with 1
        visited[startIndex] = 1;
        //Assign index number of start vertex to first element in queue
        queue[rear] = startIndex;
        rear++;

        while (front < rear) {
            //Assign index number of current vertex to queue and traversal arr
            int current = queue[front];
            front++;

            traversal[traversalCount] = current;
            traversalCount++;

            /*
                Select the lowest unvisited adjacent vertex first.
                This makes BFS independent of input adjacency order.
            */
            while (1) {
                int nextIndex = -1;

                //Scan through elements in adjacency list of current vertex
                for (int j = 0; j < a[current].numID; j++) {
                    int candidate = findVertexIndex(
                        a,
                        numVer,
                        a[current].adjacentIDs[j]
                    );

                    //Check if index exists and has not been visited yet
                    if (candidate >= 0 && !visited[candidate]) {
                        if (nextIndex == -1 ||
                            strcmp(a[candidate].name,
                                   a[nextIndex].name) < 0) {
                            nextIndex = candidate;
                        }
                    }
                }

                if (nextIndex == -1) {
                    break;
                }

                visited[nextIndex] = 1;
                queue[rear] = nextIndex;
                rear++;
            }
        }

        for (int i = 0; i < traversalCount; i++) {
            if (i > 0) {
                fprintf(new5, " ");
            }

            fprintf(new5, "%s", a[traversal[i]].name);
        }

        fprintf(new5, "\n");
        fclose(new5);
    }
}

AdjacencyList getAdjacencyList(AdjacencyList a[], ID name, int numVer){
    AdjacencyList temp;

    for(int i=0;i<numVer;i++)
        if(strcmp(a[i].name, name)==0)
            temp=a[i];

    return temp;
}

void helperTXT6(AdjacencyList a[], AdjacencyList output6List[], int visited[], int numVer, int *list6Index, int start){
    int nextIndex;
	//Mark selected vertex as visited by assigning it with 1
    visited[start]=1;
    printf("%d %d\n",*list6Index,start);
    output6List[*list6Index]=a[start];
    *list6Index+=1;

    for(int i=0;i<numVer;i++){
        if(a[start].adjacentIDs[i] && visited[findVertexIndex(a,numVer,a[start].adjacentIDs[i])]==0){
            printf("%s\n",a[start].adjacentIDs[i]);
            nextIndex = findVertexIndex(a,numVer,a[start].adjacentIDs[i]);
            helperTXT6(a,output6List,visited,numVer,list6Index,nextIndex);
        }
    }
}

void outputTXT6(Filename fn, AdjacencyList a[], int numVer, ID startVertex){
    FILE* new6;
    Filename output6fn;
    AdjacencyList output6List[numVer];
    int visited[numVer];
    int startIndex = findVertexIndex(a, numVer, startVertex), list6Index=0;

    //Generate output#6 name format
    if (startIndex >= 0) {
        strcpy(output6fn,fn);
        strcat(output6fn,"-DFS.TXT");

        //Open or create new text file for output file#6
        new6=fopen(output6fn,"w");
    } else 
        new6 = NULL;

    if(new6!=NULL)
        helperTXT6(a,output6List,visited,numVer,&list6Index,startIndex);

    //Print DFS values into file
    for (int i = 0; i < numVer; i++) {
            if (i > 0) {
                fprintf(new6, " ");
            }

            fprintf(new6, "%s", output6List[i].name);
        }

    fprintf(new6, "\n");
    //Close file pointer
    fclose(new6);
}