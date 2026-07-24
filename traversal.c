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
#include <stdlib.h>
#include <string.h>

#include "graph.c"

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: 
    f. Parameters: @fn is used for creating the output#5 filename, @a is the array of
    adjacency lists, and @numVer is the number of vertices in the file
*/
void outputTXT5(Filename fn, AdjacencyList a[], int numVer) {
    FILE* new5;
    Filename output5fn;
    AdjacencyList output5List[numVer];
    int curVer;

    //Make a duplicate of the adjacency list array parameter
    // for(int i=0;i<numVer;i++)
    // 	output5List[i] = a[i];

    //Generate output#5 name format
    strcpy(output5fn,fn);
    strcat(output5fn,"-BFS.TXT");

    //Open or create new text file for output file#3
    new5=fopen(output5fn,"w");



    //Close file pointer
    fclose(new5);
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: 
    f. Parameters: 
*/
void helperTXT5(AdjacencyList og[], AdjacencyList bfs[], int *curSize, int index, int numVer){

    //Check if the current size of the BFS arr is equivalent to the size of the original arr
    if(*curSize!=numVer-1){
        int notFound;

        //Assign the first adjacent list from the original array to the BFS array when BFS array is empty
        if(bfs==NULL){
            bfs[*curSize] = og[index];
            *curSize++; //Increment BFS arr size counter
        }

        //Organize list based on alphabetical order
        selsortList(bfs,numVer);

        //Check if an ID in the adjacency list already exists in the BFS arr
        for(int i=0;i<bfs[*curSize].numID;i++) {
            notFound=1;
            //Compare current ID with the ID names in the BFS arr
            for(int j=0;j<*curSize;j++) {
                if(strcmp(bfs[*curSize].adjacentIDs[i],bfs[j].name)==0)
                    notFound=0;
            }
            //If the current ID from the original arr is not found in BFS arr, add it to that arr
            if(notFound){
                bfs[*curSize] = og[i];
                *curSize++; //Increment BFS arr size counter
            }
        }
    }
}