/*
* Implement realpath()
*
*   The realpath utility uses the realpath(3) function to resolve all symbolic links, extra ‘/’ characters and references to /./ and /../ in path.  If path is absent, the current working
*   directory (‘.’) is assumed.
*
*   If -q is specified, warnings will not be printed when realpath(3) fails.
*/

#include "lpih.h"
#include <sys/syslimits.h>

int
main(int argc, char **argv) {
    const char *file_path = argv[1];

    int fd, flags;
    flags = O_RDONLY;
    
    if ((fd = open(file_path, O_RDONLY)) == -1) {
        sys_error("open");
    } 

    fchdir(fd);

    char *cwdbuf = malloc(PATH_MAX);
    
    if ((getcwd(cwdbuf, PATH_MAX)) == NULL) {
        sys_error("cwd");
    }

    printf("%s\n", cwdbuf);
    exit(EXIT_SUCCESS);    
}