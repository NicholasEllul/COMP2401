// file is patient.h

// include files 
#include "struct.h"

/******************************************************/
// function prototypes

void printPatients(PersonRec *person, int numRecords);
void printPatientSummary(PersonRec *person, int numRecords);
void searchPatient(PersonRec *person, int numRecords, char *familyName);
void printPatientOverallSummary (PersonRec *person,int numRecords);
void printPatientDepartmentalSummary(PersonRec *person, int numRecords);


