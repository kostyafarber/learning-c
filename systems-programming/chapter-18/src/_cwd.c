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

int
main(int argc, char **argv)
{
    int fd;
    int flags;

    flags |= O_RDONLY;

    if ((open(".", flags) == -1)) {
        sys_error("open");
    }
    
    exit(EXIT_SUCCESS);
}