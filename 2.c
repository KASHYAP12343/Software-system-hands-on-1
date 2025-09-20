
/*
============================================================================
Name : 2.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 2. Write a simple program to execute in an infinite loop at 
              the background. Go to /proc directory and identify all the 
              process related information in the corresponding proc directory.
Date: 16th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Running in background... PID: %d\n", getpid());
        sleep(5); // Sleep for 5 seconds to avoid CPU hogging
    }
    return 0;
}

/* ./a.out 
 * Running in background... PID: 14747*/

