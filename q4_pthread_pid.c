#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 4


void *func(void *thread_id) {
    long t_id;
    t_id = (long)thread_id;
    printf("This is thread %ld, pthread ID - %lu\n", t_id, pthread_self());
    pthread_exit(NULL);
}


int main(int argc, char const *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, func, (void *)t);
        if (rc) {
            printf("ERORR; return code from pthread_create() is %d\n", rc);
           	exit (0);
        }
    }
    pthread_exit(NULL);
}
