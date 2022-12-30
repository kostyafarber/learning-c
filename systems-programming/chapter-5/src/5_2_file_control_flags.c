/*
* This program intends to look at how to extract
open flags from files that have already been open.

I will try to open "test_file.txt" 
and then obtain the flags I've used.

The use of ACC_MODE is important as we can't do fflags & O_ASYNC
directly for access modes so we have to check the equality, in this
case using a mask to extract the correct value.
*/

#include "lpih.h"

int
main(int argc, char** argv) {
    int fd;
    int flags, fflags;
    char* path = argv[1];
    flags = O_RDWR | O_ASYNC; /* 01000010 */

    if ((fd = open(path, flags)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    } else {
        printf("The file %s has been opened successfully\n", path);
    }

    if ((fflags = fcntl(fd, F_GETFL)) == -1) {
        perror("file control");
    } else {
        printf("flags in hex: %x\n", fflags); 
        printf("flags in octal: %o\n", fflags); 
    }

    if (fflags & O_ASYNC) { /* could make it more explicit with ((fflags & O_ASYNC) == O_ASYNC) */
        printf("File is open as async\n");
    }

    int access_mode = fflags & O_ACCMODE;   /* O_ACCMODE = 00000011 */
                                            /* O_RDWR    = 00000010 */
                                            /* O_WRONLY  = 00000001 */
                                            /* O_RDONLY  = 00000000 */ 
    
    if (access_mode == O_RDWR) { /* can make the check explicitly (fflags & O_RDONLY) == O_RDONLY)*/
        printf("File was opened with read and write access\n");
    }

    exit(EXIT_SUCCESS);
}