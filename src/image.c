#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"

void image_load(image *img, char *filename, int x, int y, int w, int h)
{
    img->filename = filename; // This sets the image's filename to the given filename parameter.
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("IMG_Load Error: %s.\n", IMG_GetError());
        return;
    }

    // This code sets the image's position, size, and width and height.
    img->img_pos.x = x;               // This sets the image position's x coordinate to the given x parameter.
    img->img_pos.y = y;               // This sets the image position's y coordinate to the given y parameter.
    img->img_size.w = w;              // This sets the image size's width to the given w parameter.
    img->img_size.h = h;              // This sets the image size's height to the given h parameter.
    img->img_pos.w = img->img_size.w; // This sets the image's width to the image size's width.
    img->img_pos.h = img->img_size.h; // This sets the image's height to the image size's height.
}

void draw_image(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}