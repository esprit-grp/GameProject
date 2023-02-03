#ifndef IMAGE_H
#define IMAGE_H

typedef struct Image
{
    int width;
    int height;
    Uint32 *pixels;
} Image;

Image *image_load(const char *filename);     // loading the image from hard drive
void image_free(Image *image);               // freeing the image from memory
void image_draw(Image *image, int x, int y); // drawing the image on the screen

#endif