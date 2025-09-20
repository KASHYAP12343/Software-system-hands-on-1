
/*
============================================================================
Name : 10.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 10. Write a program to open a file with read write mode, write 10 bytes,
              move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 20th Aug, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd;
    const char *filename = "testfile.txt";

    // Open file with read-write mode, create if not exists
    int file = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    	char data[10]="abcdefghij";
	write(file,data,10);
	
	int s=lseek(file,10,SEEK_CUR);
	printf("File offset after lseek:%d\n",s);

	write(file,data,10); 

	return 0;
}
/*
./a.out
File offset after lseek: 20
*/
