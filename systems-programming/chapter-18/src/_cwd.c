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

struct dir_attr_check {
    ino_t i_node_child;
    ino_t i_node_parent;
    __uint8_t file_type;
};

struct dir_attr_check* 
get_curr_dir_attrs(void) 
{
    DIR *child_dir, *parent_dir;
    struct dirent *dp_child, *dp_parent;

    if ((child_dir = opendir(".")) == NULL) {
        sys_error("open");
    }

    if ((dp_child = readdir(child_dir)) == NULL) {
        sys_error("readdir");
    }
    
    if ((parent_dir = opendir("..")) == NULL) {
        sys_error("open");
    }

    if ((dp_parent = readdir(parent_dir)) == NULL) {
        sys_error("readdir");
    }

    struct dir_attr_check *dir_attrs = (struct dir_attr_check*) malloc(sizeof(struct dir_attr_check));
    if (dir_attrs == NULL) {
        return NULL;
    }
    
    dir_attrs->i_node_child = dp_child->d_ino;
    dir_attrs->i_node_parent = dp_parent->d_ino;
    dir_attrs->file_type = dp_child->d_type;

    return dir_attrs;
}

void 
traverse_directories(ino_t child, ino_t parent)
{
    if (child == parent) {
        return;
    }
 
    chdir("..");

    struct dir_attr_check *curr_dir_attrs = get_curr_dir_attrs();
    if (curr_dir_attrs == NULL) {
        printf("Failed to allocate pointer");
        exit(EXIT_FAILURE);
    }

    DIR *curr_dir;
    struct dirent *dp;
    
    if ((curr_dir = opendir(".")) == NULL) {
        sys_error("open");
    }
    
    while ((dp = readdir(curr_dir)) != NULL) {
        if (dp->d_ino == child)
            printf("Parent directory found, name is: %s\n", dp->d_name);
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
    exit(EXIT_SUCCESS);
}