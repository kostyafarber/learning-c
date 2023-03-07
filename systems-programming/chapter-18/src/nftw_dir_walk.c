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

int file_counts[NUM_TYPES];
int total = 0;
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
    printf("Total is: %d\n", total);
    exit(EXIT_SUCCESS);
}

int print_size_dir(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    int file_type = sb->st_mode;

    printf("File type:                ");
    
        switch (file_type & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    return 0;
}

void print_and_increment(enum types file_type, const char *fpath) {
    total++;
    file_counts[file_type]++;
    printf("%s %s\n", fpath, msgs[file_type]);
}