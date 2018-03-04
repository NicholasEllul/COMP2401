// file is populateRecords.c 
/* 
Purpose: populate the records of the patient and the employee

The file consists of several functions for ppopulating a person array and thus populating patient records and employee records
in the array.

The records are populated using random number generator. No special seed point is given (using the default seed of 1).


Revisions:
15/2/2018 - Doron Nussbaum file created
 
 */


/***********************************************************/
//INCLUDES 

#include "stdio.h"
#include "stdlib.h"
 #include "string.h"
#include "populateRecords.h"
 

/*********************************************************/
//FUNCTION PROTOTYPES

void populateEmployee(EmployeeRec *employee);
void populatePatient(PatientRec *patient);


/**************************************************************/
/* populates an employees

input

emp - an  employee record

output
emp - populated employee


*/


/*****************************************************************/
// DEFINES

#define MAX_YEARS_SERVICE 63
#define MAX_SALARY 300000


/*****************************************************************/


void populateEmployee(EmployeeRec *emp)
{

	emp->salary = (rand() % MAX_SALARY) * 1.34f ;
	emp->yearsService = rand() % MAX_YEARS_SERVICE+1;
	emp->department = rand() % MAX_DEPARTMENTS + 1;
	emp->position = rand() % MAX_POSITIONS;
}


/**************************************************************/
/* populate a patient record 

input
patient - a student record

output
patient - a student record


*/

#define MAX_DAILY_COST 50
#define MAX_DAYS_IN_HOSPITAL 30




void populatePatient(PatientRec *p)
{

	p->department = rand() % MAX_DEPARTMENTS + 1;
	p->dailyCost = rand() % MAX_DAILY_COST+5;
	p->severity = rand() % NUM_SEVERITIES;
	p->numDaysInHospital = rand() % MAX_DAYS_IN_HOSPITAL+1;

}







/**************************************************************/
/* populate an employee record

input
person - an array of persons
numPersons - number of person in the array

output
emp - array of employees

assumption:
numPersons is <= the size of the array person
*/
#define NUM_NAMES 7
void populateRecords(PersonRec *person, int numPersons)
{
	int i = 0;
	int j;
	static int initRandom = 0;

	char *fn[NUM_NAMES] = { "John", "Jane", "David", "Dina", "Justin","Jennifer", "Don" };
	char *sn[NUM_NAMES] = { "Smith", "Johnson", "Mart", "Carp", "Farmer","Ouster","Door" };

	if (!initRandom) {
		initRandom++;

	}

	while (i < numPersons) {
		j = rand() % NUM_NAMES;
		person->firstName[NAME_SIZE - 1] = '\0';
		strncpy(person->firstName, fn[j], NAME_SIZE - 1);
		j = rand() % NUM_NAMES;
		person->familyName[NAME_SIZE - 1] = '\0';
		strncpy(person->familyName, sn[j], sizeof(person->familyName) - 1);
		if (rand() % 2) {
			person->emplyeeOrPatient = PATIENT_TYPE;
			populatePatient(&person->patient);
		} else {
			populateEmployee(&person->emp);
			person->emplyeeOrPatient = EMPLOYEE_TYPE;
		}
		person++;
		i++;
	}
}




