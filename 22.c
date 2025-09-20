/*
============================================================================
Name : 22.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 22. Write a program, open a file, call fork, and then write to the file 
              by both the child as well as the parent processes. Check output of the file.
Date: 28th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char *argv[])
{

    fork();
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);

   dprintf(fd, "written by process %d \n", getpid());

}

/*./a.out
written by process 8911
written by process 8912
*/
