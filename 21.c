/*
============================================================================
Name : 21.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 21. Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2025.
============================================================================
*/#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child;
    printf("Parent PID: %d\n", getpid());

    child = fork();

    if (child != 0)
        printf("Child PID (from parent): %d\n", child);
    else
        printf("I am the child. My PID: %d\n", getpid());

    return 0;
}

/* ./a.out 
Parent PID: 10278
Child PID (from parent): 10279
I am the child. My PID: 10279
*/
