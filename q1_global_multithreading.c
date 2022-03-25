#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//global variable 
int a = 0;

// The function to be executed by all threads
void *myThreadFun(void *arg)
{
	// Store the value argument passed to this thread
	int *my_id = (int *)arg;
	++a;

	// Print the argument,global variables
	printf("Thread ID: %d, Global: %d\n", *my_id, ++a);
}

int main()

{
    int i;
    pthread_t tid;
  
    // Let us create three threads
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
  
    pthread_exit(NULL);
    return 0;

}

