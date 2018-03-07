Purpose of software:
    This software was created for COMP2402 - Assignment 3
    It represents a program to view data pertaining to hospital employees
    and patients.

Developer:
    This program was developed by Nicholas Ellul - 101064168
    durign the days of March 3rd - March 4th 2018

Organization:
    Files are compressed into a tar file named a3. 
    Once decompressed these will be the files you will see.
    |
    --------- employee.c
    |       \
    |        This file contains the functions used to manipulate 
    |        employee records. This includes printing data and statistics.
    |   
    --------- employee.h
    |       \
    |        This file contains the function prototypes for hospital.c to import
    |        and use.
    |
    --------- hospital.c
    |       \
    |        This file coordinates the program. It presents a menu to the user and       
    |        other small helper functions to control the user interactions. This is 
    |        where the main function resides
    |
    --------- patient.c
    |       \
    |        This file contains the functions used to manipulate 
    |        patient records. This includes printing data and statistics.
    |
    --------- patient.h
    |       \
    |        This file contains the function prototypes for hospital.c to import
    |        and use.
    |
    --------- populateRecords.c
    |       \
    |        This file contains the code provided by Doron to provide the software
    |        with sample records to interact with.
    |
    --------- populateRecords.h
    |       \
    |        This file contains a function prototype for hospital.c to
    |        import and use. 
    |
    --------- struct.h
            \
             This file contains declarations for the structs which are used
             all throughout the program. This includes PersonRec, EmployeeRec, 
             and PatientRec

Issues and limitations:
    - The assignment provides a cap for max values which are generated in
    populateRecords.c therefor the structs are optimized where possible to 
    have the smallest possible size while encompassing the generated data.
    
    This means that for PersonRec...
        - The firstName and familyName attributes can be no longer than 14 characters
        - The emplyeeOrPatient attribute can only be 0 or 1
    
    This means that for EmployeeRec...
        - The department number must be no more than 7 and no less than 0
        - The position number must be no more than 3 and no less than 0
        - The years of service can be no greater than 63 and no less than 0

    This means that for PatientRec...
        - The department number must be no more than 7 and no less than 0
        - The numDaysInHospital must be no more than 31 and no less than 0
        - The daily cost can be no more than 63 and no less than 0
        - The severity number can be no more than 3 and no less than 0

    To change the limits on these restrictions, see bit fields and defines in struct.h

    Issue:
	The program will crash if letters are entered instead of numbers into the menu input field.

How to use this software:
    To compile, navigate to the root directory and execute...
       
        gcc hospital.c patient.c employee.c populateRecords.c

    Followed by...

        ./a.out

    Once the program begins to run you will be presented with a menu. This menu will
    describe the different interactions you may do and looks like this...

        Welcome to the hospital management system! What would you like to do? 

        (1) Print all employees
        (2) Print all patients
        (3) Search patient using family name
        (4) Summary of employees data
        (5) Summary of patient data
        (6) Size of structures (PersonRec, PatientRec, and EmployheeRec)
        (0) Quit  
