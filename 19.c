
/*
============================================================================
Name : 19.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 19. Write a program to find out time taken to execute getpid 
              system call. Use time stamp counter.
Date: 27th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}

void main()
{
    long long int s, e;
    s = rdtsc();
    printf("Process id: %d\n", getpid());
    e = rdtsc();
    printf("Difference is : %llu\n", e - s);
}
/*./a.out 
Process id: 5856
Difference is : 256740
*/
