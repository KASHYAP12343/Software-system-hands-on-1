
/*
============================================================================
Name : 30.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 30. Write a program to run a script at a specific time using a Daemon process.
Date: 5th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hour> <minute> <second>\n", argv[0]);
        exit(1);
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);
    int target_sec = atoi(argv[3]);
   

    pid_t pid = fork();
    if (pid > 0) exit(0); // parent exits
    if (pid < 0) exit(1); // fork failed

    umask(0);
    setsid(); // create new session

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min && t->tm_sec == target_sec)
       	{
	    system("./30.sh");
            sleep(1); // avoid running multiple times in same second
        }

        sleep(1); // check every second
    }

    return 0;
}

/*
  ./a.out
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:~/kashyap$ Hello from script at Sun Sep  7 12:25:00 PM IST 2025
*/
