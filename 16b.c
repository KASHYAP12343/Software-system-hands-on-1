/*
============================================================================
Name : 16b.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 16. Write a program to perform mandatory locking.
              b. Implement read lock
Date: 25th Aug, 2025.
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

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct flock fl;
    fl.l_type   = F_RDLCK;   // Read lock
    fl.l_whence = SEEK_SET;
    fl.l_start  = 0;
    fl.l_len    = 0;         // Lock entire file

    printf("Trying to acquire READ lock on %s...\n", argv[1]);
    if (fcntl(fd, F_SETLKW, &fl) == -1) {  // Blocking lock
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("READ lock acquired! Press Enter to release...\n");
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("READ lock released.\n");

    close(fd);
    return 0;
}
/* ./a.out random.txt
Trying to acquire READ lock on random.txt...
READ lock acquired! Press Enter to release...

READ lock released.
*/
