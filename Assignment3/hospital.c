

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20


int menu(PersonRec *people,int numRecords);
void printSizeOfHospitalStructs();
char promptQuit();

int main()
{
    struct person person[NUM_RECORDS];
	char rc = 0;


    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);


    // Loop the menu while invalid input is given.
    menu(person,NUM_RECORDS);
    // DONT FORGET TO FOCKING RESTRICT THE FLOAT TO ONLY REAL NUMBERS BITCH
    //

    
    return 0;
}

int menu(PersonRec *people,int numRecords){

    printf("\nWelcome to the hospital management system! What would you like to do? \n");
    char repeat = 1; // Variable to mark if the menu should be looped again. 1 indicates true

    while(repeat == 1){

        printf("\n(1) Print all employees\n");
        printf("(2) Print all patients\n");
        printf("(3) Search patient using family name\n");
        printf("(4) Summary of employees data\n");
        printf("(5) Summary of patient data\n");
        printf("(6) Size of structures (PersonRec, PatientRec, and EmployheeRec)\n");
        printf("(0) Quit  \n");
        printf("\n Please enter a choice...\n");

        int userInput;
        scanf("%d", &userInput);


        switch(userInput){
            case 1:
                // Print all employees
                printEmployees(people,numRecords);
                break;
            case 2:
                // Print all patients
                printPatients(people,numRecords);
                break;
            case 3:
                // Search patient using family name
                printf(" What family name would you like to search? \n");
                char familyName[100]; // Arbitrary Buffer size to hold family name
                scanf(" %s", familyName);
                searchPatient(people,numRecords,familyName);
                break;
            case 4:
                // Summary of employees data
                printEmployeesSummary(people,numRecords);
                break;
            case 5:
                // Summary of patient data
                printPatientSummary(people,numRecords);
                break;
            case 6:
                // Size of structures (PersonRec, PatientRec, and EmployheeRec)
                printSizeOfHospitalStructs();
                break;
            case 0:
                // Quit
                repeat = promptQuit();
                break;
            default:
                printf("Invalid input. Please try again.\n");;
                break;
        }
    }
    return 1;
}

// This function prompts the user for y or n then returns 1 indicating they want
// to continue, or 0 indicating that they'd like to quit
char promptQuit(){
    int validInput = 0;
    char dontQuit;

    do{
        printf("\n Are you sure you want to quit (y/n) \n");

        char choice;
        scanf(" %c", &choice);

        if(choice == 'y' || choice == 'Y'){
            dontQuit = 0; // 0
            validInput = 1;
        }
        else if(choice == 'n' || choice == 'N'){
            dontQuit = 1;
            validInput = 1;
        }
    }while(validInput == 0);

    return dontQuit;
}

// This function prints the size of each struct
void printSizeOfHospitalStructs(){
    printf("Size of structures\n");
    printf("Size of PersonRrect = %lu\n", sizeof(PersonRec));
    printf("Size of EmployeeRrect = %lu\n", sizeof(EmployeeRec));
    printf("Size of PatientRrect = %lu\n", sizeof(PatientRec));
}

