/*
============================================================================
Name : 12.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 21st Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);  // you can open with any mode to test
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    int flags = fcntl(fd, F_GETFL);   // get file status flags
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    // Mask with O_ACCMODE to get only the access mode bits
    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File is opened in READ ONLY mode\n");
            break;
        case O_WRONLY:
            printf("File is opened in WRITE ONLY mode\n");
            break;
        case O_RDWR:
            printf("File is opened in READ/WRITE mode\n");
            break;
        default:
            printf("Unknown access mode\n");
    }
    close(fd);
  return 0;
}
/*./a.out random.txt
File is opened in READ ONLY mode
*/
