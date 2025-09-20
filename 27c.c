/*
============================================================================
Name : 27c.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 27. Write a program to execute ls -Rl by the following system call
              c. execle
Date: 2nd Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *envp[] = {NULL}; // simple environment
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execle failed");
    return 1;
}
/*./a.out
.:
total 268
-rw-rw-r-- 1 kashyapd kashyapd   942 Sep  7 11:12 '\'
-rw-rw-r-- 1 kashyapd kashyapd  1631 Sep  7 10:40  10.c
-rw-rw-r-- 1 kashyapd kashyapd  1867 Sep  7 10:48  11.c
-rw-rw-r-- 1 kashyapd kashyapd  1545 Sep  7 10:48  12.c
-rw-rw-r-- 1 kashyapd kashyapd  1476 Sep  7 10:49  13.c
*/

