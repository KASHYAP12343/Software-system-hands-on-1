/*
============================================================================
Name : 4.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 4. Write a program to open an existing file with read write mode.
              Try O_EXCL flag also.
Date: 17th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>   // for open
#include <unistd.h>  // for close, read, write
#include <string.h>  // for strlen
#include <errno.h>   // for errno

int main() {
    int fd;

    // 1. Open an existing file with read/write mode
    fd = open("testfile.txt", O_RDWR);
    if (fd == -1) {
        perror("open existing file");
    } else {
        printf("Opened existing file successfully (fd=%d)\n", fd);
        close(fd);
    }

    // 2. Try O_EXCL with O_CREAT
    fd = open("testfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open with O_EXCL");
    } else {
        printf("Created new file successfully with O_EXCL (fd=%d)\n", fd);
        write(fd, "Hello, O_EXCL!\n", strlen("Hello, O_EXCL!\n"));
        close(fd);
    }

    return 0;
}

/*./a.out 
Opened existing file successfully (fd=3)
open with O_EXCL: File exists
*/
