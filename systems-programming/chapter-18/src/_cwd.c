/*
* Implement getcwd()
*
* DESCRIPTION
*    The getcwd() function copies the absolute pathname of the current working directory into the memory
*    referenced by buf and returns a pointer to buf.  The size argument is the size, in bytes, of the
*    array referenced by buf.
*
*    If buf is NULL, space is allocated as necessary to store the pathname and size is ignored.  This
*    space may later be free(3)'d.
*
*    The function getwd() is a compatibility routine which calls getcwd() with its buf argument and a
*    size of MAXPATHLEN (as defined in the include file <sys/param.h>).  Obviously, buf should be at
*    least MAXPATHLEN bytes in length.
*
*/

#include "lpih.h"
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>  


struct dir_attr_check {
    ino_t i_node_child;
    ino_t i_node_parent;
    dev_t file_type;
};

static char path[PATH_MAX];
static char curr_path[PATH_MAX];
static char temp_path[PATH_MAX];

char *sep = "/";
struct dir_attr_check* 
get_curr_dir_attrs(void) 
{
    struct stat *child, *parent;
    child = (struct stat*) malloc(sizeof(struct stat));
    if (child == NULL) 
        sys_error("malloc");

    if ((stat(".", child)) == -1)
        sys_error("stat");

    parent = (struct stat*) malloc(sizeof(struct stat));
    if (parent == NULL) 
        sys_error("malloc");

    if ((stat("..", parent)) == -1)
        sys_error("stat");

    struct dir_attr_check *dir_attrs = (struct dir_attr_check*) malloc(sizeof(struct dir_attr_check));
    if (dir_attrs == NULL) {
        return NULL;
    }
    
    dir_attrs->i_node_child = child->st_ino;
    dir_attrs->i_node_parent = parent->st_ino;
    dir_attrs->file_type = child->st_dev;

    return dir_attrs;
}

void 
find_dir(ino_t child)
{

    DIR *curr_dir;
    struct dirent *dp;
    
    if ((curr_dir = opendir(".")) == NULL) {
        sys_error("open");
    }

    while ((dp = readdir(curr_dir)) != NULL) {
        struct stat sfile;
        stat(dp->d_name, &sfile);
        if (sfile.st_ino == child)
            printf("Parent directory found, name is: %s\n", dp->d_name);
    }
}

void 
traverse_directories(ino_t child, ino_t parent)
{
 
    if (child == parent) {
        return;
    }

    chdir("..");

    DIR *curr_dir;
    struct dirent *dp;
    
    curr_dir = opendir(".");
    if (curr_dir == NULL) {
        sys_error("open");
    }

    while ((dp = readdir(curr_dir)) != NULL) {
        if (errno != 0) {
            sys_error("readdir");
        } 

        struct stat sfile;
        stat(dp->d_name, &sfile);
        if (sfile.st_ino == child) {
            snprintf(curr_path, PATH_MAX, "%s%s", sep, dp->d_name);
            snprintf(temp_path, PATH_MAX, "%s", path);
            snprintf(path, PATH_MAX, "%s", curr_path);
            strcat(path, temp_path);
        }
    }
    closedir(curr_dir);

    struct dir_attr_check *curr_dir_attrs = get_curr_dir_attrs();
    if (curr_dir_attrs == NULL) {
        printf("Failed to allocate pointer");
        exit(EXIT_FAILURE);
    }

    traverse_directories(curr_dir_attrs->i_node_child, curr_dir_attrs->i_node_parent);

}

int
main(int argc, char **argv)
{
    struct dir_attr_check *curr_dir_attrs = get_curr_dir_attrs();
    if (curr_dir_attrs == NULL) {
        printf("Failed to allocate pointer");
        exit(EXIT_FAILURE);
    }
    
    traverse_directories(curr_dir_attrs->i_node_child, curr_dir_attrs->i_node_parent);
    free(curr_dir_attrs);

    printf("%s\n", path);
    exit(EXIT_SUCCESS);
}