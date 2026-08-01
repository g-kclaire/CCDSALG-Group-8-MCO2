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

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will sort the list of IDs in the given ID array based
    on alphabetical order
    e. Return: none
    f. Parameters: @list is the array of IDs to be sorted, and @numID is the number 
	of IDs in the list
*/
void selsortIDs(ID list[], int numID){
	ID temp;

    //Organize list based on alphabetical order
    for(int i=0;i<numID-1;i++){
        int min = i;
        for(int j=i+1;j<numID;j++){
            if(strcmp(list[min],list[j])>0)
                min=j;
        }
        
        if(min!=i){
	        strcpy(temp,list[min]);
	        strcpy(list[min],list[i]);
	        strcpy(list[i],temp);
		}
    }
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will traverse through the graph using the DFS algorithm.
    It will begin at the given start index, and go through the entire graph until
    all vertices have been visited.
    e. Return: none
    f. Parameters: @a is the graph, @output6List is where the DFS-based traversal is
    stored, @visited is the array showing which vertices have been visited, @numVer is
    the number of vertices in the graph, @*list6Index is the current index number in the
    DFS traversal, and @start is the start index where the DFS traversal will begin
*/
void helperTXT6(AdjacencyList a[], AdjacencyList output6List[], int visited[], int numVer, int *list6Index, int start){
    int nextIndex;
    
	//Mark selected vertex as visited by assigning it with 1
    visited[start]=1;
    output6List[*list6Index]=a[start];
    *list6Index+=1;

	//Scan through index of IDs of current vertex
    for(int i=0;i<a[start].numID;i++){
        if(a[start].adjacentIDs[i] && visited[findVertexIndex(a,numVer,a[start].adjacentIDs[i])]==0){
        	
        	//Set new start index with index number of next adjacent ID
            nextIndex = findVertexIndex(a,numVer,a[start].adjacentIDs[i]);
            
            //Call function recursion for adjacent vertex ID
            helperTXT6(a,output6List,visited,numVer,list6Index,nextIndex);
        }
    }
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will generate the expected output for the sixth output file.
    It creates a file based on the Depth Search graph traversal of the passed file.
    e. Return: none
    f. Parameters: @fn is used for creating the output#6 filename, @a is the array of
    adjacency lists, and @numVer is the number of vertices in the file
*/
void outputTXT6(Filename fn, AdjacencyList a[], int numVer, ID startVertex){
    FILE* new6;
    Filename output6fn;
//    AdjacencyList sortedList[numVer];
	AdjacencyList output6List[numVer];
    int visited[numVer];
    int startIndex = findVertexIndex(a, numVer, startVertex), list6Index=0;

    //Initialize all visited nodes to 0
    for (int i = 0; i < numVer; i++) {
        visited[i] = 0;
    }

    //Initialize all output6List to empty strings
    for (int i = 0; i < numVer; i++) {
        strcpy(output6List[i].name, ""); 
    }

    //Generate output#6 name format
    if (startIndex >= 0) {
        strcpy(output6fn,fn);
        strcat(output6fn,"-DFS.TXT");

    	//Open or create new text file for output file#6
        new6=fopen(output6fn,"w");
    } else 
        new6 = NULL;
    
    //Sort the list of adjacent IDs based on alphabetical order
    for(int i=0;i<numVer;i++)
		selsortIDs(a[i].adjacentIDs,a[i].numID);

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