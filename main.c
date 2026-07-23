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

int main(){
    FILE* fp;
    Filename fntxt,fn;
    int numVer;

    /*Get user input for filename of the input, and make sure inputted filename is exists.
    Terminate program if it does not. */
	printf("Input filename (eg. <FILENAME>.txt): ");
	scanf("%s",fntxt);
    if((fp=fopen(fntxt,"r"))==0){
        printf("File %s not found.\n",fntxt);
        return 0;
    }

    //Get the number of vertices
    fscanf(fp,"%d ",&numVer);
    
    //Create array of adjacency lists and assign ID names to it
    AdjacencyList a[numVer];
    readSNSFile(fntxt,a,fp,&numVer);

    //Get name of file without ".txt"
    strncpy(fn,fntxt,FILE_NAME_SIZE);
    strcat(fn,"\0");
    
    outputTXT2(fn,a,numVer);
    outputTXT3(fn,a,numVer);

    //Test print results
    for(int i=0;i<numVer;i++){
        printf("%s - ",a[i].name);
        for(int j=0;j<a[i].numID;j++)
            printf("%s ",a[i].adjacentIDs[j]);
        printf("%d\n",a[i].numID);
    }
    //Close the file
    fclose(fp);
    return 0;
}