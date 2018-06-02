// FILE IS main.c
/*
Description:

This is an exmaple of a test program that you should write to test your code.  
The testing is not complete because it checks only a subset of the required functionality
and not all aspects of it. 

This code will not be used by the TAs to test your code.


Revisions:
Doron Nussbaum 2018
Copyright Doron Nussbaum 2018

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"
//#include "bubble_sort.h"

#define CONTINUE {printf("hit <cr> to continue \n"); getchar();}

void populatePerson(char *firstName, char *familyName, int *id);


int main(int argc, char* argv[])
{
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
	unsigned int id;
	PersonalInfo *empHead = NULL;
	PersonalInfo *p = NULL, *q = NULL;
	int i;
    int rc = 0;
	
	for (i = 0; i < 2; i++) {
	// add code for testing
		printf("%d ",i+1);
		populatePerson(firstName, familyName, &id);
		insertToList(&empHead, id, firstName, familyName);
	}
    PersonalInfo * x = searchByName(empHead,firstName);
    printList(empHead);
    printf("LOOL \n %s\n",firstName);
    deleteNodeByName(&empHead, firstName, familyName, &id);
    printf("FUCK %0x\n",empHead);
    x = NULL;
    deleteList(&empHead);
    printf("FUCK %0x\n",empHead);
    insertAfter(empHead,id,firstName,familyName);
    printList(empHead);

/*
	printList(empHead);

    printf("test SearchById \n");
	q = p = searchById(empHead, 39);
    if(p == NULL) { 
        printf("Record Not Found \n");
    } else {
        printNode(p);
    }
    CONTINUE;
	if (p != NULL) {
	    for (i = 0; i < 4; i++) {
		    populatePerson(firstName, familyName, &id);
		    p = insertAfter(p, id, firstName, familyName);
	    }
    }
	printList(empHead);

    // test delete after
    
	rc = deleteAfter(q, &id, firstName, familyName);
    printf("deleteAfter rc = %d \n",rc);
	printList(empHead);
    CONTINUE;


	p = searchById(empHead, 39);
	if (p != NULL) {
		printf("\n found name to delete \n");
		printNode(p);
		strncpy(firstName, p->firstName, NAME_LENGTH);
		deleteNodeByName(&empHead, firstName, familyName, &id);
	}

	

	//crbubbleSort(&empHead);

	printf("\n\n sorted list \n\n");
	printList(empHead);

//	getchar();

	printf("\n\n remove duplicates \n\n");
	removeDuplicates(empHead);
	printList(empHead);
    deleteList(&empHead);
//	getchar();
*/
	return 0;
}


	

/***************************************************************************/
/* purpose: the function populate the personal info

input/output
struct personalInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(char *firstName, char *familyName, int *id)
{
	static int initRand = 0;
	int j;
	char *first[5] = { "John", "Don", "Edna", "Bev", "Miya" };
	char *family[5] = { "Broker", "Smith", "Tower", "Little", "Bronson" };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096  
	*id = rand() % 150;

}






