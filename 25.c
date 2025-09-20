
/*
============================================================================
Name : 25.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 25. Write a program to create three child processes. 
              The parent should wait for a particular child (use waitpid system call).
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t c1, c2, c3;
    int status;

    c1 = fork();
    if (c1 == 0) {
        printf("Child 1 PID %d\n", getpid());
        sleep(2);
        exit(1);
    }

    c2 = fork();
    if (c2 == 0) {
        printf("Child 2 PID %d\n", getpid());
        sleep(4);
        exit(2);
    }

    c3 = fork();
    if (c3 == 0) {
        printf("Child 3 PID %d\n", getpid());
        sleep(6);
        exit(3);
    }

    printf("Parent PID %d, waiting for child 2 (PID=%d)\n", getpid(), c2);

    pid_t w = waitpid(c2, &status, 0);
    if (WIFEXITED(status)) {
        printf("Child %d exited with status %d\n", w, WEXITSTATUS(status));
    }

    sleep(7);
    return 0;
}
/*
./a.out
Child 1 PID 3470
Child 2 PID 3471
Parent PID 3469, waiting for child 2 (PID=3471)
Child 3 PID 3472
Child 3471 exited with status 2
*/
