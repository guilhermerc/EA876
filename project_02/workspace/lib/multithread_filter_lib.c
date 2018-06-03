#include <stdio.h>
#include <stdlib.h>

#include "image_processing.h"
#include "multithread_filter.h"

#include <pthread.h>
#include <time.h>

#define N_THREADS 4

typedef enum {RED, GREEN, BLUE} channel;
pthread_mutex_t lock_;

void * thread_func(void * arg)
{
	pthread_mutex_lock(&lock_);

	uint8_t * p_id = (uint8_t *) arg;
	uint8_t id = * p_id;

	pthread_mutex_unlock(&lock_);

	// calculate_matrix(RED, id);
	// calculate_matrix(GREEN, id);
	// calculate_matrix(BLUE, id);
}

void apply_multithread_filter()
{
	pthread_t threads[N_THREADS];
	uint8_t threads_id[N_THREADS];

	for(int i = 0; i < N_THREADS; i++)
		threads_id[i] = i;

	for(int i = 0; i < N_THREADS; i++)
		pthread_create(&(threads[i]), NULL, thread_func, (void *) (&(threads_id[i])));

	for(int i = 0; i < N_THREADS; i++)
		pthread_join(threads[i], NULL);
}	

/*
void calculate_matrix(channel ch, uint8_t id)
{
	float * aux = NULL;
	switch(ch)
	{
		case RED:
			{
				aux = img.r;
				break;
			}
		case GREEN:
			{
				aux = img.g;
				break;
			}
		case BLUE:
			{
				aux = img.b;
			}
	}	

	for(int k = id; k < convm.order; k += N_THREADS)
	{
		// calculate_row(i, j, k);
	}	
		}
	}
}
*/
