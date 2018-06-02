
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2018
Nicholas Ellul 2018
 
 
 
 
 Copyright 2018 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName) {

	// Handle case where head is null
	if(*head == NULL){
		*head = createNode(id,firstName,familyName);
		if(*head == NULL){
			printf("Memory allocation failed. Something went wrong.");
			return NULL;
		}
	}else{ // Handle all other cases
		PersonalInfo* newNode = NULL;
               newNode = createNode(id,firstName,familyName);
		if(*head == NULL){
			printf("Memory allocation failed. Something went wrong.");
			return NULL;
		}else{
			newNode->next = *head;
			*head= newNode;
		}
	}

	return *head;
}

// This helper function dynamically allocates space for a new node and returns it to the caller
PersonalInfo* createNode(unsigned int id, char *firstName, char *familyName){


	// Set up pointer
	PersonalInfo* newNode = NULL;
    newNode = (PersonalInfo*) malloc(sizeof(PersonalInfo));

	// Truncate the name if its too long
    if(strlen(firstName) > NAME_LENGTH - 1){
        truncate(&firstName,firstName,NAME_LENGTH-1);
    }

    if(strlen(familyName) > NAME_LENGTH - 1){
	    truncate(&familyName,familyName,NAME_LENGTH-1);
    }
	// Add the data to the node
	strcpy(newNode->familyName, familyName);
	strcpy(newNode->firstName, firstName);
	newNode->id=id;
	newNode->next = NULL;
	return newNode;
}

// Takes in an output string by reference, an in put string by value, and the max number of characters that the output string can have
// Returns 0 if failed, or 1 if successful
void truncate(char**outputString,char*inputString,int numChars){
    for(int i = 0; i < numChars-1 ;i++){
        (*outputString)[i] = inputString[i];
    }
    (*outputString)[15] = '\0';
}
/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
    if(node == NULL) return NULL;
	PersonalInfo* newNode = NULL;

	// Allocate memory
    newNode = createNode(id,firstName,familyName);

	if(newNode == NULL) {
		printf("Memory Allocation failed. Insert after");
		return NULL;
	}
	// Update references
    newNode->next = node->next;
	node->next=newNode;
	return newNode;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{

	// Handle case where head is null
    if(*head == NULL) {
        *head = createNode(id,firstName,familyName);
        if(*head == NULL){
            printf("Memory Allocation Failed");
            return NULL;
        }
        return *head;
    }

	// Loop until iterator is the last node
	PersonalInfo *iterator = NULL;
	iterator = *head;
    while(iterator->next != NULL){
		iterator = iterator->next;
	}

	// Add the new node to the end
	PersonalInfo *newNode = NULL;
    newNode = createNode(id,firstName,familyName);

	if(newNode == NULL){
		printf("Memory Allocation Failed");
		return NULL;
	}
	iterator->next = newNode;
	return newNode;
}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	// Loop until were at the end of the list or we find a matching first name
    while(head != NULL && strcmp(head->firstName,firstName) != 0){
		head = head->next;
	}
	return head;
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	// Loop until were at the end of the list or we find a matching id
	while(head != NULL && head->id != id ){
		head = head->next;
	}
	return head;
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
 
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName) {

	if(*head == NULL) return 1;

    // Loop until you find the node before the node to remove
    copyData(*head,id,firstName,familyName);
    // Adjust Links
    PersonalInfo *oldHead = NULL;
    oldHead =  *head;
	*head = oldHead->next;

    // Free memory
	free(oldHead);
	return 0;
}

// Helper function that copies data from the node to the pointers
void copyData(PersonalInfo *node, unsigned int *id, char *firstName, char *familyName){
    // Copy data over
    unsigned int cpyId = node->id;
    strcpy(firstName,node->firstName);
    strcpy(familyName,node->familyName);
    *id = cpyId;
}
/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName) {

	// Handle case where head is null
    if (*head == NULL) return 1;
	// If the next node is null, remove the head
    if ((*head)->next == NULL) {
        copyData(*head, id, firstName, familyName);
        free(*head);
        *head=NULL;
        return 0;
    }

	// Otherwise loop until the last node is found but keep track of the previous
    PersonalInfo *iterator = NULL;
    iterator = *head;
    PersonalInfo *prev = NULL;
        do {
            prev = iterator;
            iterator = iterator->next;
        } while (iterator->next != NULL);

	// Set previous next to null then delete that last node
    prev->next = NULL;
    copyData(iterator, id, firstName, familyName);
    free(iterator);
    return 0;
}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)
{
	// Should delete if theres < 2 nodes in the list
    if(node == NULL || node->next == NULL) return 1;

    PersonalInfo* nodeToRemove = NULL;
	nodeToRemove = node->next;
	copyData(nodeToRemove,id,firstName,familyName);
	node->next = nodeToRemove->next;
	free(nodeToRemove);
	return 0;
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of deleted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName, char *familyName, unsigned int *id)
{
    if(head == NULL) return 1;

	PersonalInfo *iterator = NULL;
	PersonalInfo *prev = NULL;
	iterator = *head;

	// Loop until node is found or we get to the end of the list
	while(iterator != NULL && strcmp(iterator->firstName,firstName) != 0){
        prev = iterator;
		iterator = iterator->next;
	}
	// IF its null, then theres nothing to delete
    if(iterator == NULL) return 1;

    // If its the head and only one in the list handle that
    if(iterator == *head && (*head)->next == NULL && strcmp(iterator->firstName,firstName) == 0){
        *head = NULL;
        free(iterator);
        return 0;
    }
	// Otherwise delete
    copyData(iterator,id,firstName,familyName);
    if(prev != NULL){
        prev->next = iterator->next;
    }else{
        *head = iterator->next;
    }
    prev = NULL;
    free(iterator);
    return 0;
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	// Loop though the list freeing all memory
	while(*head != NULL){
		PersonalInfo *nodeToDelete = NULL;
		nodeToDelete = *head;
        *head = (*head)->next;
		free(nodeToDelete);
	}
	*head = NULL;

}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);
}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	// Loop though and print list
    while(head != NULL){
        printNode(head);
        head = head->next;
    }

}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	// Loop though nodes incrementing counter
	int count = 0;
	while(head != NULL){
		count += 1;
		head = head->next;
	}
	return count;

}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	// Loop though list incrementing counter only when first name matches
	int count = 0;
	while(head != NULL){
		if(strcmp(head->firstName,firstName) == 0){
			count += 1;
		}
		head = head->next;
	}
	return count;

}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/


void removeDuplicates(PersonalInfo *head) {

	if(head == NULL) return;

	// Cache the first name in the list.
	char name[NAME_LENGTH];
	strcpy(name,head->firstName);

    PersonalInfo *prev = NULL;
	prev = head;
    head = head->next;

	// Start with the second node and start lopping though the whole list
	while(head != NULL){

		// If this node has the same name as the already seen name, then delete it.
		if(strcmp(head->firstName,name) == 0){
			PersonalInfo* nodeToDelete = head;
            prev->next = head->next;
			head = prev;
			free(nodeToDelete);
		}
		// Update the last seen name to head (which will be the node before the one that just got removed)
		strcpy(name,head->firstName);
        prev = head;
		head = head->next;
	}
}

