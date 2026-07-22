/**
    Group #: 08  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
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

#include "graph.c"

int main(){
    FILE* fp;
    int numVer;

    //Open the given file
    fp=fopen("G.txt", "r");
    fscanf(fp,"%d",&numVer);
    fclose(fp);
    
    AdjacencyList a[numVer];
    readSNSFile("G.text",a,numVer);

    //Test print results
    for(int i=0;i<numVer;i++){
        printf("%s",a[i].name);
        for(int j=0;j<a[i].numID;j++)
            printf("%s ",a[i].adjacentIDs[j]);
        printf("\n");
    }

    
    return 0;
}