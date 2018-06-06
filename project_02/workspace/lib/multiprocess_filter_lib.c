#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//#include <sys/sysinfo.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "multiprocess_filter_lib.h"

#include <time.h>

typedef enum {R, G, B} channel;

void proc_conv(channel ch, uint8_t id) 
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
    
    int i, j, p;
    for(i = 0; i < img.height; i++)
    {
        for(j = 0; j < img.width; j++)
        {
            for(p = id; p < cm.order; p+= N_PROCESSES)
                tmp_channel[array_matrix_index(tmp, i, j)] += (float)
                    calculate_conv_row(img, img_channel, cm, i, j, p) /
                    cm.divider; 

        }
    }
}

void multiprocess_filter() {

    // N_PROCESSES = get_nprocs(); 
    pid_t pids[N_PROCESSES];

    int k;
    for (k = 0; k < N_PROCESSES; ++k) {
        pids[k] = fork();
        if (pids[k] == 0) {
            proc_conv(R, k); proc_conv(G, k); proc_conv(B, k);
            exit(0);
        }
    }

    for (k = 0; k < N_PROCESSES; ++k)   waitpid(pids[k], NULL, 0);
}	
