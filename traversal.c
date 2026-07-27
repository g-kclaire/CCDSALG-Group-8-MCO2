/**
    Group #: 08  (2 digits)

    GAN, KRISTINE CLAIRE    S09
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

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

    //Make a duplicate of the adjacency list array parameter
    // for(int i=0;i<numVer;i++)
    // 	output5List[i] = a[i];

    //Generate output#5 name format
    if (startIndex >= 0) {
    strcpy(output5fn,fn);
    strcat(output5fn,"-BFS.TXT");

    //Open or create new text file for output file#3
    new5=fopen(output5fn,"w");
} else 
{
    new5 = NULL;
}

    if (new5 != NULL) {
        visited[startIndex] = 1;
        queue[rear] = startIndex;
        rear++;

        while (front < rear) {
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

                for (int j = 0; j < a[current].numID; j++) {
                    int candidate = findVertexIndex(
                        a,
                        numVer,
                        a[current].adjacentIDs[j]
                    );

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
