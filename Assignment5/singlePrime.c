//
// Created by Nicholas Ellul on 2018-04-10.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"



int morph(char* num){
    // Prepare arguments to morph into isPrime
    char * isPrimeFile = "./isPrime";
    char * parameters[3];
    parameters[0] = "isPrime";
    parameters[1] = num;
    parameters[2] = NULL;

    int primeCode = execv(isPrimeFile,parameters);

    // Code shouldn't reach here
    printf("Something went wrong. Return code %d", primeCode);
    return primeCode;
}

int main(int argc, char* argv[]) {
    if(argc != 2){
        printf("Use the program by typing: singlePrime NAME_OF_FILE\n");
        return(2);
    }
    else{
        // Open the bin file
        FILE *fid = NULL;
        fid = fopen(argv[1], "rb");
        if (fid == NULL) {
            printf("The file %s does not exist\n", argv[1]);
            return(3);

        } else {
            unsigned int number;
            // Read the first number
            unsigned int rc = fread(&number,sizeof(unsigned int),1,fid);
            if(rc == 0) return 1;

            // Convert the number to string and morph into isPrime
            char numberBuffer[20];
            sprintf(numberBuffer,"%u",number);
            fclose(fid);
            morph(numberBuffer);
            return 0;
        }
    }
}

