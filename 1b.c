/*
============================================================================
Name : 1b.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 1. Create the following types of files using system call
b. hard link (link system call)
Date: 16th Aug, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    if (link("original.txt", "hardlink.txt") == -1) {
        perror("link");
        return 1;
    }
    printf("Hard link created successfully.\n");
    return 0;
}

/*./a.out 
Hard link created successfully.

*/



