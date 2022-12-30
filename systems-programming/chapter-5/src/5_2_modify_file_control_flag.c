#include "lpih.h"

int
main(int argc, char **argv) {
    int fd;
    int flags, fflags;
    char* path = argv[1];
    flags = O_RDWR | O_APPEND;
    
    if ((fd = open(path, flags)) == -1) {
        sys_error("open");
    } else {
        printf("Successfully opened file at: %s\n", path);
    }

    

    exit(EXIT_SUCCESS);
}