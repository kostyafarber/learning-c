/*
* An example of using nftw (ftw, nftw – traverse (walk) a file tree)
*
*/

#include "lpih.h"
#include <ftw.h>

#define NUM_TYPES 3

enum types {
    file,
    dir,
    sym_link
};

int print_size_dir(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf);
void print_and_increment(enum types file_type, const char *fpath);

static int file_counts[NUM_TYPES];
const char *msgs[] = {
    "is a file",
    "is a directory",
    "is a symbolic link"
};

int
main(int argc, char **argv)
{
    if (nftw(".", print_size_dir, 20, 0) == -1) {
        sys_error("nftw\n");
    }

    printf("Number of files after traversal is: %d\n", file_counts[file]);
    printf("Number of directories after traversal is: %d\n", file_counts[dir]);
    exit(EXIT_SUCCESS);
}

int print_size_dir(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    
    if (typeflag == FTW_F) {
        print_and_increment(file, fpath);
    } else if (typeflag == FTW_D) {
        print_and_increment(dir, fpath);
    }
    // printf("Size of: %s is %lld\n", fpath, sb->st_size);
    return 0;
}

void print_and_increment(enum types file_type, const char *fpath) {
    file_counts[file_type]++;
    printf("%s %s\n", fpath, msgs[file_type]);
}