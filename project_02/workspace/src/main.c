#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "singlethread_filter_lib.h"
#include "multithread_filter_lib.h"
#include "multiprocess_filter_lib.h"

int main(int argc, char ** argv)
{
        img = open_image("tests/test.jpg");

        tmp.width = img.width;
        tmp.height = img.height;
        
        tmp.r = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        tmp.g = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        tmp.b = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        for(int i = 0; i < tmp.width * tmp.height; i++) 
        {
            tmp.r[i] = 0; tmp.g[i] = 0; tmp.b[i] = 0;
        }

        cm.order = 11; cm.divider = 121;

        cm.matrix = malloc(sizeof(float *) * cm.order);
        for(int i = 0; i < cm.order; i++)
            cm.matrix[i] = malloc(sizeof(float) * cm.order);

        for(int i = 0; i < cm.order; i++)
        {
            for(int j = 0; j < cm.order; j++)
                cm.matrix[i][j] = 1;
        }

        if(argc > 1)
        {
            if(strcmp(argv[1], "-s") == 0)
            {    
                printf("Singlethread mode!\n");
                singlethread_filter();
            }
            else if(strcmp(argv[1], "-t") == 0)
            {
                if(argc > 2)    
                {
                    N_THREADS = atoi(argv[2]);
                    printf("Multithread mode with %d threads!\n", N_THREADS);
                    multithread_filter();
                }
                else
                    printf("Invalid usage. Please, insert the number of threads as a third argument.\n");
            }
            else if(strcmp(argv[1], "-p") == 0)
            {
                if(argc > 2)    
                {
                    N_PROCESSES = atoi(argv[2]);
                    printf("Multiprocess mode with %d processes!\n", N_PROCESSES);
                    multiprocess_filter();
                }
                else
                    printf("Invalid usage. Please, insert the number of processes as a third argument.\n");
            }
        }
        else
            printf("Nothing has been done here\n");

        save_image("filter_test-out.jpg", &tmp);

	//free_image(&tmp);
        free_image(&img);
        return 0;
}
