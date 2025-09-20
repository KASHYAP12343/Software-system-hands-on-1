/*
============================================================================
Name : 16a.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 16. Write a program to perform mandatory locking.
              a. Implement write lock
Date: 24th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct flock fl;
    fl.l_type   = F_WRLCK;   // Write lock
    fl.l_whence = SEEK_SET;
    fl.l_start  = 0;
    fl.l_len    = 0;         // Lock entire file

    printf("Trying to acquire WRITE lock on %s...\n", argv[1]);
    if (fcntl(fd, F_SETLKW, &fl) == -1) {  // Blocking lock
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("WRITE lock acquired! Press Enter to release...\n");
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("WRITE lock released.\n");

    close(fd);
    return 0;
}
/*./a.out random.txt
Trying to acquire WRITE lock on random.txt...
WRITE lock acquired! Press Enter to release...

WRITE lock released.
*/
