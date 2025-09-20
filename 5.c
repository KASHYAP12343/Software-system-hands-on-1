/*
============================================================================
Name : 5.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : Create 5 files with infinite loop, check /proc/pid/fd
Date: 6 Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fds[5];
    char filename[20];

    for (int i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "file%d.txt", i + 1);
        fds[i] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fds[i] < 0) {
            perror("open");
            exit(1);
        }
        dprintf(fds[i], "This is file %d\n", i + 1);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}/* ./a.out
    cd /proc/8216/fd
kashyapd@kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:/proc/8216/fd$ ls -l
lrwx------ 1 kashyapd kashyapd 64 Sep  6 18:43 0 -> /dev/pts/0
lrwx------ 1 kashyapd kashyapd 64 Sep  6 18:43 1 -> /dev/pts/0
lrwx------ 1 kashyapd kashyapd 64 Sep  6 18:43 2 -> /dev/pts/0
l-wx------ 1 kashyapd kashyapd 64 Sep  6 18:43 3 -> /home/kashyapd/kashyap/file1.txt
l-wx------ 1 kashyapd kashyapd 64 Sep  6 18:43 4 -> /home/kashyapd/kashyap/file2.txt
l-wx------ 1 kashyapd kashyapd 64 Sep  6 18:43 5 -> /home/kashyapd/kashyap/file3.txt
l-wx------ 1 kashyapd kashyapd 64 Sep  6 18:43 6 -> /home/kashyapd/kashyap/file4.txt
l-wx------ 1 kashyapd kashyapd 64 Sep  6 18:43 7 -> /home/kashyapd/kashyap/file5.txt
*/ 
