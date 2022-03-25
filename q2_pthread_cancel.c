#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int counter = 0;

pthread_t my_thread;

// thread_one call func
void* func1(void* ptr)
{
	while (1) {

		printf("thread 1\n");
		sleep(1); 
		counter++;
		if (counter == 2) {
			pthread_cancel(my_thread);
			pthread_exit(NULL);
		}
	}
}

void* func2(void* p)
{

	my_thread = pthread_self();

	while (1) {
		printf("thread 2\n");
		sleep(1);
	}
}

int main()
{

	pthread_t thread_one, thread_two;

	pthread_create(&thread_one, NULL, func1, NULL);
	pthread_create(&thread_two, NULL, func2, NULL);

	pthread_join(thread_one, NULL);
	pthread_join(thread_two, NULL);

}

