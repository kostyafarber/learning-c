#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                         plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <sys/errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
#include <stdbool.h>    /* 'bool' type plus 'true' and 'false' constants */
#include <fcntl.h>

int main(int argc, char **argv) {
    
    char* path = argv[1];
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("FD returned is: %d\n", fd);
    return 0;
}