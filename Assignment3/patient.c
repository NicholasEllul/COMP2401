

#include <stdlib.h>
#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person) {
    PatientRec patient = person.patient;

    // Generate string to hold the employees fullname
    //int lengthOfString = strlen(person.firstName) + strlen(person.familyName) + 2;
    char fullname[33];
    sprintf(fullname,"%s %s", person.firstName, person.familyName);

    // Calculate the salary to date since the employee started
    int totalCost = patient.dailyCost * patient.numDaysInHospital;

    // Print with formatting
    printf("%-33s dept:%2u days in hospital:%3d severity:%2d daily cost:%3d total cost:%5d\n",
           fullname, patient.department,patient.numDaysInHospital, patient.severity, patient.dailyCost,totalCost);

}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords) {

    printf("\nPatient List\n");
    printf("-----------------------\n");
    for (int i = 0; i < numRecords; i++, person++) {
        if (person->emplyeeOrPatient == PATIENT_TYPE) {
            printPatient(*person);
        }
    }
    printf("-----------------------\n");
}

void printPatientOverallSummary (PersonRec *person,int numRecords){
    PersonRec *startPosition = person;

    int totalPatients = 0;
    float totalDailyCostTotals = 0;
    float totalCostsToDate = 0;

    for(int deptNum = 1; deptNum <= 6; deptNum++){
        // Variables used to subtotal the data for each position
        person = startPosition;
        for(int j = 0; j < numRecords; j++,person++){
            if(person ->emplyeeOrPatient == PATIENT_TYPE && person->patient.department == deptNum){
                totalPatients++;
                totalDailyCostTotals += person->patient.dailyCost;
                totalCostsToDate += person->patient.dailyCost * person->patient.numDaysInHospital;
            }
        }
    }
    float averageCostPerPatent = 0;
    if(totalPatients > 0) averageCostPerPatent = totalDailyCostTotals/totalPatients;

    printf("Total number of patients:%3d total cost to-date:%10.2f daily cost:%7.2f average cost per patient to-date:%8.2f\n",
            totalPatients,totalCostsToDate, totalDailyCostTotals,averageCostPerPatent);
}

void printPatientDepartmentalSummary(PersonRec *person, int numRecords){

        PersonRec *startPosition = person;
        for(int deptNum = 1; deptNum <= 6; deptNum++){
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
void printPatientSummary(PersonRec *person, int numRecords)
{
    printf("Patient Summary\n");
    printPatientOverallSummary(person,numRecords);

    printf("Summary by Department\n");
    printPatientDepartmentalSummary(person,numRecords);
}


/********************************************************************/
void searchPatient(PersonRec *person, int numRecords, char *familyName ) {

    // add code
    printf("\nPatient(s) with family name: %s\n",familyName);
    printf("-----------------------\n");
    for (int i = 0; i < numRecords; i++, person++) {
        if (strcmp(person->familyName,familyName) == 0 && person->emplyeeOrPatient == PATIENT_TYPE) {
            printPatient(*person);
        }
    }
    printf("-----------------------\n");

}
