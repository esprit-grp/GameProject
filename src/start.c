#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/menu.h" //! temporarily until i make a universal image.h
#include "../include/start.h"

void imageLoad_lvlmenutitle(image *img)
{
    img->filename = "../assets/img/lvlmenutitle.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load level menu title Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = 50;
}

void imageLoad_lvl1(image *img)
{
    img->filename = "../assets/img/lvl1.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load level 1 button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = 200;
}

void imageDraw_lvlmenutitle(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDraw_lvl1(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}