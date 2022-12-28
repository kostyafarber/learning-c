#include "lpih.h"

#define MAXREAD 1000

int main() {
    int fd;    
    char buffer[MAXREAD + 1];

    if (read(STDIN_FILENO, buffer, MAXREAD) == -1) {
        perror("Error");
    }

    printf("%s\n", buffer);
    return 0;
}