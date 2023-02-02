/*
* implement setenv() and unsetenv()
* using getenv() and putenv()
*/

#include "lpih.h"

extern char **environ;

int
main(int argc, char **argv) {
    while (*environ) {
        printf("%s\n", *environ);
        environ++;
    }
}

