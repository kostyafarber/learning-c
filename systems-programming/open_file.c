#include <stdio.h>

int main() {
    char* fname = "folders.txt";
    FILE* fptr;

    fptr = fopen(fname, "r");
    // char c = fgetc(fptr);

    // printf("First character is: %c\n", c); 

    // read into a buffer
    char buffer[50];
    char* ptr;
    while (fgets(buffer, 20, fptr)) {
        printf("%s", buffer);
    }
    return 0;
}

