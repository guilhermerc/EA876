#ifndef CONVOLUTION_LIB_H
#define CONVOLUTION_LIB_H

#include <stdint.h>

typedef struct
{
    uint16_t order;
    uint16_t divider;
    float ** matrix;
} conv_matrix;

uint64_t array_matrix_index(image img, uint16_t row, uint16_t column);

double calculate_conv_row(image img, float * channel, conv_matrix cm, uint16_t
        pixel_row, uint16_t pixel_column, uint16_t cm_row);

#endif
