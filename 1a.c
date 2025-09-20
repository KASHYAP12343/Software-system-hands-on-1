/*============================================================================
Name : 1a.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 1. Create the following types of files using system call
              a. soft link (symlink system call)
Date: 15th Aug, 2025.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    if (symlink("original_file.txt", "soft_link.txt") == -1) {
        perror("symlink");
        return 1;
    }
    printf("sucess");
    return 0;
}
/*./a.out
sucess*/
                  
