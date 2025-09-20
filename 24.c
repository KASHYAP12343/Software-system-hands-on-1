/*
============================================================================
Name : 24.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 24. Write a program to create an orphan process.
Date: 29th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();
    if (pid == 0) {
        sleep(5);
        printf("Child process %d, parent %d\n", getpid(), getppid());
    } else {
        printf("Parent process %d exiting\n", getpid());
        exit(0);
    }
    return 0;
}
/*./a.out 
Parent process 6156 exiting
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:~/kashyap$ 
Child process 6157, parent 2134
*/
