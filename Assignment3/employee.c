// Made by Nicholas Ellul 101064168
// Made for COMP2401 A3
// This file contains code for manipulating employee data

#include <string.h>
#include <printf.h>
#include "employee.h"
#include "stdio.h"

// Prints employee data of a PersonRec passed in
void printEmployee(PersonRec person) {
    EmployeeRec emp = person.emp;

    // Generate string to hold the employees fullname
    //int lengthOfString = strlen(person.firstName) + strlen(person.familyName) + 2;
    char fullname[33]; // Buffer to hold the full name
    sprintf(fullname,"%s %s", person.firstName, person.familyName);

    // Calculate the salary to date since the employee started
    float salaryToDate = emp.yearsService * emp.salary;

    // Print with formatting
    printf("%-33s dept:%2u salary:%9.2f position:%2d years of service:%4d salary to-date:%11.2f\n",
           fullname, emp.department,emp.salary,emp.position,emp.yearsService,salaryToDate);
}


// Takes in a list of people and the count of them. Then calls the print function
// on those which are employees
void printEmployees(PersonRec *person, int numRecords)
{
    // Iterate though all records but only print the employee ones
    printf("\nHospital Employees\n");
    printf("-----------------------\n");
    for(int i = 0; i < numRecords; i++,person++){
        if(person ->emplyeeOrPatient == EMPLOYEE_TYPE){
            printEmployee(*person);
        }
    }
    printf("-----------------------\n");
}


// Prints overall data encompassing all employees
void printEmployeeTotalSummary(PersonRec *people, int numRecords){

    // Loop though the employees tallying up the salary and number of employees
    float totalSalary = 0.0f;
    int numEmployees = 0;
    for(int i = 0; i < numRecords; i++,people++){
        if(people ->emplyeeOrPatient == EMPLOYEE_TYPE){
            numEmployees ++;
            totalSalary += people ->emp.salary;
        }
    }

    // Calculate average salary
    float grandAvgSalary = 0.0f;
    if(numEmployees > 0) grandAvgSalary = totalSalary/numEmployees;

    printf("Total number of employees:%2d total salary:%9.2f average salary: %9.2f\n",
           numEmployees,totalSalary,grandAvgSalary);
}

// This function takes in people records and prints stats by each position
void printSummaryByPosition(PersonRec *people, int numRecords){

    // Used to reset the people pointer to the front of the the records each loop through
    PersonRec * startPosition = people;

    // Cycle though each position and print their stats
    for(int posNum = 0; posNum < MAX_POSITIONS; posNum++){

        float totalSalary = 0.0f;
        int numEmployees = 0;
        people = startPosition; // point pointer to front of people list

        // Tally up subtotals for this position
        for(int i = 0; i < numRecords; i++,people++){
            if(people ->emplyeeOrPatient == EMPLOYEE_TYPE && people->emp.position == posNum){
                numEmployees ++;
                totalSalary += people ->emp.salary;
            }
        }

        float avgSalary = 0.0f;
        if(numEmployees > 0) avgSalary = totalSalary/numEmployees;

        printf("Position[%d] - employees:%2d total salary:%9.2f average salary: %9.2f\n",
               posNum,numEmployees,totalSalary,avgSalary);
    }
}

// Prints summary statistics of all the employees, then employees by position
void printEmployeesSummary(PersonRec *people, int numRecords) {
    // add code
    printf("\nEmployee Summary:\n");
    printEmployeeTotalSummary(people,numRecords); // Prints only the overall stats
    printf("\nSummary By Position:\n");
    printSummaryByPosition(people,numRecords); // Prints the stats for each department
    printf("-----------------------\n");
}
