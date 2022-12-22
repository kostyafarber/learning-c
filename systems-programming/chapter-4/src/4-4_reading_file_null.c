#include "lpih.h"

#define MAXSIZE 1000

int main() {
    
    ssize_t bytes_read;
    char buffer[MAXSIZE + 1];
    bytes_read = read(STDIN_FILENO, buffer, MAXSIZE);

    if (bytes_read == -1) {
        perror("Read");
    }

    // have to manually add, as read can read from many files (sockets)
    buffer[bytes_read] = '\0';

    printf("Input read was: %sBytes read: %zd\n", buffer, bytes_read); 
    return 0;
}