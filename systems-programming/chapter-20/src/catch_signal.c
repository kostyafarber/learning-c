/*
* This program intends to show how to 
* implement a simple signal handler
*
* Create a handler for the SIGINT (ctrl-c) signal  
*/

#include "lpih.h"
#include <signal.h>

void sig_handler(int sig);

int
main(int argc, char **argv)
{

    if ((signal(SIGINT, sig_handler)) == SIG_ERR)
        sys_error("signal");
    
    for (;;)
        pause();

    exit(EXIT_SUCCESS);

}

void sig_handler(int sig)
{
    printf("\nDamn, catching SIGINT\n");
    return;
}