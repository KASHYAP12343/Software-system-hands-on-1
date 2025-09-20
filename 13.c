
/*
============================================================================
Name : 13.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. 
              Write a proper print statement to verify whether the data is available 
              within 10 seconds or not.
Date: 23rd Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    fd_set readfds;
    struct timeval tv;
    int retval;

    // Watch stdin (fd 0) to see when it has input.
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Wait up to 10 seconds
    tv.tv_sec = 10;
    printf("Waiting for input (10 seconds)...\n");
    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (retval) {
        printf("Data is available now.\n");

        // To prove, read from stdin
        char buf[1024];
        int n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            printf("You entered: %s\n", buf);
        }
    } else {
        printf("No data within 10 seconds.\n");
    }

    return 0;
}
/*./a.out
Waiting for input (10 seconds)...
4
Data is available now.
You entered: 4
*/
