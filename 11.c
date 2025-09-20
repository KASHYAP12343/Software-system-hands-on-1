/*
============================================================================
Name : 11.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 21st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd, fd_dup1, fd_dup2, fd_dup3;
    const char *filename = "dup_test.txt";

    // Open file in append mode
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // a. Duplicate using dup()
    fd_dup1 = dup(fd);
    if (fd_dup1 < 0) {
        perror("dup");
        exit(1);
    }

    // b. Duplicate using dup2()
    fd_dup2 = dup2(fd, fd + 10);  // duplicate into fd+10
    if (fd_dup2 < 0) {
        perror("dup2");
        exit(1);
    }

    // c. Duplicate using fcntl()
    fd_dup3 = fcntl(fd, F_DUPFD, 100);  // duplicate into fd >= 100
    if (fd_dup3 < 0) {
        perror("fcntl");
        exit(1);
    }

    // Write using all descriptors
    write(fd, "Hello from fd\n", 14);
    write(fd_dup1, "Hello from dup\n", 15);
    write(fd_dup2, "Hello from dup2\n", 16);
    write(fd_dup3, "Hello from fcntl\n", 17);

    // Close all descriptors
    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    printf("Data written. Open %s to verify.\n", filename);
    return 0;
}
/*./a.out
Data written. Open dup_test.txt to verify.
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:~/kashyap$ cat dup_test.txt

Hello from fd
Hello from dup
Hello from dup2
Hello from fcntl
*/
