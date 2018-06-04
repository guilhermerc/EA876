#include <stdio.h>
#include <stdlib.h>

#include "image_io_lib.h"
#include "convolution_lib.h"

int main(int argc, char ** argv)
{
        image img = open_image("tests/theo.jpg");
        image tmp;
        tmp.width = img.width;
        tmp.height = img.height;
        
        tmp.r = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        tmp.g = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        tmp.b = (float *) malloc(sizeof(float) * tmp.width * tmp.height);
        for(int i = 0; i < tmp.width * tmp.height; i++) 
        {
            tmp.r[i] = 0;
            tmp.g[i] = img.g[i];
            tmp.b[i] = img.b[i];
        }
        conv_matrix cm;
        cm.order = 20; cm.divider = cm.order * cm.order;

        cm.matrix = malloc(sizeof(float *) * cm.order);
        for(int i = 0; i < cm.order; i ++)
            cm.matrix[i] = malloc(sizeof(float) * cm.order);

        for(int i = 0; i < cm.order; i++)
        {
            for(int j = 0; j < cm.order; j++) cm.matrix[i][j] = 1;
        }

        /* 
         
        for(int i = 0; i < img.height; i++)
        {
            for(int j = 0; j < img.height; j++)
                printf("%.1f\t", img.r[array_matrix_index(img, i, j)]);
            printf("\n");
        }

        printf("-------------------------------------------------------------- \n"); 

        for(int i = 0; i < tmp.height; i++)
        {
            for(int j = 0; j < tmp.height; j++)
                printf("T:%.1f\t", tmp.r[array_matrix_index(tmp, i, j)]);
            printf("\n");
        }

        printf("-------------------------------------------------------------- \n"); 

        */

        double sum = 0.0;
        for(int i = 0; i < img.height; i++)
        {
            for(int j = 0; j < img.width; j++)
            {
                for(int k = 0; k < cm.order; k++)
                    sum += calculate_conv_row(img, img.r, cm, i, j, k); 
                tmp.r[array_matrix_index(tmp, i, j)] = (float) sum / cm.divider;
                sum = 0.0;
                for(int k = 0; k < cm.order; k++)
                    sum += calculate_conv_row(img, img.g, cm, i, j, k); 
                tmp.g[array_matrix_index(tmp, i, j)] = (float) sum / cm.divider;
                sum = 0.0;
                for(int k = 0; k < cm.order; k++)
                    sum += calculate_conv_row(img, img.b, cm, i, j, k); 
                tmp.b[array_matrix_index(tmp, i, j)] = (float) sum / cm.divider;
                sum = 0.0;
            }
        }
       
        /*
         *
        printf("-------------------------------------------------------------- \n"); 

        for(int i = 0; i < tmp.height; i++)
        {
            for(int j = 0; j < tmp.height; j++)
                printf("T:%.1f\t", tmp.r[array_matrix_index(tmp, i, j)]);
            printf("\n");
        }

        printf("-------------------------------------------------------------- \n"); 

        for(int i = 0; i < img.height; i++)
        {
            for(int j = 0; j < img.height; j++)
                printf("I:%.1f\t", img.r[array_matrix_index(img, i, j)]);
            printf("\n");
        }

        */

        save_image("aesthetics_vaporwave-out.jpg", &tmp);
	free_image(&tmp);
        free_image(&img);
        return 0;
}
