
/*
============================================================================
Name : 27a.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 27. Write a program to execute ls -Rl by the following system call
              a. execl
Date: 1st Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl failed");
    return 1;
}
/*
./a.out
.:
total 268
-rw-rw-r-- 1 kashyapd kashyapd   942 Sep  7 11:12 '\'
-rw-rw-r-- 1 kashyapd kashyapd  1631 Sep  7 10:40  10.c
-rw-rw-r-- 1 kashyapd kashyapd  1867 Sep  7 10:48  11.c
-rw-rw-r-- 1 kashyapd kashyapd  1545 Sep  7 10:48  12.c
-rw-rw-r-- 1 kashyapd kashyapd  1476 Sep  7 10:49  13.c
*/
