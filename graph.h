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

#ifndef DEFS_H // Include this to prevent redefinition error
#define DEFS_H // Include this to prevent redefinition error

#define MAX_NUM_VERTICES    20
#define FILE_NAME_SIZE		1

typedef char ID[8];
typedef char Filename[30];
typedef struct{
    ID name;
    int numID;
    ID adjacentIDs[MAX_NUM_VERTICES];
} AdjacencyList;

#endif //DEFS_H; //Include this to prevent redefinition error