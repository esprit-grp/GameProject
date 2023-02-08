#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/image.h"

spacing = 14; // spacing between the buttons (px)

// load the images
void imageLoad_background(image *img)
{
    img->filename = "../assets/img/background.png";
    img->img = IMG_Load(img->filename);
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
    img->filename = "../assets/img/playbutton.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load play button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = 400;
}

void imageLoad_settingsbutton(image *img)
{
    img->filename = "../assets/img/menu.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load settings button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W - img->img_size.w) / 2) - (img->img_size.w / 2);
    img->img_pos.y = 400 + img->img_size.h + spacing;
}

void imageLoad_quitbutton(image *img)
{
    img->filename = "../assets/img/exit.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load quit button Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W - img->img_size.w) / 2) - (img->img_size.w / 2);
    img->img_pos.y = 400 + img->img_size.h * 2 + spacing * 2;
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