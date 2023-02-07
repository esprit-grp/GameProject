#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/image.h"

// load the images
void imageLoad_background(image *img)
{
    img->filename = "../assets/img/background.bmp";
    img->img = SDL_LoadBMP(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load background Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_pos.x = 0;
    img->img_pos.y = 0;
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = SCREEN_W;
    img->img_size.h = SCREEN_H;
}

void imageLoad_playbutton(image *img)
{
    img->filename = "../assets/img/play.bmp";
    img->img = SDL_LoadBMP(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load play button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = 238;
    img->img_size.h = 58;
    img->img_pos.x = ((SCREEN_W - img->img_size.w) / 2);
    img->img_pos.y = ((SCREEN_W - img->img_size.h) / 3);
}

void imageLoad_settingsbutton(image *img)
{
    img->filename = "../assets/img/settings.bmp";
    img->img = SDL_LoadBMP(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load settings button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = 237;
    img->img_size.h = 58;
    img->img_pos.x = ((SCREEN_W - img->img_size.w) / 2);
    img->img_pos.y = ((SCREEN_W - img->img_size.h) / 3);
}

void imageLoad_quitbutton(image *img)

{
    img->filename = "../assets/img/quit.bmp";
    img->img = SDL_LoadBMP(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load quit button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = 236;
    img->img_size.h = 55;
    img->img_pos.x = ((SCREEN_W - img->img_size.w) / 2);
    img->img_pos.y = ((SCREEN_W - img->img_size.h) / 3);
}

// draw the images
void imageDraw_background(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}
void imageDraw_playbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, NULL, screen, &img.img_pos);
}

void imageDraw_settingsbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, NULL, screen, &img.img_pos);
}

void imageDraw_quitbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, NULL, screen, &img.img_pos);
}

// free the images
void imageFree_background(image img)
{
    SDL_FreeSurface(img.img);
}