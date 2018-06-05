#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

typedef struct
{
    unsigned int width, height;
    float * r, * g, * b;
} image;

image img, tmp;

image open_image(char *nome_do_arquivo);
void save_image(char *nome_do_arquivo, image *I);
void free_image(image *i);

#endif
