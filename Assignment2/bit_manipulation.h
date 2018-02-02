
/*

File bit_manipulation.h

Purpose:header file of functions prototypes

*/

/************************************************************************/

// INCLUDE FILES


#include "stdio.h"
#include "stdlib.h"
#include "assert.h"


/************************************************************************/
// FUNCTION PROTOTYPES

int isCharBitSet(char c, int bitNum);
void setCharBit(int bitNum, char *c);
int isShortBitSet(short num, int bitNum);
void setShortBit(int bitNum, short *num);
void flipBitShort(int bitNum, short *num);
int countBits(short num);

