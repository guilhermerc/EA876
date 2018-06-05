#include <stdlib.h>
#include <stdint.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "multithread_filter_lib.h"

#include <pthread.h>
#include <time.h>

typedef enum {R, G, B} channel;

void thread_conv(channel ch, uint8_t id);

pthread_mutex_t lock_;

void * thread_func(void * arg)
{
    pthread_mutex_lock(&lock_);

    uint8_t * p_id = (uint8_t *) arg;
    uint8_t id = * p_id;

    pthread_mutex_unlock(&lock_);

    thread_conv(R, id); thread_conv(G, id); thread_conv(B, id);
}

// This function applies filter given by the convolution operation of the
// convolution matrix 'cm' by each pixel of the image 'img' (both are global
// variables) using multiple (at least > 1) threads. The number of threads are
// defined as an argument of main call.
void multithread_filter()
{
    pthread_t threads[N_THREADS];
    uint8_t threads_id[N_THREADS];

    for(int i = 0; i < N_THREADS; i++)
        threads_id[i] = i;

    for(int i = 0; i < N_THREADS; i++)
        pthread_create(&(threads[i]), NULL, thread_func, (void *)
                (&(threads_id[i])));

    for(int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
}	

// Each thread is responsible for calculating a certain number of dot products
// between a convolution matrix row and a image row under a filtering operation.
// These dot products contribute to a convolution operation result. This
// function traverses an image's channel matrix (R, G or B) and calculates the
// contribution of the lines in charge by the current thread to the convolution
// operation and updates the image buffer 'tmp' (used to keep the under
// construction image).
void thread_conv(channel ch, uint8_t id) 
{
    float * img_channel = NULL;
    float * tmp_channel = NULL;
    switch(ch)
    {
        case R:
            {
                img_channel = img.r;
                tmp_channel = tmp.r;
                break;
            }
        case G:
            {
                img_channel = img.g;
                tmp_channel = tmp.g;
                break;
            }
        case B:
            {
                img_channel = img.b;
                tmp_channel = tmp.b;
            }
    }

    // Traversing the image matrix rows
    for(uint16_t row = 0; row < img.height; row++)
    {
        // Traversing the image matrix columns
        for(uint16_t column = 0; column < img.width; column++)
        {
            // Trying to divide equally the number of dot products to each
            // thread calculate. If the order of the convolution matrix is a
            // multiple of the number of threads, they're balanced. If not,
            // there will be threads doing 1 more row than others.
            for(uint16_t thread_row = id; thread_row < cm.order; thread_row
                    += N_THREADS)
                tmp_channel[array_matrix_index(tmp, row, column)] += (float)
                    calculate_conv_row(img, img_channel, cm, row, column,
                            thread_row) / cm.divider; 
        }
    }
}
