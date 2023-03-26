#include "lpih.h"

void sys_error(char* error_type) {
    perror(error_type);
    exit(EXIT_FAILURE);
}

void usage(const char *prog_name, const char *msg) 
{
    fprintf(stderr, "usage: %s %s\n", prog_name, msg);
    exit(EXIT_FAILURE);
}