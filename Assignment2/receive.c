
/*

File receive.c


Purpose: simulate the receiveing end of a message over the network.  

The program converts a message encodded as an array of short integers into characters.
The input message uses 1-bit error correction code.
As part of the simulation, the program also corrects any 1-bit errors in the receiving message.


Revision:
a. Initial code - Doron Nussbaum
b. Implemented Short2Char and CorrectCode functions - Nicholas Ellul - 101064168

*/


/************************************************************************/

// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES



#define XSTR(A) STR(A)
#define STR(A) #A
#define MAX_INPUT_LENGTH 8192
#define MAX_MSG_LENGTH 2048
#define P1_MASK 0xaa8   // 0b0101010101000
#define P2_MASK 0xcc8	// 0b0110011001000
#define P4_MASK 0x10e0	// 0b1000011100000
#define P8_MASK 0x1e00  // 0b1111000000000


/************************************************************************/
// FUNCTION PROTOTYPES


void short2Char(short encodedChar, char *c);
void correctCode(short *num);
void readEncodedMessage(short *buf, int len, int *numRead);




/**************************************************************************/

int main(int argc, char *argv[])

{
	int rc = 0;		// return code

	char s[MAX_MSG_LENGTH] = { '\0' };  // message
	short encodedMsg[MAX_MSG_LENGTH];
	int numRead = 0;  // number of characters in the message
	int i;

	// read the message
	printf("Enter the transmitted message: ");
	readEncodedMessage(encodedMsg, MAX_MSG_LENGTH, &numRead);



	// print the corrected message
	printf("\n\n Transmitted Message:\n");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
    }
    printf("\n");

    // correct the message
	for (i = 0; i < numRead; i++) {
		correctCode(&encodedMsg[i]);
	}



	// print the corrected message
	printf("\n\n Corrected Transmitted Message:\n");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
	}
	printf("\n");

	return(0);
}


/***********************************************************************************/
/* reads a message from the user

input
len - maximum length of mesage that should be read

output
receivedMsg - contains the message
numRead - the number of characters in the message

Asumption: 
function does not do any error checking of the input.  It expects to receive 
a sequence of positive short integers.

*/


void readEncodedMessage(short *receivedMsg, int len, int *numRead)
{
	int i;
	int rc;
	char s[MAX_INPUT_LENGTH+1];
	char *token = NULL;
	*numRead = 0;

	s[MAX_INPUT_LENGTH] = '\0';
	scanf("%"XSTR(MAX_INPUT_LENGTH)"[^\n]s", s);
	token = strtok(s, " ");

	for (i = 0; token != NULL  &&  i < len;token = strtok(NULL, " "), i++) {
		rc = sscanf(token, "%hd", &receivedMsg[i]);
	}

	*numRead = i; // set the number of read integers

    // empty the input buffer
    for( ; getchar() != '\n'; );


}




/*************************************************************************/
/* assign bits 3,5,6,7,9,10,11,12 of a integer to bits 0-7 of a char

input
encodedNum - a short integer 

output
*c - the modified char that is embedded in encodedNum

return:
none

comment:
this is the "inverse" of the function char2Short in the transmit program

*/

void short2Char(short encodedNum, char *c) {
	short mask = 0x0001;
	int i;
	int bitSet;

	*c = 0;		// initialize *c

    // Loop though bits of the short, and extract the bits which correspond to
    // the bits of the char we want to represent
    // We only loop though bit index 3 to 13 because we have no need to consider
    // parity bits or any other unused bits
	for (i = 3; i < 13; i++) {

        bitSet = isShortBitSet(encodedNum,i);
        if (!bitSet) continue;

        switch(i) {
		   case 3:
			   setCharBit(0, c);
			   break;
		   case 5:
			   setCharBit(1, c);
			   break;
		   case 6:
			   setCharBit(2, c);
			   break;
		   case 7:
			   setCharBit(3, c);
			   break;
		   case 9:
			   setCharBit(4, c);
			   break;
		   case 10:
			   setCharBit(5, c);
			   break;
		   case 11:
			   setCharBit(6, c);
			   break;
		   case 12:
			   setCharBit(7, c);
			   break;
		   default:
			   break;
	   }
	}
}


/*************************************************************************************/


/* purpose:
performs error corrections, if needed on the short integer

The function checks the parity bits for error and see if there is a discrepancy between
the transmitted parity bits and the computed parity bits for the received number.  
If there is a discrepancy then it finds the bit number that was flipped.

If there is an error then it fixes it.

input
num - the address of the short number 

output:
*num - the modified number
*/


void correctCode(short *num) {
	int sum;
	int bitNumber = 0; //  bit number with the error bit

	// Check each parity bit for any discrepancies.
	// If the sum of the parity bits and its dependencies
	// are an odd number, add 2^n to the bit num where n is the index of the parity bit.
	sum = countBits(*num & P1_MASK) + isShortBitSet(*num,1);
	if(sum % 2 == 1)  bitNumber+= 1;

	sum = countBits(*num & P2_MASK) + isShortBitSet(*num,2);
	if(sum % 2 == 1)  bitNumber+= 2;

	sum = countBits(*num & P4_MASK) + isShortBitSet(*num,4);
	if(sum % 2 == 1)  bitNumber+= 4;

	sum = countBits(*num & P8_MASK) + isShortBitSet(*num,8);
	if(sum % 2 == 1)  bitNumber+= 8;

	// If the parity bits showed a discrepancy, flip that bit.
	// a bitNumber of 0 mean all the bits were correct.
    printf("%d",bitNumber);
	if(bitNumber != 0) flipBitShort(bitNumber,num);
}

