/*
* Get stats about a certain file using the
* stat() system call
*/

#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include "lpih.h"
 

int
main(int argc, char **argv) {
    const char *file_path = "/Users/kostyafarber/repos/learning-c/systems-programming/test_files/hole.txt";
    struct stat file_stats;

    if (stat(file_path, &file_stats) == -1) {
        sys_error("stat");
    }

    printf("uid of file %d\n", file_stats.st_uid);
    printf("uid of file %d\n\n", file_stats.st_flags);

    printf("Time last accessed %s", ctime(&file_stats.st_atimespec.tv_sec));
    printf("Changing last time file accessed...\n");
    utime(file_path, NULL);
    printf("Time last accessed after utime(): %s\n", ctime(&file_stats.st_atimespec.tv_sec));

    printf("I-node number of file: %llu\n", file_stats.st_ino);


    exit(EXIT_SUCCESS);
}