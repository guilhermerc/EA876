#ifndef CONVOLUTION_LIB_H
#define CONVOLUTION_LIB_H

typedef struct
{
    uint16_t order;
    uint16_t divider;
    float ** matrix;
} conv_matrix;

double calculate_conv_row(image img, float * channel, image * tmp, conv_matrix
        cm, uint16_t pixel_row, uint16_t pixel_column, uint16_t cm_row);

#endif
