
/*
============================================================================
Name : 17.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 17. Write a program to simulate online ticket reservation.
              Implement write lock.
Date: 25th Aug, 2025.
============================================================================
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error while opening file!");
        return 1;
    }
    int num;
    printf("Enter ticket number: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    char buf[20];
    int n = snprintf(buf, sizeof(buf), "%d\n", num); // convert number to string
    if (write(fd, buf, n) == -1)
    {
        perror("Error while writing to file");
    } else
    {
        printf("Ticket number is stored in file\n");
    }

    close(fd);
    return 0;
}
/*./a.out ticket.txt 
Enter ticket number: 4
Ticket number is stored in file
*/
