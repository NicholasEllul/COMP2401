Made by Nicholas Ellul - 101064168
Made for 2401 Assignment 2

This readme covers the file transmit.c

For transmit.c to run, header file bit_manipulation.h must be imported 
which will refer to bit manipulation function in bit_manipulation.c

Transmit.c takes in text from the command line, and converts it to a short to be transmitted. Intentional errors are
added to this short code. The file uses parity bits in order to mark errors for the reciever.

The short will be printed for the user and is ready to be interpreted by recieve.c


COMPILE INSTRUCTIONS
	gcc -o Transmit transmit.c bit_manipulation.c

RUN INSTRUCTIONS
	./Transmit


Example Input Output

    Input:
        Tell your story. Write for the learning log.


    Output:
        2624 2136 3264 3136 1284 3480 3324 1882 3634 1284 3964 3956 3308 3890 3992
        1524 3332 2668 3858 3226 3924 3160 1292 3172 3316 4018 1292 3932 3204 3144 
        1284 3264 2136 3084 3890 3314 3218 2290 3178 1028 3200 3320 3182 1520

    --------------------------------------------------------------------------------

    Input:
        University drive temporary lane closure notice

    Output:
        2638 2290 3226 4070 3160 3378 3900 1178 3668 3992 1348 3190 3874 3226 3942
        3160 3332 3924 3192 3278 3840 3324 3898 3084 3898 3864 1292 3272 3100 3298
        3160 1284 2110 3264 3324 3900 3922 2866 3160 1028 3250 3320 3920 3230 3646
        3288