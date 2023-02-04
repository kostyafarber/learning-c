/*
* Implement set_env using 
* putenv
*/

#include "lpih.h"

void _setenv(char *env_pair);

int
main(int argc, char **argv) {
    if (argc != 2) {
        printf("Please provide one name and value (e.g FOO=BAR)\n");
        exit(EXIT_FAILURE);
    }
    
    char *env_value = argv[1];
    printf("Setting environment value: %s\n", env_value); 
    _setenv(env_value);
    printf("%s successfully set\n", env_value);

    char cmd[] = "env | grep ";
    char *c = malloc(strlen(cmd) + strlen(env_value) + 1);
    strcpy(c, cmd);
    strcat(c, env_value);

    printf("Checking for new var, running command: %s\n", c);
    system(c);
    free(c);
    exit(EXIT_SUCCESS);
}

void _setenv(char *env_pair) {
    if (putenv(env_pair) == -1) {
        sys_error("setting environment");
    }
}