Made by Nicholas Ellul - 101064168
Made for 2401 Assignment 2

This readme covers the file recieve.c

For recieve.c to run, header file bit_manipulation.h must be imported 
which will refer to bit manipulation function in bit_manipulation.c

Recieve.c takes the keyboard input of a short that represented an encoded message. Then this file prints back the shorts
conversion as characters. Note that there may be errors in this translation, so the file then checks the parity bits of the 
message and returns the corrected decoded message back to the user. 

COMPILE INSTRUCTIONS
	gcc -o Recieve recieve.c bit_manipulation.c

RUN INSTRUCTIONS
	./Recieve

Example Input Output
    Input: 
        2624 2136 3264 3136 1284 3480 3324 1882 3634 1284 3964 3956 3308 3890 3992 
        1524 3332 2668 3858 3226 3924 3160 1292 3172 3316 4018 1292 3932 3204 3144 1284 
        3264 2136 3084 3890 3314 3218 2290 3178 1028 3200 3320 3182 1520


    Output:
        Transmitted Message:
        TEld io5r wvory.`Wpite!fnz!uhe lEarnhNg hog.
        4100709011806540001105000303733440010000310086222

        Corrected Transmitted Message:
        Tell your story. Write for the learning log.

-----------------------------------------------------------------------------------------
    Input:
        2638 2290 3226 4070 3160 3378 3900 1178 3668 3992 1348 3190 3874 3226 3942 3160 3332 3924 3192 3278 3840
        3324 3898 3084 3898 3864 1292 3272 3100 3298 3160 1284 2110 3264 3324 3900 3922 2866 3160 1028 3250 3320 
        3920 3230 3646 3288

    Output:
        Transmitted Message:
        UNi~ebs)ty$frive`tgmposasq!mane ClostRe jotism
        410070901180654000110500030373344001000031008622297

        Corrected Transmitted Message:
        University drive temporary lane closure notice


