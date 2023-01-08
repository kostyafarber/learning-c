#include "lpih.h"

void sys_error(char* error_type) {
    perror(error_type);
    exit(EXIT_FAILURE);
}