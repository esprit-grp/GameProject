#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/menu.h" //! temporarily until i make a universal image.h
#include "../include/settings.h"

void imageLoad_sounddown(image *img)
{
    img->filename = "../assets/img/sounddown.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load sound down button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

void imageLoad_soundup(image *img)
{
    img->filename = "../assets/img/soundup.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load sound up button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

void imageLoad_soundmute(image *img)
{
    img->filename = "../assets/img/soundmute.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load sound mute button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

void imageLoad_fullscreen(image *img)
{
    img->filename = "../assets/img/fullscreen.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load fullscreen button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

void imageDraw_sounddown(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDraw_soundup(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDraw_soundmute(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDraw_fullscreen(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}
