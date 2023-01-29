/*
* Write a program to verify that duplicated file descriptors
* share a file offset value and open file status flags
*
*   usage: 5_5_dup_share filename
*
*/

#include "lpih.h"
#define SEEK_BYTES 50

int
main(int argc, char **argv) {
    int fd, fd2;
    int flags = O_RDWR;

    if (argc > 2) {
        printf("Too many arguments, please only provide a filename\n");
        exit(EXIT_FAILURE);
    }

    if (argc < 2) {
        printf("Please provide a filename\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    printf("Opening file...\n");
    if ((fd = open(filename, flags)) == -1) {
       sys_error("open"); 
    } else {
        printf("Opened %s with file descriptor %d\n\n", filename, fd);
    }

    printf("Duplicating file decsriptor for %s\n",filename);
    if ((fd2 = dup(fd)) == -1) {
        sys_error("duplication of file desc");
    } else {
        printf("Duplicated file descriptor %d at %d\n\n", fd, fd2);
    }

    /* seeking duplicated file desc*/
    printf("Seeking on duplicated file descriptor: %d\n", fd2);
    off_t num_bytes_fd2;
    if ((num_bytes_fd2 = lseek(fd2, SEEK_BYTES, SEEK_CUR)) == 1) {
        sys_error("seek");
    } else {
        printf("Moved forward %d bytes on file descriptor %d\n\n", SEEK_BYTES, fd2);
    }

    /* seek zero bytes to get offset for fd*/
    off_t num_bytes_fd;
    printf("Performing lseek on og file descriptor %d for zero bytes...\n", fd);
    if ((num_bytes_fd = lseek(fd, 0, SEEK_CUR)) == -1) {
        sys_error("seek");
    } 
    else if (num_bytes_fd == num_bytes_fd2) {
        printf(
            "File offset is the same for both file descriptors after seeking: \n\n"
            "fd\t offset\n"
            "%d\t %lld\n" 
            "%d\t %lld\n\n", fd, num_bytes_fd, fd2, num_bytes_fd2
        );
    }

    int flags_fd2; 
    printf("Obtaining flags for duplicated file descriptor...\n");
    if ((flags_fd2 = fcntl(fd2, F_GETFL)) == -1) {
        sys_error("fcntl");
    } else if (flags == flags_fd2) {
        printf("Both file descriptors have the same flags set\n");
    }

    exit(EXIT_SUCCESS);
}