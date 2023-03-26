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
    
    pid_t pid;
    pid = getpid();

    struct sigaction act;
    act.sa_handler = &sig_handler;
    if (sigaction(SIGUSR1, &act, NULL) == -1)
        sys_error("sigaction");

    printf("PID is: %d\n", pid);
    printf("Sleeping and waiting for signals...\n");
    
    for (;;)
        pause();

    exit(EXIT_SUCCESS);

}

void sig_handler(int sig)
{
    
    printf("Hey I caught signal (%s)\n", strsignal(sig));
    return;
}