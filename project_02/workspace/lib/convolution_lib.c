#include <stdint.h>
#include <stdbool.h>

#include "image_io_lib.h"
#include "convolution_lib.h"

typedef struct
{
    int16_t currently_row;
    int16_t currently_column;
} currently_position;

// This function calculates the index of a continuous matrix representation as
// an array, given its correponding (i, j) position.
uint64_t array_matrix_index(image img, uint16_t row, uint16_t column)
{
    uint64_t index = row * img.width + column;	
    return index;
}

// This function calculates a single row of a convolution between two matrices.
// It is assumed that the row passed as an argument is valid
double calculate_conv_row(image img, float * channel, image * tmp, conv_matrix
        cm, uint16_t pixel_row, uint16_t pixel_column, uint16_t cm_row)
{
    // Orthogonal distance from the borders of the convolution matrix to the
    // pixel under calcultation
    uint16_t distance = cm.order / 2;

    // Imagine we superpose the convolution matrix over the image matrix,
    // centering the former matrix in the currently pixel under calculation of
    // the latter. Then, the position (0, 0) of the convolution matrix is
    // correlated to the following position in the image matrix 
    currently_position img_position;
    // The convolution image row never changes in this context, since this
    // function calculates a single row of convolution operation
    img_position.currently_row = pixel_row - distance;
    img_position.currently_column = pixel_column - distance;

    currently_position cm_position;
    // Never changes in this context
    cm_position.currently_row = cm_row;
    cm_position.currently_column = 0;

    double convolution_row_sum = 0.0;
    // Calculates the dot product between the image and the convolution matrix
    // respective rows
    while(cm_position.currently_column < cm.order)
    {
        // If the convolution image position is inside of the image matrix, the
        // the convolution operation is valid. We decided to ignore those cases
        // in the filter aplication. It'll cause a border-effect: fading pixels
        // near to the borders).
        if(img_position.currently_row >= 0 &&
                img_position.currently_column >= 0)
        {
            convolution_row_sum += channel[array_matrix_index(img,
                    img_position.currently_row, img_position.currently_column)]
                    * cm.matrix[cm_position.currently_row][cm_position.currently_column];
        }
        img_position.currently_column++;
        cm_position.currently_column++;
    }
    return convolution_row_sum;
} 

