/**
    Group #: 08  (2 digits)

    GAN, KRISTINE CLAIRE    S09
    MESA, MONICA    S09
    VILLARIN, NICOLAI PAOLO    S09 

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
    a. Name of Programmer(s):  Kristine Claire Gan, Nicolai Paolo Villarin
    b. Name of Tester(s)    :  Monica Mesa
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will read in the IDs, the number of IDs, and their
    respective list of adjacent IDs written in the given text file.
    e. Return: none
    f. Parameters: @fileName[] is the string containing the name of the file to read
    inputs from, @a[] is the array of adjacency lists for each ID, @*fp is the file pointer
    coming from the driver code, and @numVer is the number of vertices in the given file
*/
void readSNSFile(char fileName[], AdjacencyList a[], FILE *fp, int *numVer) {
    (void)fileName;

    //Scan the current number of vertices
    fscanf(fp,"%d",numVer);

    //Read info from file into array of adjacency lists
    for(int i=0;i<*numVer;i++){

        //Read name of current adjacency list owner
        fscanf(fp,"%8s ",a[i].name);
        int j=0;

        //Read list of IDs into the current adjacency list array
        while(j < MAX_NUM_VERTICES && fscanf(fp,"%8s",a[i].adjacentIDs[j])==1 && strcmp(a[i].adjacentIDs[j],"-1")){
            j++;
        }
        //Assign current ID tally to the variable of the number of IDs
        a[i].numID = j;
    }
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan, Nicolai Paolo Villarin
    b. Name of Tester(s)    :  Monica Mesa
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will get the name of the file w/o ".txt" based on user input.
    e. Return: none
    f. Parameters: @fntxt is the inputted filename with ".txt", and @*fn is for storing
    the actual filename itself
*/
void getFilename(Filename fntxt, Filename *fn){
    int i = 0;
    while (fntxt[i] != '\0' && fntxt[i] != '.' && i < (int)sizeof(Filename) - 1) 
    {
        (*fn)[i] = fntxt[i];
        i++;
    }

    (*fn)[i] = '\0';
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  Nicolai Paolo Villarin
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will sort the list of IDs in the given adjacency list array based
    on alphabetical order.
    e. Return: none
    f. Parameters: @list is the array of adjacency lists, and @numVer is the number of vertices in the file
*/
void selsortList(AdjacencyList list[], int numVer){
    AdjacencyList temp;

    //Organize list based on alphabetical order
    for(int i=0;i<numVer-1;i++){
        int min = i;
        for(int j=i+1;j<numVer;j++){
            if(strcmp(list[min].name,list[j].name)>0)
                min=j;
        }
        temp=list[min];
        list[min]=list[i];
        list[i]=temp;
    }
}

/*
    a. Name of Programmer(s):  Monica Mesa
    b. Name of Tester(s)    :  Nicolai Paolo Villarin
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will sort edges alphabetically by checking the starting
                vertices. This will also check the ending vertices if both starting vertices are the same.
    e. Return: none
    f. Parameters: @edgeList is the array that stores the edges, 
                   @numEdges is the number of edges present in the file
*/
void selSortEdges(AdjacencyList edgeList[], int numEdges)
{
    AdjacencyList temp; //temporarily stores index number

    //Organize list based on alphabetical order
    for(int i=0;i<numEdges-1;i++){
        int min = i;
        for(int j=i+1;j<numEdges;j++){
            if(strcmp(edgeList[min].name,edgeList[j].name)>0) //compares starting vertices
                min=j;
            else if(strcmp(edgeList[min].name,edgeList[j].name)==0) //check if starting vertices are the same
                if(strcmp(edgeList[min].adjacentIDs[0],edgeList[j].adjacentIDs[0])>0) //compares ending vertices
                    min=j;
        }
        temp=edgeList[min];
        edgeList[min]=edgeList[i];
        edgeList[i]=temp;
    }
}

/*
    a. Name of Programmer(s):  Monica Mesa
    b. Name of Tester(s)    :  Kristine Claire Gan
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will generate the expected output for the first output file.
                It will provide the vertices and edges present in the provided graph via the TXT file.
    e. Return: none
    f. Parameters: @fn is used for creating the output#1 filename, 
                   @a is the array of adjacency lists, and 
                   @numVer is the number of vertices in the file
*/
void outputTXT1(Filename fn, AdjacencyList a[], int numVer)
{
    FILE* new1;
    Filename output1fn;

    AdjacencyList output1List[numVer];
    AdjacencyList edge1List[MAX_NUM_EDGES];
    int numEdges=0;

    /*Make a duplicate of the adjacency list array parameter*/
    for(int i=0;i<numVer;i++)
     	output1List[i] = a[i];

    //Call selection sort function to sort list
    selsortList(output1List,numVer);

    //Identifies list of edges & the number of edges present
    for(int i=0;i<numVer;i++){
        for(int j=0;j<output1List[i].numID;j++){
            if(strcmp(output1List[i].name,output1List[i].adjacentIDs[j])<0){ //ensures starting vertex comes before ending vertex 
                strcpy(edge1List[numEdges].name,output1List[i].name);
                strcpy(edge1List[numEdges].adjacentIDs[0],output1List[i].adjacentIDs[j]);
                numEdges++;
            }
        }
    }

    //Call selection sort for edges
    selSortEdges(edge1List,numEdges);

    //Generate output#1 name format
    strcpy(output1fn,fn);
    strcat(output1fn,"-SET.TXT");

    //Open or create new text file for output file#1
    new1=fopen(output1fn,"w");

    //Print Vertices
    fprintf(new1,"V(%s)={", fn);
    for(int i=0;i<numVer;i++)
    {
        if(i>0)
            fprintf(new1,",");
        fprintf(new1,"%s",output1List[i].name);
    }
    fprintf(new1,"}\n");

    //Print Edges
    fprintf(new1,"E(%s)={", fn);
    for(int i=0;i<numEdges;i++)
    {
        if(i>0)
            fprintf(new1,",");
        fprintf(new1,"(%s,%s)",edge1List[i].name,edge1List[i].adjacentIDs[0]);
    }
    fprintf(new1,"}\n");

    //Close file pointer
    fclose(new1);
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  Monica Mesa
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
    AdjacencyList output2List[numVer];
    
    //Make a duplicate of the adjacency list array parameter
    for(int i=0;i<numVer;i++)
    	output2List[i] = a[i];

    //Generate output#2 name format
    strcpy(output2fn,fn);
    strcat(output2fn,"-DEGREE.TXT");

    //Open or create new text file for output file#2
    new2=fopen(output2fn,"w");

    //Call selection sort function
    selsortList(output2List,numVer);
    
    //Print adjacency list info into output#2 file
    for(int i=0;i<numVer;i++)
        fprintf(new2,"%s\t%d\n",output2List[i].name,output2List[i].numID);
    
    //Close file pointer
    fclose(new2);
}

/*
    a. Name of Programmer(s):  Kristine Claire Gan
    b. Name of Tester(s)    :  Monica Mesa
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will generate the expected output for the third output file.
    It prints out the adjacency list per vertex.
    e. Return: none
    f. Parameters: @fn is used for creating the output#3 filename, @a is the array of
    adjacency lists, and @numVer is the number of vertices in the file
*/
void outputTXT3(Filename fn, AdjacencyList a[], int numVer){
    FILE* new3;
    Filename output3fn;

    //Generate output#3 name format
    strcpy(output3fn,fn);
    strcat(output3fn,"-LIST.TXT");

    //Open or create new text file for output file#3
    new3=fopen(output3fn,"w");

    //Print adjacency list in output file#3
    for(int i=0;i<numVer;i++){
        fprintf(new3,"%s->",a[i].name);
        for(int j=0;j<a[i].numID;j++)
            fprintf(new3,"%s->",a[i].adjacentIDs[j]);
        fprintf(new3,"\\\n");
    }

    //Close file pointer
    fclose(new3);
}

/*
    a. Name of Programmer(s):  Nicolai Paolo Villarin
    b. Name of Tester(s)    :  Monica Mesa
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will generate the expected output for the fourth output file. 
    It will create an adjacency matrix using the vertex IDs in the same order as they appeared in the input file.
    e. Return: none
    f. Parameters: @fn is used for creating the output#4 filename, @a is the
    array of adjacency lists, and @numVer is the number of vertices in the file

*/
void outputTXT4(Filename fn, AdjacencyList a[], int numVer) {
    FILE *new4;
    Filename output4fn;

    strcpy(output4fn, fn);
    strcat(output4fn, "-MATRIX.TXT");

    new4 = fopen(output4fn, "w");

    if (new4 != NULL) {
        /*
            The matrix uses the same vertex order as the input file.
            Each row searches its original adjacency list for the
            corresponding column vertex.
        */

        /* Print column labels. */
        fprintf(new4, "\t ");
        for (int i = 0; i < numVer; i++) {
            if (i > 0) {
                fprintf(new4, " ");
            }

            fprintf(new4, "%s", a[i].name);
        }

        fprintf(new4, "\n");

        /* Print matrix rows. */
        for (int i = 0; i < numVer; i++) {
            fprintf(new4, "%s", a[i].name);

            for (int j = 0; j < numVer; j++) {
                int connected = 0;

                for (int k = 0; k < a[i].numID; k++) {
                    if (strcmp(a[i].adjacentIDs[k], a[j].name) == 0) {
                        connected = 1;
                        break;
                    }
                }
                
                fprintf(new4, " \t %d", connected);
            }

            fprintf(new4, "\n");
        }

        fclose(new4);
    }
}