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

#include "graph.h"

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will read in the IDs and their respective list of
    adjacent IDs written in the given text file.
    e. Return: none
    f. Parameters: fileName[] is the string containing the name of the file to read
    inputs from, a[] is the array of adjacency lists for each ID, and numVer is the
    number of vertices in the given file
*/
void readSNSFile(char fileName[], AdjacencyList a[], FILE *fp, int *numVer)
{
    //Scan the current number of vertices
    fscanf(fp,"%d",numVer);

    //Read info from file into array of adjacency lists
    for(int i=0;i<*numVer;i++){
        //Read name of current adjacency list owner
        fscanf(fp,"%s ",a[i].name);
        int j=0;
        //Read list of IDs into the current adjacency list array
        while(fscanf(fp,"%s",a[i].adjacentIDs[j])==1 && strcmp(a[i].adjacentIDs[j],"-1")){
            j++;
        }
        //Assign current ID tally to the variable of the number of IDs
        a[i].numID = j;
    }
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will read in the IDs and their respective list of
    adjacent IDs written in the given text file.
    e. Return: none
    f. Parameters: fileName[] is the string containing the name of the file to read
    inputs from, a[] is the array of adjacency lists for each ID, and numVer is the
    number of vertices in the given file
*/
void outputTXT2(Filename fn){
    // FILE* new2;
    Filename output2fn;
    strcpy(output2fn,fn);
    strcat(output2fn,"-DEGREE.TXT");
    printf("\nTEST : %s\n",output2fn);
    // new2=fopen(output2fn,"w");
}