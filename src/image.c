#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"

Image *image_load(const char *filename)
{
    Image *image = (Image *)malloc(sizeof(Image));

    SDL_Surface *surface = IMG_Load(filename);
    if (!surface)
    {
        printf("error: %s\n", IMG_GetError());
    }

    image->width = surface->w;
    image->height = surface->h;
    image->pixels = (Uint32 *)surface->pixels;

    return image;
}

void image_free(Image *image)
{
    free(image);
}

void image_draw(Image *image, int x, int y)
{
    SDL_Surface *screen;
    // Draw the image on the screen
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = image->width;
    rect.h = image->height;
    SDL_BlitSurface((SDL_Surface *)image, NULL, screen, &rect);
}