
/*
============================================================================
Name : 23.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 23. Write a program to create a Zombie state of the running program.
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
        printf("Child process %d exiting\n", getpid());
        exit(0);
    } else {
        printf("Parent process %d, child %d\n", getpid(), pid);
        sleep(20);
    }
    return 0;
}
/*./a.out 
Parent process 6111, child 6112
Child process 6112 exiting
*/
