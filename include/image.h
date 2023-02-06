#ifndef IMAGE_H
#define IMAGE_H

typedef struct
{
    char *filename;    // the filename of the image (url)
    SDL_Rect img_pos;  // the position of the image
    SDL_Rect img_size; // the size of the image
    SDL_Surface *img;  // pointer to the image
} image;

void image_load(image *img, char *filename, int x, int y, int w, int h); // var, filename, x, y, w, h
void draw_image(SDL_Surface *screen, image img);
#endif