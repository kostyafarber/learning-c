#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("This is the entry point into main \n");
    
    pid = fork();

    if (pid == 0) {
        printf("Hello from the child process! I will list all the current files here");
        system("ls -a");
    }

    else { // parent
        printf("Hello from the parent, I'm going to print all numbers from 0-9 \n");

        for (int i = 0; i < 10; i++) {
            printf("%d \n", i);
        }
    }

    return 0;
}