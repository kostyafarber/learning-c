#include <stdio.h>

int main(int argc, char **argv) {
    int i = 1;
    while (i < argc) {

        // can use this method to access every char of the underlying args
        // char *arg_i = argv[i];
        // while (*arg_i) {
        //     printf("%c", *arg_i);
        //     arg_i++;
        // }

        printf("%s", argv[i]);
        printf("\n");
        i++;
    }
    
    return 0;
}