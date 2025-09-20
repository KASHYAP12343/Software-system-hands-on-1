/*
============================================================================
Name : 20.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 20. Find out the priority of your running program. 
              Modify the priority with nice command.
Date: 27th Aug, 2025.
============================================================================
*/

#include <unistd.h> // Import for `nice` system call
#include <stdio.h>  // Import for `printf` function
#include <stdlib.h> // `atoi` conversion from string to int

void main(int argc, char *argv[])
{
    int priority, newp;
    if (argc != 2)
        printf("Enter priority");
    else
    {
        newp = atoi(argv[1]);
        priority = nice(0); // Get the priorty by adding 0 to current priorty
        printf("Current priority: %d\n", priority);
        priority = nice(newp); // Adds `newp` to the current priority
        printf("New priority: %d\n", priority);
    }
}
/* ./a.out 10
Current priority: 0
New priority: 10
*/
