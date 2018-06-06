#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>  // define pid_t
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>     // fork()

//#include <sys/sysinfo.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "multiprocess_filter_lib.h"

#include <time.h>

typedef enum {R, G, B} channel;

void proc_conv(channel ch, uint8_t id, image * shared_tmp) 
{
    float * img_channel = NULL;
    float * shared_tmp_channel = NULL;
    switch(ch)
    {
        case R:
            {
                img_channel = img.r;
                shared_tmp_channel = shared_tmp->r;
                break;
            }
        case G:
            {
                img_channel = img.g;
                shared_tmp_channel = shared_tmp->g;
                break;
            }
        case B:
            {
                img_channel = img.b;
                shared_tmp_channel = shared_tmp->b;
            }
    }
    
    int i, j, p;
    for(i = 0; i < shared_tmp->height; i++)
    {
        for(j = 0; j < shared_tmp->width; j++)
        {
            for(p = id; p < cm.order; p+= N_PROCESSES)
                shared_tmp_channel[array_matrix_index(* shared_tmp, i, j)] += (float)
                    calculate_conv_row(img, img_channel, cm, i, j, p) /
                    cm.divider; 

        }
    }
}

void multiprocess_filter() {

    // N_PROCESSES = get_nprocs(); 
    pid_t pids[N_PROCESSES];

    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_SHARED | MAP_ANON;

    image * shared_tmp = (image *) mmap(NULL, sizeof(image), protection,
            visibility, 0, 0); 

    shared_tmp->width = tmp.width;
    shared_tmp->height = tmp.height;

    shared_tmp->r = (float *) mmap(NULL, sizeof(float) * shared_tmp->width *
            shared_tmp->height, protection, visibility, 0, 0);
    shared_tmp->g = (float *) mmap(NULL, sizeof(float) * shared_tmp->width *
            shared_tmp->height, protection, visibility, 0, 0);
    shared_tmp->b = (float *) mmap(NULL, sizeof(float) * shared_tmp->width *
            shared_tmp->height, protection, visibility, 0, 0);

    /*
    shared_tmp->r = (float *) malloc(sizeof(float) * shared_tmp->width *
            shared_tmp->height);
    shared_tmp->g = (float *) malloc(sizeof(float) * shared_tmp->width *
            shared_tmp->height);
    shared_tmp->b = (float *) malloc(sizeof(float) * shared_tmp->width *
            shared_tmp->height);
    */

    for(int i = 0; i < shared_tmp->width * shared_tmp->height; i++) 
    {
        shared_tmp->r[i] = 0; shared_tmp->g[i] = 0; shared_tmp->b[i] = 0;
    }

    int k;
    for (k = 0; k < N_PROCESSES; ++k) {
        pids[k] = fork();
        if (pids[k] == 0) {
            proc_conv(R, k, shared_tmp);
            proc_conv(G, k, shared_tmp);
            proc_conv(B, k, shared_tmp);
            exit(0);
        }
    }

    for (k = 0; k < N_PROCESSES; ++k)   waitpid(pids[k], NULL, 0);

    tmp = * shared_tmp;
}	
