//
// Created by Nicholas Ellul on 2018-04-11.
//
//
// Created by Nicholas Ellul on 2018-04-10.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/wait.h>
#include "unistd.h"


int morph(char* num) {
    // Prepare arguments to morph into isPrime
    char *isPrimeFile = "./isPrime";
    char *parameters[3];
    parameters[0] = "isPrime";
    parameters[1] = num;
    parameters[2] = NULL;

    int primeCode = execv(isPrimeFile, parameters);
    // Code shouldn't reach here
    printf("Something went wrong. Return code %d", primeCode);
    return -1;
}


int spawnChildren(unsigned int numbers[], int numberCount) {
    pid_t childIds[numberCount];
    int childResponses[numberCount];

    // Call a child process for each number
    for(int i = 0; i < numberCount; i++){
        childIds[i] = fork();
        if(childIds[i] == 0){
            char numberAsString[100];
            sprintf(numberAsString,"%u",numbers[i]);
            morph(numberAsString);
        }
    }

    // Wait for children to finish and record their return codess
    for(int i = 0; i < numberCount; i++){
        int status = 0;
        int childId = waitpid(-1, &status, 0);
        if(WIFSIGNALED(status)) return -1;

        for(int i = 0; i < numberCount; i ++){
            if(childId == childIds[i]) childResponses[i] = WEXITSTATUS(status);
        }
    }

    // Print results if prime or not
    for (int i=0; i<numberCount; i++) {

        if (childResponses[i] == 1) {
            printf("%u is a prime number\n", numbers[i]);
        }
        else if (childResponses[i] == 0) {
            printf("%u is not a prime number\n", numbers[i]);
        }
    }
    return 1;
}


size_t getFileSize(FILE * filePointer){

    long posInFile = ftell(filePointer);
    fseek(filePointer, 0L, SEEK_END);

    long size = ftell(filePointer);

    // reset position in file
    fseek(filePointer,posInFile,SEEK_SET);
    return size / sizeof(int);
}

int main(int argc, char* argv[]) {
    if(argc != 2){
        printf("Use the program by typing: singlePrime NAME_OF_FILE\n");
        return(2);
    }
    else{
        FILE *fid = NULL;
        fid = fopen(argv[1], "rb");
        if (fid == NULL) {

            printf("The file %s does not exist\n", argv[1]);
            return(3);

        } else {
            size_t numberCount = getFileSize(fid);

            unsigned int * numbers = NULL;
            numbers = (unsigned int*)malloc(numberCount);
            if(numbers == NULL)
                return -1;
            size_t rc = fread(numbers, sizeof(unsigned int), numberCount, fid);
            if(rc == 0) return -1;
            fclose(fid);
            spawnChildren(numbers,(int)numberCount);
            free(numbers);
        }
    }
}