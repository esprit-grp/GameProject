#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/menu.h" //! temporarily until i make a universal image.h
#include "../include/settings.h"

void imageLoad_sounddown(image *img)
{
    img->filename = "../assets/img/-.png";
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
    img->img_pos.x = 50;
    img->img_pos.y = 180;
}

void imageLoad_soundup(image *img)
{
    img->filename = "../assets/img/+.png";
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
    img->img_pos.x = 980;
    img->img_pos.y = 180;
}

void imageLoad_soundmute(image *img)
{
    img->filename = "../assets/img/mute.png";
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
    img->img_pos.x = 565;
    img->img_pos.y = 180;
}

void imageLoad_fullscreen(image *img)
{
    img->filename = "../assets/img/full.png";
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
    img->img_pos.x = 570;
    img->img_pos.y = 0;
}

void imageLoad_backbutton(image *img)
{
    img->filename = "../assets/img/back.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load back button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 670;
}

void imageLoadHovered_soundmute(image *img)
{
    img->filename = "../assets/img/nomute.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load sound mute hovered button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

void imageLoadHovered_backbutton(image *img)
{
    img->filename = "../assets/img/backh.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load back button hovered Error: %s.\n", IMG_GetError());
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

void imageDraw_backbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDrawHovered_soundmute(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDrawHovered_backbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}