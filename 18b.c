
/*
============================================================================
Name : 18b.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 18. Write a program to perform Record locking.
              b. Implement read lock
Date: 26th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define RECSIZE 20

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <record_number>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int recno = atoi(argv[2]);
    off_t offset = recno * RECSIZE;


    struct flock lock;
    lock.l_type = F_RDLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = RECSIZE;
    lock.l_pid = getpid();

    printf("Trying to acquire read lock on record %d...\n", recno);
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }
    printf("Read lock acquired on record %d.\n", recno);


    lseek(fd, offset, SEEK_SET);
    char buffer[RECSIZE+1];
    read(fd, buffer, RECSIZE);
    buffer[RECSIZE] = '\0';

    printf("Record %d data: %s\n", recno, buffer);

    printf("Press Enter to release lock...\n");
    getchar();


    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);
    return 0;
}
/*./a.out 18.txt 2
Trying to acquire read lock on record 2...
Read lock acquired on record 2.
Record 2 data: updated
           
Press Enter to release lock...

Lock released.
*/
