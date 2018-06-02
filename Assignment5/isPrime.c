/* 
File is isPrime.c

Purpose:
a program that checks if a given number is a prime number

input:
number - a positive int  entered via the command line parameters.  For example isPrime 1234

output:
0 - if the input number is not a prime number
1 - if the input number is a prime number
2 - if the command line parameter is not correct 

Assumption:
the program does not check if the number is a positive integer


Notice:
Code can be used only for the assignment.  Other usages are not allowed

Copyright 2018 Doron Nussbaum
*/ 

/**************************************************************/
// INCLUDE FILES
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>


/*************************************************************/
// PROTYPES
//
int isPrime(unsigned long number);


/*************************************************************/


int main(int argc, char *argv[])

{
	int i;
	unsigned long number;
	if (argc < 2) return(2);
	else number = strtoul(argv[1],NULL, 0);
	if (isPrime(number)) {
		exit(1);
	}
	exit(0);
}


/*************************************************************/
/*
Purpose: check if the input number is a prime number
input:
number - the number to be checked

return:
0 - if the number is not a prime number
1 - if the number is a prime number
*/ 

int isPrime(unsigned long number)
{
	unsigned long i;
	unsigned long root = 65536;

	// check prime by attempting to divide the number by all integer small then root(number)
	// without a remainder
	for(i = 2; i <= root && i*i <= number; i++) {
		usleep(100);
		if (number % i == 0) {
			return(0);
		}
	}
	return(1);
}
