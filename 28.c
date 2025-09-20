/*
============================================================================
Name : 28.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 28. Write a program to get maximum and minimum real time priority.
Date: 3rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_fifo, min_fifo, max_rr, min_rr;

    max_fifo = sched_get_priority_max(SCHED_FIFO);
    min_fifo = sched_get_priority_min(SCHED_FIFO);

    max_rr = sched_get_priority_max(SCHED_RR);
    min_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO: max priority = %d, min priority = %d\n", max_fifo, min_fifo);
    printf("SCHED_RR  : max priority = %d, min priority = %d\n", max_rr, min_rr);

    return 0;
}
/*./a.out
SCHED_FIFO: max priority = 99, min priority = 1
SCHED_RR  : max priority = 99, min priority = 1
*/
