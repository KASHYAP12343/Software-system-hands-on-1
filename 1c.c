/*
============================================================================
Name : 5.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : Create 5 files with infinite loop, check /proc/pid/fd
Date: 18th Aug, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkfifo("mypipe", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO created successfully.\n");
    return 0;
}

/*./a.out 
mkfifo: File exists
*/
