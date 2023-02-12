/*
* Get stats about a certain file using the
* stat() system call
*/

#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include "lpih.h"
#define BUFFSIZE 1024


char* 
get_basename(char *file_path);

int
main(int argc, char **argv) {
    char file_path[] = "/Users/kostyafarber/repos/learning-c/systems-programming/test_files/hole.txt";
    struct stat file_stats;

    char *basename;
    basename = get_basename(file_path);

    if (stat(file_path, &file_stats) == -1) {
        sys_error("stat");
    }


    printf("uid of %s is %d\n", basename, file_stats.st_uid);
    printf("uid of %s is %d\n\n", basename, file_stats.st_flags);
    free(basename);

    printf("Time last accessed %s", ctime(&file_stats.st_atimespec.tv_sec));
    printf("Changing last time file accessed...\n");
    utime(file_path, NULL);
    printf("Time last accessed after utime(): %s\n", ctime(&file_stats.st_atimespec.tv_sec));

    printf("I-node number of file: %llu\n", file_stats.st_ino);


    exit(EXIT_SUCCESS);
}

char* 
get_basename(char *file_path) {
    FILE *cmd_output_stream;
    char buffer[BUFFSIZE];
    char cmd[] = "basename ";
    char *cmd_ptr = malloc(strlen(cmd) + strlen(file_path) + 1);
    
    strcpy(cmd_ptr, cmd);
    strcat(cmd_ptr, file_path);

    cmd_output_stream = popen(cmd_ptr, "r");
    free(cmd_ptr);

    char *base_path = malloc(strlen(file_path));
    while (fgets(buffer, sizeof(file_path), cmd_output_stream) != NULL) {
        strcat(base_path, buffer);
    }

    base_path[sizeof(base_path)] = '\0'; /* strip newline */
    return base_path;
}