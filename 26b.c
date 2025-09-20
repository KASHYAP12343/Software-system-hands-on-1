#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Hello, %s! This is running..\n", argv[1]);
    } else {
        printf("Hello! This is running..\n");
    }
    return 0;
}

