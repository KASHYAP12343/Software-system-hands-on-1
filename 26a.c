/*
============================================================================
Name : 26a.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 26. Write a program to execute an executable program.
              a. use some executable program
Date: 30th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *program = "./aa.out";      // the executable
    char *args[] = {"./aa.out",argv[1], NULL};  // arguments (argv[0] is program name)

    printf("Running %s...\n", program);

    // Replace current process with the new program
    execvp(program, args);

    // If execvp fails, print error
    perror("execvp failed");
    return 1;
}
/*cc 26b.c -o aa.out
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:~/kashyap/hands-on-1$ cc 26a.c -o 26a
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:~/kashyap/hands-on-1$ ./26a KASHYAP
Running ./aa.out...
Hello, KASHYAP! This is running.

*/
