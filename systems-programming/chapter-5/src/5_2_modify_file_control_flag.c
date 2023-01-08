/*
* This program opens a file in O_APPEND mode
* and then seeks to the beginning and writes 
* some data.
* The data still gets written to the end of the file
* because seeks aren't performed when a file is opened 
* in O_APPEND mode
*/
#include "lpih.h"

#define BUFFERSIZE 1024

int
main(int argc, char **argv) {
    int fd;
    int flags, fflags;
    char buf[] = "Kostya";
    char* path = argv[1];
    flags = O_RDWR | O_APPEND;
    
    if ((fd = open(path, flags)) == -1) {
        sys_error("open");
    } else {
        printf("Successfully opened file at: %s\n", path);
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        sys_error("seek");
    }

    if (write(fd, buf, sizeof(buf)) == -1) {
        sys_error("write");
    }

    exit(EXIT_SUCCESS);
}