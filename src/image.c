#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"

Image *image_load(const char *filename)
{
    Image *image = (Image *)malloc(sizeof(Image)); // allocating memory for the image

    SDL_Surface *surface = IMG_Load(filename); // loading the image from hard drive
    if (!surface)
    {
        printf("error: %s\n", IMG_GetError()); // error handling
    }

    image->width = surface->w; // setting the width and height of the image
    image->height = surface->h;
    image->pixels = (Uint32 *)surface->pixels; // setting the pixels of the image //TODO: check if this is correct

    return image;
}

void image_free(Image *image) // freeing the image from memory
{
    free(image);
}

void image_draw(Image *image, int x, int y, int w, int h)
{
    SDL_Surface *screen;
    // Draw the image on the screen
    SDL_Rect rect; // creating a rectangle
    rect.x = x;    // setting the x and y coordinates of the rectangle
    rect.y = y;
    rect.w = w; // setting the width and height of the rectangle
    rect.h = h;
    SDL_BlitSurface((SDL_Surface *)image, NULL, screen, &rect); // drawing the image on the screen
}
