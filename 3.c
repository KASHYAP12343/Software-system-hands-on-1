/*
============================================================================
Name : 3.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 3. Write a program to create a file and print the file descriptor value.
              Use creat() system call.
Date: 17th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>   // for creat()
#include <unistd.h>  // for close()

int main() {
    int fd;

    // creat() takes filename and permissions (mode)
    fd = creat("myfile.txt", 0644);  

    if (fd == -1) {
        perror("creat");   // prints error if creation fails
        return 1;
    }

    printf("File created successfully.\n");
    printf("File descriptor: %d\n", fd);

    // Always close the file descriptor when done
    close(fd);

    return 0;
}
/*./a.out 
File created successfully.
File descriptor: 3
*/

