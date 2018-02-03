
/*

File bit_manipulation.c

Purpose :
contains helper functions for manipulating bits


Revisions:
a. Initial code - Doron Nussbaum

* /

/************************************************************************/

// INCLUDE FILES

#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES



/************************************************************************/
// FUNCTION PROTOTYPES



/***************************************************/

//example of a testing function for the functions in the file 
// it should be used only when adding code to the functions
// to use it: 
// 1. change the statment below (preprocessing directive) to #if 1.
// This "tells" the compiler to include the code between #if 1 and #endif.
// 2. compile the file
// 3. exectute the file
// 4. if needed add more test calls
// 5. when you are satified with the results change the statement #if 1 to #if 0 to exclude the code from compilation. 
#if 0

int main(int argc, char *argv[])

{
	int rc = 0;		// return code


	short test = 0;
	short modified;
	int bitNum;		// bit number to be used
	
	
	test = 0;
	bitNum = 2;
	modified = test;
	flipBitShort(bitNum, &modified);
	printf("flipBitShort: test=%d, flipping bit #=%d, answer should be=%d, modified test=%d\n", test, bitNum, 4, modified);

	rc = isShortBitSet(modified, 3);
	printf("isShortBitSet: bit 3 in %d should not be set.  Functions returned %d \n", modified, rc);

	rc = isShortBitSet(modified, 2);
	printf("isShortBitSet: bit 2 in %d should  be set.  Function returned %d \n", modified, rc);

    clearShortBit(2,&modified);

    rc = isShortBitSet(2,modified);
    printf("isShortBitSet: bit 2 in %d should not  be set.  Function returned %d \n", modified, rc);

	test = 9;
	rc = countBits(test);
	printf("countBits: test = %d number of bits set to 1 should be 2.  Function returend: %d \n", test, rc);


   getchar();
   
	return(0);
}


#endif

/*************************************************************************************/
/* purpose: checks if a bit at position bitNum is set  to 1

input:
c - the character to be checked
bitNum - the bit number to be checked (expected range 0-7)

return:
1 if the bit is set to 1
0 if the bit is not set to 1 (bit is 0)

*/

int isCharBitSet(char c, int bitNum) {
    if(bitNum > 7 || bitNum < 0) return -1;
    return (c & (1<<bitNum))>>bitNum;
}




/*************************************************************************************/

/* purpose: checks if a bit at position bitNum is set  to 1

input: 
num - the number to be checked
bitNum - the bit number to be checked 

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

return:
none
*/
int isShortBitSet(short num, int bitNum)
{
    if(bitNum > 15 || bitNum < 0) return -1;
    return (num & (1<<bitNum))>>bitNum;
}

/*************************************************************************************/
/* purpose: sets bit bitNum to 1 in *num to 1  

input:
num - the address of the short integer
bitNum - the bit number to be checked

Output:
*num - the modified short

return:
none

*/

void setShortBit(int bitNum, short* num) {

    *num = (*num | (1 << bitNum));

}
/////COMMENTS
void clearShortBit(int bitNum, short* num) {

    *num = (*num & ~(1<<bitNum));

}

/*************************************************************************************/


/* purpose: sets bit bitNum in *c to 1

input:
c - address of character 
bitNum - the bit number to be checked

output:
*c - the modified character
return:
none

*/
void setCharBit(int bitNum, char *c) {

    *c = (*c | (1 << bitNum));
}
////COMMENTS
/*void clearCharBit(int bitNum, char *c) {

    *c = (*c & ~(1<<bitNum));
}*/
/*************************************************************************************/


/*  count the number of bits in a short

input: 
num - a short interger

output:
none

return:
the numer of bits that are set to 1 in num



*/
int countBits(short num) {

    // add code
    int bitCount = 0;
    for(int i = 0; i < 16; i++){
        if(isShortBitSet(num,i) == 1){
            bitCount++;
        }
    }
    return bitCount;
}






/*************************************************************************************/

/* purpose:
flips bit i in num (set bit i to 1 if the bit is 0 or set bit i to 0 if the bit is 1)

input:
bitNum - the bit number to be flipped
num - address of the short integer

output:
*num - the modified short integer

return:
none

*/
void flipBitShort(int bitNum, short *num)

{
    *num = (*num^(1<<bitNum));
    // add code
}


