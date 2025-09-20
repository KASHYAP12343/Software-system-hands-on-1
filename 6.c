
/*
============================================================================
Name : 6.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : Take input from STDIN, display on STDOUT using read/write
Date: 18th Aug, 2025.
============================================================================
*/

#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytes;

    while ((bytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes);
    }

    return 0;
}
/* ./a.out 
hello
hello
*/

