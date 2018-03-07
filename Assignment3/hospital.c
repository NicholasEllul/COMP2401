// Made by Nicholas Ellul 101064168
// Made for COMP2401 A3
// This file contains code for the menu and initialization

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20


int menu();
void printSizeOfHospitalStructs();
char promptQuit();

// Maps user input to functions as well as populates sample data
int main()
{
    struct person person[NUM_RECORDS];
    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);

    printf("\nWelcome to the hospital management system! What would you like to do? \n");

    // Excecute appropriate function based on user input from the menu function
    int quitMenu = 0;
    while (quitMenu == 0){
        switch(menu(person,NUM_RECORDS)){
            case 1:
                // Print all employees
                printEmployees(person,NUM_RECORDS);
                break;
            case 2:
                // Print all patients
                printPatients(person,NUM_RECORDS);
                break;
            case 3:
                searchPatient(person,NUM_RECORDS);
                break;
            case 4:
                // Summary of employees data
                printEmployeesSummary(person,NUM_RECORDS);
                break;
            case 5:
                // Summary of patient data
                printPatientSummary(person,NUM_RECORDS);
                break;
            case 6:
                // Size of structures (PersonRec, PatientRec, and EmployheeRec)
                printSizeOfHospitalStructs();
                break;
            case 0:
                // Quit
                quitMenu = promptQuit();
                break;
        }
    }
    return 0;
}


// Prompts the user to enter a valid integer corrisponding to a menu action.
// returns that number if a valid input is given, or returns -1 if not.
int menu() {

        printf("\n(1) Print all employees\n");
        printf("(2) Print all patients\n");
        printf("(3) Search patients by family name\n");
        printf("(4) Summary of employee data\n");
        printf("(5) Summary of patient data\n");
        printf("(6) Size of structures (PersonRec, PatientRec, and EmployheeRec)\n");
        printf("(0) Quit  \n");
        printf("\n Please enter a choice...\n");

        int userInput;
        scanf(" %d",&userInput);

        if (userInput < 0 || userInput > 6) {
            printf("Sorry that is not a valid option. Please try again\n");
            return -1;
        } else {
            return userInput;
        }
}

// This function prompts the user for y or n then returns 1 indicating they want
// to continue, or 0 indicating that they'd like to quit
char promptQuit(){
    int validInput = 0;
    char quit;

    do{
        printf("\n Are you sure you want to quit (y/n) \n");

        char choice;
        scanf(" %c", &choice);

        // Check for uppercase or lowercase then flag variables
        if(choice == 'y' || choice == 'Y'){
            quit = 1; // 0
            validInput = 1;
        }
        else if(choice == 'n' || choice == 'N'){
            quit = 0;
            validInput = 1;
        }
    }while(validInput == 0);

    return quit;
}

// This function prints the size of each struct
void printSizeOfHospitalStructs(){
    printf("Size of structures\n");
    printf("Size of PersonRrect = %zu\n", sizeof(PersonRec));
    printf("Size of EmployeeRrect = %zu\n", sizeof(EmployeeRec));
    printf("Size of PatientRrect = %zu\n", sizeof(PatientRec));
    printf("-----------------------\n");
}

