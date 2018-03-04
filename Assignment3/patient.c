

#include <stdlib.h>
#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/

void printPatient(PersonRec person) {
    PatientRec patient = person.patient;

    // Generate string to hold the employees fullname
    char fullname[33]; // Buffer string to hold expected input (33 comes from the restriction provided in the assignment)
    sprintf(fullname,"%s %s", person.firstName, person.familyName);

    // Calculate the salary to date since the employee started
    int totalCost = patient.dailyCost * patient.numDaysInHospital;

    // Print with formatting
    printf("%-33s dept:%2u days in hospital:%3d severity:%2d daily cost:%3d total cost:%5d\n",
           fullname, patient.department,patient.numDaysInHospital, patient.severity, patient.dailyCost,totalCost);

}

// Takes in a list of people and the count of them. Then calls the print function
// on those which are patients
void printPatients(PersonRec *person, int numRecords) {

    printf("\nPatient List\n");
    for (int i = 0; i < numRecords; i++, person++) {
        if (person->emplyeeOrPatient == PATIENT_TYPE) {
            printPatient(*person);
        }
    }
    printf("-----------------------\n");
}

// Given a record of people, it prints stats about all the patients
void printPatientOverallSummary (PersonRec *person,int numRecords){

    int totalPatients = 0;
    float totalDailyCostTotals = 0;
    float totalCostsToDate = 0;

    // Loop though the records and tally up patient data
    for(int j = 0; j < numRecords; j++,person++){
        if(person ->emplyeeOrPatient == PATIENT_TYPE){
            totalPatients++;
            totalDailyCostTotals += person->patient.dailyCost;
            totalCostsToDate += person->patient.dailyCost * person->patient.numDaysInHospital;
        }
    }

    float averageCostPerPatent = 0;
    if(totalPatients > 0) averageCostPerPatent = totalDailyCostTotals/totalPatients;

    printf("Total number of patients:%3d total cost to-date:%10.2f daily cost:%7.2f average cost per patient to-date:%8.2f\n",
            totalPatients,totalCostsToDate, totalDailyCostTotals,averageCostPerPatent);
}

// Given a record of people, it prints stats about the patient data by department
void printPatientDepartmentalSummary(PersonRec *person, int numRecords){

        PersonRec *startPosition = person;
        for(int deptNum = 1; deptNum <= MAX_DEPARTMENTS; deptNum++){
            // Variables used to subtotal the data for each position

            int numPatients=0;
            float dailyCostTotal=0;
            float costToDate=0;

            person = startPosition;
            for(int j = 0; j < numRecords; j++,person++){
                if(person ->emplyeeOrPatient == PATIENT_TYPE && person->patient.department == deptNum){
                    numPatients++;
                    dailyCostTotal += person->patient.dailyCost;
                    costToDate += person->patient.dailyCost * person->patient.numDaysInHospital;
                }
            }

            float avgDailyCostPerPatient = 0.0f;
            if(numPatients > 0) avgDailyCostPerPatient = dailyCostTotal/numPatients;
            printf("Department [%d] - patients: %3d cost to-date:%7.2f daily cost: %7.2f, average daily cost per patient:%7.2f\n",
            deptNum,numPatients,costToDate,dailyCostTotal,avgDailyCostPerPatient);
        }
}

/********************************************************************/
// Takes in a record of people and the count then prints out the overall patient data,
// then data by department
void printPatientSummary(PersonRec *person, int numRecords)
{
    printf("Patient Summary\n");
    printPatientOverallSummary(person,numRecords);

    printf("Summary by Department\n");
    printPatientDepartmentalSummary(person,numRecords);
}


/********************************************************************/
// Takes in a record of people, the count, and a family name to search for
// It then prints data about that patient who's family name is the passed in family name
void searchPatient(PersonRec *person, int numRecords, char *familyName ) {

    // add code
    printf("\nPatient(s) with family name: %s\n",familyName);
    for (int i = 0; i < numRecords; i++, person++) {
        if (strcmp(person->familyName,familyName) == 0 && person->emplyeeOrPatient == PATIENT_TYPE) {
            printPatient(*person);
        }
    }
    printf("-----------------------\n");

}
