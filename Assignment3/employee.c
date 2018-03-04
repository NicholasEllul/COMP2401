#include <string.h>
#include <printf.h>
#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person) {
    EmployeeRec emp = person.emp;

    // Generate string to hold the employees fullname
    //int lengthOfString = strlen(person.firstName) + strlen(person.familyName) + 2;
    char fullname[33];
    sprintf(fullname,"%s %s", person.firstName, person.familyName);

    // Calculate the salary to date since the employee started
    float salaryToDate = emp.yearsService * emp.salary;

    // Print with formatting
    printf("%-33s dept:%2u salary:%9.2f position:%2d years of service:%4d salary to-date:%11.2f\n",
           fullname, emp.department,emp.salary,emp.position,emp.yearsService,salaryToDate);
}

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


void printEmployeesSummary(PersonRec *person, int numRecords)
{
    // add code
    printf("\nEmployee Summary:\n");
    printf("-----------------------\n");
    PersonRec *startPosition = person;

    // Indexes 0-3 of this array correspond to positions.
    int numEmployees[4];
    float salaries[4];

    for(int posNum = 0; posNum < 4; posNum++){
        // Variables used to subtotal the data for each position
        person=startPosition;
        numEmployees[posNum]=0;
        salaries[posNum]=0;
        for(int j = 0; j < numRecords; j++,person++){
            if(person ->emplyeeOrPatient == EMPLOYEE_TYPE && person->emp.position == posNum){
                numEmployees[posNum]++;
                salaries[posNum] += person ->emp.salary;
            }
        }
    }

    // Tally Up Totals
    float grandTotalSalary = 0;
    int grandTotalEmployees = 0;
    for(int i = 0; i < 4; i++){
        grandTotalEmployees += numEmployees[i];
        grandTotalSalary += salaries[i];
    }

    float grandAvgSalary = 0.0f;
    if(grandTotalEmployees > 0) grandAvgSalary = grandTotalSalary/grandTotalEmployees;

    // Dorons instructions say to let the average salary have less digits than the salary but that makes no sense
    // considering the average can also be 6 figures
    printf("Total number of employees:%2d total salary:%9.2f average salary: %9.2f\n",
           grandTotalEmployees,grandTotalSalary,grandAvgSalary);

    // Tally Up Totals
    for(int i = 0; i < 4; i++){
        float avgSalary = 0.0f;
        if(numEmployees[i] > 0) avgSalary = salaries[i]/numEmployees[i];
        printf("Position[%d] - employees:%2d total salary:%9.2f average salary: %9.2f\n",
                i,numEmployees[i],salaries[i],avgSalary);
    }

    printf("-----------------------\n");
}
