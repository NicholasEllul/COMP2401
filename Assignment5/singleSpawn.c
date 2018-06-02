
//
// Created by Nicholas Ellul on 2018-04-10.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <sys/wait.h>

int morph(char* num) {
    // Set up morph call and attributes
    char *isPrimeFile = "./isPrime";
    char *parameters[3];
    parameters[0] = "isPrime";
    parameters[1] = num;
    parameters[2] = NULL;

    // Fork into child and call is prime
    int pid = fork();
    if (pid == 0) {
        // child process instructions
        int primeCode = execv(isPrimeFile, parameters);
        printf("Something went wrong. Return code %d", primeCode);
        return -1;
    }
    // parent process instructions
    int status;
    wait(&status);
    // If it exited normally, decide if its prime or not
    if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) == 1) {
            printf("\n The number %s IS prime", num);
        }
        if (WEXITSTATUS(status) == 0) {
            printf("\n The number %s is NOT prime", num);
        }
    } else {
        printf("\nChild terminated unexpectedly with value of %d", WEXITSTATUS(status));
    }
    return WEXITSTATUS(status);

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
            unsigned int number;

            // Read the first binary number
            int rc = fread(&number,sizeof(unsigned int),1,fid);
            if(rc == 0) return 1;

            // Translate the number to a strings
            char numberBuffer[20];
            sprintf(numberBuffer,"%u",number);
            fclose(fid);
            // morph this program into the isPrime program
            return morph(numberBuffer);
        }
    }
}

