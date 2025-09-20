/*
============================================================================
Name : 18a.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 18. Write a program to perform Record locking.
              a. Implement write lock
Date: 26th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define RECSIZE 20   

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <record_number>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int recno = atoi(argv[2]); 
    off_t offset = recno * RECSIZE;


    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = RECSIZE;
    lock.l_pid = getpid();

    printf("Trying to acquire write lock on record %d...\n", recno);
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }
    printf("Write lock acquired on record %d.\n", recno);

      lseek(fd, offset, SEEK_SET);

    char buffer[RECSIZE];
    printf("Enter new data for record %d: ", recno);
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);

    char fixed[RECSIZE];
    snprintf(fixed, sizeof(fixed), "%-19s", buffer); 
    write(fd, fixed, RECSIZE);

    printf("Record %d updated.\n", recno);

    printf("Press Enter to release lock...\n");
    getchar();


    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);
    return 0;
}
/*
./a.out 18.txt 2
Trying to acquire write lock on record 2...
Write lock acquired on record 2.
Enter new data for record 2: updated
Record 2 updated.
Press Enter to release lock...

Lock released.
*/
