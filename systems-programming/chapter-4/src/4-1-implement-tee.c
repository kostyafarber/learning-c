/*
* The purpose of this program is implement UNIX tee
* tee prints it's input to output and writes it to a user provided file
* @params file path
* 
*/

#include "lpih.h"
#define MAXBUFFERSIZE 1024

int
main(int argc, char **argv) {
    int fd;
    char* fp = argv[1];
    char buff[MAXBUFFERSIZE + 1];
    ssize_t bytes_read_input, bytes_write_stdout, bytes_write_file;

    fd = open(fp, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("file");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read_input = read(STDIN_FILENO, buff, MAXBUFFERSIZE)) != 0) {
        if (bytes_read_input == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        /*
        there key here for me was to write the amount that was read up above not   
        the maxbuff size
        */

        bytes_write_stdout = write(STDOUT_FILENO, buff, bytes_read_input);
        if (bytes_write_stdout == -1) {
            perror("error writing stdout");
        }

        bytes_write_file = write(fd, buff, bytes_read_input);
        if (bytes_write_file == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    
    exit(EXIT_SUCCESS);
}