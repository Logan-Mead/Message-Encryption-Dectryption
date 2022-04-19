/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Logan Mead
 * ECE141-Spring 2020
 *
 * Created on April 4, 2020, 2:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
//function headers with inputs of letter and shift
char encryptLetter(char letter, int shift);
char decryptLetter(char letter, int shift);

int main(int argc, char** argv) {
    char inputFile[32];                                                          //initialize inputFiles as a char with a size of 32 
    char outputFile[32];                                                         //initialize outFiles as a char with the size of 32
    char userAction;                                                             //initialize userAction as a char for entering e or f
    char letter = ' ';                                                           //initialize letter as a char to a blank space
    char array[128];                                                             //initialize array as a char with the size of 128
    int i = 0;                                                                   //initialize i to zero
  
    printf("Enter name of input file: ");                                        //asks the user for the name of an input file and save it
    scanf("%s", inputFile);
    
    printf("Enter name of output file: ");                                       //asks the user for the name of an output file and save it
    scanf("%s", outputFile);
    
    int shift = 0;                                                               //initialize shift to zero
    printf("Enter a Shift amount: ");                                            //asks the user for the shift amount and save it
    scanf("%d", &shift);
  
    printf("Press e for encrypt or d for decrypt: ");                            //asks the user to enter e or d and saves it as userAction
    scanf("%s", &userAction);
    
    while((userAction != 'e') && (userAction != 'd')){                           //runs if the userAction is not e or d
        printf("Must enter e for encrypt or d for decrypt!\n");                  //tells the users they must enter e or d
        printf("Press e for encrypt or d for decrypt: ");                        //asks the user to enter e or d and saves it as userAction
        scanf("%s", &userAction);
    }
    
    if(strcmp(inputFile,"msg1.txt")==0){                                         //runs if statement if the comparison of inputFile and msg1.txt are the same
        FILE* inFileOne = NULL;                                                  //sets a pointer inFileOne to NULL
        inFileOne = fopen("msg1.txt", "r");                                      //opens the file msg1.txt to read only
        if(inFileOne == NULL){                                                   //runs if inFileOne is equal NULL
            printf("ERROR: Could Not Open File One For Reading\n");              //prints an error saying the file could not be opened
            return -1;                                                           //returns -1
        }
        if(userAction == 'e'){                                                   //runs if the user entered e
            while (!feof(inFileOne)){                                            //runs until it has reached the end of inFileOne
                int numRead = fscanf(inFileOne, "%c", &letter);                  //sets numRead equal to what it reads inFileOne being either 1 or 0
                if ( numRead == 1 ){                                             //runs if numRead is equal to 1
                    array[i] = encryptLetter(letter,shift);                      //sets array equal to the function encryptLetter with the input of letter and shift
                    i++;                                                         //adds one to i
                }
            }
        }
        fclose(inFileOne);                                                       //closes the file inFileOne
    }
    
    if(strcmp(inputFile,"msg2.txt")==0){                                         //runs if statement if the comparison of inputFile and msg2.txt are the same                        
        FILE* inFileTwo = NULL;                                                  //sets a pointer inFileTwo to NULL
        inFileTwo = fopen("msg2.txt", "r");                                      //opens the file msg2.txt to read only
        if(inFileTwo == NULL){                                                   //runs if inFileTwo is equal to NULL
            printf("ERROR: Could Not Open File Two For Reading\n");              //prints an error saying the file could not be read
            return -1;                                                           //returns -1
        } 
         if(userAction == 'e'){                                                  //runs if the user entered e
            while (!feof(inFileTwo)){                                            //runs until it has reached the end of inFileTwo
                int numRead = fscanf(inFileTwo, "%c", &letter);                  //sets numRead equal to what it reads inFileTwo being either 1 or 0
                if ( numRead == 1 ){                                             //runs if numRead is equal to 1
                    array[i] = encryptLetter(letter,shift);                      //sets array equal to the function encryptLetter with the input letter and shift
                    i++;                                                         //adds one to i
                }
            }
        }
        fclose(inFileTwo);                                                       //closes the file inFileTwo
    }   
    
    
    if(strcmp(inputFile, "e1.txt")==0){                                          //runs if statement if the comparison of inputFile and e1.txt are the same
        FILE* inFileThree = NULL;                                                //sets a pointer inFileThree to NULL
        inFileThree = fopen("e1.txt", "r");                                      //opens the file e1.txt to read only
        if(inFileThree == NULL){                                                 //runs if inFileThree is equal to NULL
            printf("ERROR: Could Not Open File Three For Reading\n");            //prints an error saying the file could not be read
            return -1;                                                           //returns -1
        }
        if(userAction == 'd'){                                                   //runs if the user entered d
            while(!feof(inFileThree)){                                           //runs until it has reached the end of inFileThree
                int numRead = fscanf(inFileThree, "%c", &letter);                //sets numRead equal to what it reads inFileThree being either 1 or 0
                if(numRead == 1){                                                //runs if numRead is equal to 1
                    array[i] = decryptLetter(letter,shift);                      //sets array equal to the function decryptLetter with the input letter and shift
                    i++;                                                         //adds on to i
                }
            }
        }
        fclose(inFileThree);                                                     //closes the file inFileThree
    }
    
    if(strcmp(inputFile, "e2.txt")==0){                                          //runs if statement if the comparison of inputFile and e2.txt are the same
        FILE* inFileFour = NULL;                                                 //sets a pointer inFileFour to NULL
        inFileFour = fopen("e2.txt", "r");                                       //opens the file e2.txt to read only
        if(inFileFour == NULL){                                                  //run if inFileFour is equal to NULL
            printf("ERROR: Could Not Open File Four For Reading\n");             //prints an error saying the file could not be read
            return -1;                                                           //returns -1
        }
        if(userAction  == 'd'){                                                  //runs if the user entered d
            while(!feof(inFileFour)){                                            //runs until it has reached the end of inFileFour
                int numRead = fscanf(inFileFour, "%c", &letter);                 //sets numRead equal to what it reads inFileFour being either 1 or 0
                if(numRead == 1){                                                //runs if numRead is equal to 1
                    array[i] = decryptLetter(letter,shift);                      //sets array equal to the function decryptLetter with the input letter and shift
                    i++;                                                         //adds on to i
                }
            }
        }
        fclose(inFileFour);                                                      //closes the file inFileFour
    }
    
    if(strcmp(outputFile,"e1.txt")==0){                                          //runs if statement if the comparison of outputFile and e1.txt are the same
        FILE* outFileOne = NULL;                                                 //sets a pointer outFileOne to NULL
        outFileOne = fopen("e1.txt", "w");                                       //opens the file e1 to write only
        if(outFileOne == NULL){                                                  //runs if outFileOne is NULL
            printf("ERROR: Could Not Open File One For Writing\n");              //prints an error saying file could not be opened
            return -1;                                                           //returns -1
        }
        for(int i=0; array[i] != '\0'; i++){                                     //for loop that prints out all elements of array to the file e1.txt
            fprintf(outFileOne, "%c", array[i]);
        }
        printf("Encrypted File in e1.txt\n");                                    //tells the user the Encrypted File is in e1.txt
        fclose(outFileOne);                                                      //close the file outFileOne
    }  
    
    if(strcmp(outputFile,"e2.txt")==0){                                          //runs if statement if the comparison of outputFile and e2 are the same
        FILE* outFileTwo = NULL;                                                 //sets an pointer outFileTwo to NULL
        outFileTwo = fopen("e2.txt", "w");                                       //opens the file e2 to write only
        if(outFileTwo == NULL){                                                  //runs if outFileTwo is NULL
            printf("ERROR: Could Not Open File Two For Writing\n");              //prints an error saying the file could not be opened
            return -1;                                                           //returns -1
        }
        for(int i=0; array[i] != '\0'; i++){                                     //for loop that prints out all elements of array to the file e2.txt
            fprintf(outFileTwo, "%c", array[i]);
        }
        printf("Encrypted File in e2.txt\n");                                    //tells the user the Encrypted File is in e2.txt
        fclose(outFileTwo);                                                      //closes the file outFileTwo
    }  
    
    if(strcmp(outputFile, "d1.txt")==0){                                         //runs if statement if the comparison of outputFile and d1.txt are the same 
        FILE* outFileThree = NULL;                                               //sets a pointer outFileThree to NULL
        outFileThree = fopen("d1.txt", "w");                                     //opens the file d1.txt for write only
        if(outFileThree == NULL){                                                //runs if outFileThree is NULL
            printf("ERROR: Could Not Open File Three For Writing\n");            //prints an error saying the file could not be opened
            return -1;                                                           //returns -1
        }
        for(int i=0; array[i] != '\0'; i++){                                     //for loop that prints out all elements of array to the file d1.txt
            fprintf(outFileThree, "%c", array[i]);
        }
        printf("Decrypted File in d1.txt\n");                                    //tells user the Decrypted File is in d1.txt
        fclose(outFileThree);                                                    //closes the file outFileThree
    }
    
    if(strcmp(outputFile, "d2.txt")==0){                                         //runs if statement if the comparison of outputFile and d2.txt are the same
        FILE* outFileFour = NULL;                                                //sets a pointer outFileFour to NULL
        outFileFour = fopen("d2.txt", "w");                                      //opens the file d2.txt for write only
        if(outFileFour == NULL){                                                 //runs if outFileFour is NULL
            printf("ERROR: Could Not Open File Four For Writing\n");             //prints an error saying the file could not be opened
            return -1;                                                           //returns -1
        }
        for(int i=0; array[i] != '\0'; i++){                                     //for loop that prints out all elements of array to the file d2.txt
            fprintf(outFileFour, "%c", array[i]);
        }
        printf("Decrypted File in d2.txt\n");                                    //tells the user the Decrypted File is in d2.txt
        fclose(outFileFour);                                                     //closes the file outFileFour
    }
    return (EXIT_SUCCESS);
}

//encryptLetter function that changes the letter based on shift
char encryptLetter(char letter, int shift){
    int ascii = (int) letter;
    if (letter >= 'a' && letter <= 'z'){
        ascii = ascii + shift;
        if (ascii > 'z'){
            ascii = (ascii - 'z') + 'a' - 1;
        }
    }
    return ((char) ascii);
}

//decryptLetter function that changes the letter based on shift
char decryptLetter(char letter, int shift){
    int ascii = (int) letter;
    if(letter >= 'a' && letter <= 'z'){
        ascii = ascii - shift;
        if (ascii < 'a'){
            ascii = 'z' - ('a' - ascii -1);
        }
    }
    return ((char) ascii);
}
