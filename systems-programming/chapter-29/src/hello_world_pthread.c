#include "lpih.h"
#include <pthread.h>

void *threaded_function(void *arg)
{   
    char *msg = (char *) arg;
    printf("Hello from thread, passing msg: %s from main()\n", msg);
    pthread_exit(NULL);
}


int
main(int argc, char **argv)
{
    char *msg = "I'm watching succession";
    pthread_t th;
    int ret;

    ret = pthread_create(&th, NULL, threaded_function, msg);
    sleep(1);
    printf("Hi from main(), creating thread\n");
    if (ret != 0) {
        sys_error("pthread_create");
    }

    ret = pthread_join(th, NULL);
    if (ret != 0) {
        sys_error("pthread_join");
    }

    exit(EXIT_SUCCESS);
}