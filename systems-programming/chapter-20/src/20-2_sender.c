/*
*
* Write a program that shows that when the disposition of a 
* pending signal is changed to SIG_IGN, the program never
* sees (catches) the signal
* 
*   Step 1: Send a signal to a process that blocks that signal this
*   causes it to be pending. 
* 
*   Step 2: Change the disposition of that signal to be of SIG_IGN.
*
*   Step 3: Unblock the signal on the receiving process and confirm that it 
            has not been received.
*/

#include "lpih.h"
#include <signal.h>

void sig_handler(int sig);

int
main(int argc, char **argv)
{
    if (argc > 3 || strcmp(argv[1], "--help") == 0)
        usage(argv[0], "pid");

    pid_t pid;
    pid = atoi(argv[1]);

    if (kill(pid, SIGUSR1) == -1)
        sys_error("kill");
    
    if (argc > 2) {
        int sig;
        sig = atoi(argv[2]);
        if (kill(pid, sig) == -1) {
            sys_error("kill");
        }
    }

    exit(EXIT_SUCCESS);

}

void sig_handler(int sig)
{
    return;
}