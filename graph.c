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
    d. Purpose: This function will read in the IDs, the number of IDs, and their
    respective list of adjacent IDs written in the given text file.
    e. Return: none
    f. Parameters: @fileName[] is the string containing the name of the file to read
    inputs from, @a[] is the array of adjacency lists for each ID, @*fp is the file pointer
    coming from the driver code, and @numVer is the number of vertices in the given file
*/
void readSNSFile(char fileName[], AdjacencyList a[], FILE *fp, int *numVer) {
    
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
    d. Purpose: This function will generate the expected output for the second output file.
    It sorts the list of vertices based on alphabetical order, and shows the number of
    adjacent IDs each vertex is connected to.
    e. Return: none
    f. Parameters: @fn is used for creating the output#2 filename, @a is the array of
    adjacency lists, and @numVer is the number of vertices in the file
*/
void outputTXT2(Filename fn, AdjacencyList a[], int numVer){
    FILE* new2;
    Filename output2fn;
    AdjacencyList output2List[numVer], temp;
    
    //Make a duplicate of the adjacency list array parameter
    for(int i=0;i<numVer;i++)
    	output2List[i] = a[i];

    //Generate output#2 name format
    strcpy(output2fn,fn);
    strcat(output2fn,"-DEGREE.TXT");

    //Open or create new text file for output file#2
    new2=fopen(output2fn,"w");

    //Organize list based on alphabetical order
    for(int i=0;i<numVer-1;i++){
        int min = i;
        for(int j=i+1;j<numVer;j++){
            if(strcmp(output2List[min].name,output2List[j].name)==1)
                min=j;
        }
        temp=output2List[min];
        output2List[min]=output2List[i];
        output2List[i]=temp;
    }
    
    //Print adjacency list info into output#2 file
    for(int i=0;i<numVer;i++)
        fprintf(new2,"%s\t%d\n",output2List[i].name,output2List[i].numID);
    
    //Close file pointer
    fclose(new2);
}

