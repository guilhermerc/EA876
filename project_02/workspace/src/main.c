#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "singlethread_filter_lib.h"
#include "multithread_filter_lib.h"
#include "multiprocess_filter_lib.h"
#include "chronometer_lib.h"

int main(int argc, char ** argv)
{
        img = open_image(argv[1]);

        printf("Arquivo da imagem: %s\n", argv[1]);
        printf("Resolução: %d pixels x %d pixels\n", img.width, img.height);

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

        printf("Tamanho da matriz de convolução: %d x %d\n", cm.order, cm.order);

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
            if(strcmp(argv[2], "-s") == 0)
            {    
                printf("Estratégia: singlethread\n");
                time_measurement(singlethread_filter, NULL);
                //singlethread_filter();
            }
            else if(strcmp(argv[2], "-t") == 0)
            {
                if(argc > 2)    
                {
                    N_THREADS = atoi(argv[3]);
                    printf("Estratégia: multithread (%d threads)\n", N_THREADS);
                    time_measurement(multithread_filter, NULL);
                    //multithread_filter();
                }
                else
                    printf("Invalid usage. Please, insert the number of threads as a fourth argument.\n");
            }
            else if(strcmp(argv[2], "-p") == 0)
            {
                if(argc > 2)    
                {
                    N_PROCESSES = atoi(argv[3]);
                    printf("Estratégia: multiprocesso (%d processos)\n", N_PROCESSES);
                    time_measurement(multiprocess_filter, NULL);
                    //multiprocess_filter();
                }
                else
                    printf("Invalid usage. Please, insert the number of processes as a fourth argument.\n");
            }
        }
        else
            printf("Nothing has been done here\n");
        
        uint8_t size = 0;
        bool found = false;
        for(size = 1; found == false; size++)
        {
            if(argv[1][size] == '\0') found = true;
        }

        argv[1][size - 5] = '\0';

        char output_name[200] = "out/";
        strcat(output_name, argv[1]);
        if(strcmp(argv[2], "-s") == 0)
            strcat(output_name, "-singlethread");
        else if(strcmp(argv[2], "-t") == 0)
        {
            strcat(output_name, "-multithread");
            strcat(output_name, "-"); strcat(output_name, argv[3]);
        }
        else if(strcmp(argv[2], "-p") == 0)
        {
            strcat(output_name, "-multiprocess");
            strcat(output_name, "-"); strcat(output_name, argv[3]);
        }

        strcat(output_name, "-out.jpg");    

        save_image(output_name, &tmp);

	//free_image(&tmp);
        free_image(&img);
        return 0;
}
