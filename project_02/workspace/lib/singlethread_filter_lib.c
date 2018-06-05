#include <stdlib.h>
#include <stdint.h>

#include "image_io_lib.h"
#include "convolution_lib.h"
#include "singlethread_filter_lib.h"

typedef enum {R, G, B} channel;

void calculate_conv(channel ch);
    
void singlethread_filter()
{
    calculate_conv(R);
    calculate_conv(G);
    calculate_conv(B);
}

void calculate_conv(channel ch)
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

    for(int row = 0; row < img.height; row++)
    {
        for(int column = 0; column < img.width; column++)
        {
            for(int cm_row = 0; cm_row < cm.order; cm_row++)
            {
                tmp_channel[array_matrix_index(tmp, row, column)] +=
                    calculate_conv_row(img, img_channel, cm, row, column,
                            cm_row) / cm.divider; 
            }
        }
    }
}
