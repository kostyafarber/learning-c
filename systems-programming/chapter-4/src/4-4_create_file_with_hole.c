#include "lpih.h"
/*
* This program looks to create a file with a "file hole".
* It will write first 6 letters of the alphabet (lower) then
* then the upper chars. 
*/

#define BUFFERSIZE 1024;

int
main(int argc, char **argv) {
    char l_letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char u_letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int flags = O_CREAT | O_TRUNC | O_WRONLY;
    mode_t mode = S_IRUSR | S_IWUSR;
    ssize_t bytes_read;
    int fd;

    if ((fd = open("hole.txt", flags, mode)) == -1) {
        perror("read");
    }

    if ((bytes_read = write(fd, l_letters, sizeof(l_letters))) < 0) {
        perror("write");
    }

    off_t offset;
    if ((offset = lseek(fd, 100, SEEK_CUR)) == -1) {
        perror("seek");
    }

    // file offset now 100 after file bytes 
    if ((bytes_read = write(fd, u_letters, sizeof(u_letters))) < 0) {
        perror("second write");
    }
}