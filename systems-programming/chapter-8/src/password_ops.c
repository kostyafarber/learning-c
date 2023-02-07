/*
* Playing around with the
* getpwnam() functions
*/

#include "lpih.h"
#include <pwd.h>

int
main(int argc, char **argv) {
    struct passwd *attributes;

    attributes = getpwnam("kostyafarber");

    printf("username is: %s\n", attributes->pw_name);
    printf("user id: %u\n", attributes->pw_uid);
    printf("encrypted password: %s\n", attributes->pw_passwd);
    printf("last time %ld\n", attributes->pw_change);
    printf("user shell: %s\n", attributes->pw_shell);
}