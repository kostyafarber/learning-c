/*
* a program to demonstrate 
* how hard links work
*/

#include "lpih.h"

int
main(int argc, char **argv) {
    /* array of pointers to type*/
    char *cmds[] = {
        "echo 'It is good to collect things, ' > abc",
        "ls -li abc",
        "ln abc xyz",
        "echo ' but it is better to go on a walks.' >> xyz",
        "cat abc",
        "ls -li abc xyz",
        NULL
    };

    /* pointer to pointer to type*/
    char **char_ptr = cmds;
    while (*char_ptr) {
        // printf("%s\n", *char_ptr);
        system(*char_ptr);
        char_ptr++;
    }
}