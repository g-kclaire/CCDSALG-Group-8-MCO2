/**
    Group #: 08  (2 digits)

    GAN, KRISTINE CLAIRE    S09
    MESA, MONICA    S09
    VILLARIN, NICOLAI PAOLO  S09 

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
    AdjacencyList a[MAX_NUM_VERTICES];


    /*Get user input for filename of the input, and make sure inputted filename is exists.
    Terminate program if it does not. */
	printf("Input filename (eg. <FILENAME>.txt): ");
	scanf("%29s",fntxt);

    fp = fopen(fntxt, "r");
    
    if (fp == NULL) {
    printf("File %s not found.\n", fntxt);
    return 0;
    }
    
    //Create array of adjacency lists with size of @numVer, and assign ID names to it
    readSNSFile(fntxt, a, fp, &numVer);
    
    //Call func to get filename w/o ".txt"
    getFilename(fntxt, &fn);

    //Call output file funcs
    outputTXT1(fn, a, numVer);
    outputTXT2(fn, a, numVer);
    outputTXT3(fn, a, numVer);
    outputTXt4(fn, a, numVer);

    //Close the file
    fclose(fp);
    return 0;
}