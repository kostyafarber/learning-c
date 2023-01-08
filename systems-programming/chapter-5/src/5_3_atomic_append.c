/*
* atomic_append(filename, number_bytes, [x])
*
* Demonstrates why atomicity with opening a file
* with a O_APPEND flag is necessary
*
* Calling this program and writing 1000000 bytes with 
* and without O_APPEND (i.e with and without x flag)
* Results in the below output from ls -l
* 
*   $ -rwxr-xr-x  1 kostyafarber  staff  2000000  8 Jan 17:21 f1
*   $ -rwxr-xr-x  1 kostyafarber  staff  1001173  8 Jan 17:21 f2
* 
* In the second instance the file size is not 2000000 as expected because 
* one program is overwriting the other because each seek and write isn't atomic.
* This creates a race condition and unpredictable results.
*
*
* Author: Kostya Farber <kostya.farber@gmail.com> 
*/

#include "lpih.h"

void usage(char *progname);
void write_bytes(long bytes, int fd, int with_append);

int
main(int argc, char **argv) {
    if (argc < 2) {
        usage(argv[0]);
    }

    char *filename = argv[1];
    int fd;
    int flags = O_CREAT | O_RDWR | O_APPEND;
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO; /* rwx-rwx-rwx */

    /* turn off append mode if flag is set */
    if ((argc == 4) && (strcmp(argv[3], "x") == 0)) {
        flags &= ~O_APPEND;
    } 

    if ((fd = open(filename, flags, mode)) == -1) {
        sys_error("open");
    } else {
        printf("Successfully opened file %s\n", filename);
    }

    long bytes = atol(argv[2]);

    if (flags & O_APPEND) {
        printf("Opened with append\n");
        write_bytes(bytes, fd, 1);
        printf("Writing bytes...\n");
    } else {
        printf("Not opened with append\n");
        write_bytes(bytes, fd, 0);
        printf("Writing bytes...\n");
    }
    printf("Finished writing %ld bytes to %s\n", bytes, filename);
    exit(EXIT_SUCCESS);
}

void usage(char *progname) {
    fprintf(stderr, "usage: %s file_name num_bytes [x]\n", progname);
    exit(EXIT_FAILURE);
}

void write_bytes(long bytes, int fd, int with_append) {
    if (with_append) {
        for (int i = 0; i < bytes; i++) {
            if (write(fd, "i", 1) == -1) {
                sys_error("write");
            }
        }
    } else {
        for (int i = 0; i < bytes; i++) {
            if (lseek(fd, 0, SEEK_END) == -1) {
                sys_error("seek");
            }

            if (write(fd, "i", 1) == -1) {
                sys_error("write");
            }
        }
    }
}