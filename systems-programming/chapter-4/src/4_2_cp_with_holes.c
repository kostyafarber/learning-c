#include "lpih.h"
#define BUFFERSIZE 1024

void usage(char *progname, int status);

int
main(int argc, char **argv) {
    if (argc != 3) {
        usage(argv[0], EXIT_FAILURE);
    }
    
    char* file_in = argv[1];
    char* file_out = argv[2];
    char buffer[BUFFERSIZE];
    int fdi, fdo;
    ssize_t bytes_read, bytes_write;

    int flags_in, flags_out;

    flags_in = O_RDONLY;
    flags_out = O_RDWR | O_CREAT | O_TRUNC;
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO;

    if ((fdi = open(file_in, flags_in)) == -1) {
        sys_error("Input file");
    }

    if ((fdo = open(file_out, flags_out, mode)) == -1) {
        sys_error("Output file ");
    }

    while ((bytes_read = read(fdi, buffer, BUFFERSIZE)) > 0) {
        if ((bytes_write = write(fdo, buffer, bytes_read)) == -1) {
            sys_error("Write error");
        }
    }

    if (bytes_read == -1) {
        sys_error("Partial read");
    }

    exit(EXIT_SUCCESS);
}

void usage(char *progname, int status) {
    fprintf(stderr, "usage: %s infile outfile\n", progname);
    exit(status);
}