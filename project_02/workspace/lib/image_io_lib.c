#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>

#include "image_io_lib.h"

image open_image(char *nome_do_arquivo) {
    FIBITMAP *bitmapIn;
    int x, y;
    RGBQUAD color;
    image I;

    bitmapIn = FreeImage_Load(FIF_JPEG, nome_do_arquivo, 0);

    if (bitmapIn == 0) {
        printf("Erro! Nao achei arquivo - %s\n", nome_do_arquivo);
    } else {
        printf("Arquivo lido corretamente!\n");
    }

    x = FreeImage_GetWidth(bitmapIn);
    y = FreeImage_GetHeight(bitmapIn);

    I.width = x;
    I.height = y;
    I.r = malloc(sizeof(float) * x * y);
    I.g = malloc(sizeof(float) * x * y);
    I.b = malloc(sizeof(float) * x * y);

    for (int i=0; i<x; i++) {
        for (int j=0; j <y; j++) {
            int idx;
            FreeImage_GetPixelColor(bitmapIn, i, j, &color);

            idx = i + (j*x);

            I.r[idx] = color.rgbRed;
            I.g[idx] = color.rgbGreen;
            I.b[idx] = color.rgbBlue;
        }
    }
    return I;

}

void free_image(image * i)
{
    free(i->r);
    free(i->g);
    free(i->b);
}

void save_image(char *nome_do_arquivo, image *I) {
    FIBITMAP *bitmapOut;
    RGBQUAD color;

    printf("Salvando imagem %d por %d...\n", I->width, I->height);
    bitmapOut = FreeImage_Allocate(I->width, I->height, 24, 0, 0, 0);

    for (int i=0; i<I->width; i++) {
        for (int j=0; j<I->height; j++) {
            int idx;

            idx = i + (j*I->width);
            color.rgbRed = I->r[idx];
            color.rgbGreen = I->g[idx];
            color.rgbBlue = I->b[idx];

            FreeImage_SetPixelColor(bitmapOut, i, j, &color);
        }
    }

    FreeImage_Save(FIF_JPEG, bitmapOut, nome_do_arquivo, JPEG_DEFAULT);
}
