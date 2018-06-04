#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "image_io_lib.h"
#include "multithread_filter_lib.h"

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

    // (RED, id);
    // (GREEN, id);
    // (BLUE, id);
}

void multithread_filter(image img, image tmp, conv_matrix cm)
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
        // calculate
    }	
*/
