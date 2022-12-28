#include "lpih.h"
#define BUFFERSIZE 24

int main(int argc, char **argv) {
    int fd;
    char* file = argv[1];
    char buff[BUFFERSIZE];
    ssize_t nums_read;

    fd = open(file, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "File: %s %s\n", file, strerror(errno));
    }
    
    nums_read = read(fd, buff, BUFFERSIZE);

    if (nums_read == -1) {
        perror("Read");
    }

    fprintf(stdout, "Contents read: \n%s", buff);

    exit(EXIT_SUCCESS);
}