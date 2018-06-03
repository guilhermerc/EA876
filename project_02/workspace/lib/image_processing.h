#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

typedef struct
{
	unsigned int width, height;
	float * r, * g, * b;
} image;

typedef struct
{
	uint16_t order;
        uint16_t divider;
	float ** convm;
} conv_matrix;

image open_image(char *nome_do_arquivo);
void save_image(char *nome_do_arquivo, imagem *I);
void free_image(imagem *i);

#endif
