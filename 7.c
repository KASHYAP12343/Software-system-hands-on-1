
/*
============================================================================
Name : 7.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 19th Aug, 2025.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: ./mycp <file1> <file2>\n", 30);
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        perror("open source");
        exit(1);
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open destination");
        close(fd1);
        exit(1);
    }

    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(fd1, buffer, sizeof(buffer))) > 0) {
        if (write(fd2, buffer, bytes) != bytes) {
            perror("write");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }

    if (bytes < 0) {
        perror("read");
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");
    return 0;
}
/*./a.out  copy1.txt copy2.txt
File copied successfully*/

