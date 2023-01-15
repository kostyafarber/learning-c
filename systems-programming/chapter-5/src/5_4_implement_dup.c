/*
* This program implements dup() and dup2() (check man pages for what they do)
* using fcntl()
* usage 
* 
*/

#include "lpih.h"

int _dup(int file_desc);

int
main(int argc, char **argv) {
    int file_des, dupe_file_des;
    int table_size;

    file_des = atoi(argv[1]);
    table_size = getdtablesize();

    if (file_des > table_size) {
        fprintf(stderr, "file descriptor of size %d larger than table size" 
                        "please reduce the number\n", file_des);
        exit(EXIT_FAILURE);
    }

    dupe_file_des = _dup(file_des);
    if (dupe_file_des >= 0) {
        printf("file descriptor %d duplicated at file descriptor %d\n", file_des, dupe_file_des);
    }

    write(dupe_file_des, "Hey from dup\n", 13);
    exit(EXIT_SUCCESS);
}


int _dup(int file_desc) {
    int new_file_desc;
    if ((new_file_desc = fcntl(file_desc, F_DUPFD, 0)) == -1) {
        sys_error("duplicate");
    }
    return new_file_desc;
}