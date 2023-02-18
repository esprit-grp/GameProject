#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/menu.h"

spacing = 14;    // spacing between the buttons (px)
initial_y = 325; // intitial y pos //!LOCKED

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

void imageLoad_gametitle(image *img)
{
    img->filename = "../assets/img/gametitle.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load game title Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = img->img->w;
    img->img_size.h = img->img->h;
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = 0; //! LOCKED
}

void imageLoad_playbutton(image *img)
{
    img->filename = "../assets/img/start.png";
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
    img->img_pos.y = initial_y;
}

void imageLoad_settingsbutton(image *img)
{
    img->filename = "../assets/img/options.png";
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h + spacing;
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h * 2 + spacing * 2;
}

// load the Clicked images
void imageLoadClicked_playbutton(image *img)
{
    img->filename = "../assets/img/startc.png";
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
    img->img_pos.y = initial_y;
}

void imageLoadClicked_settingsbutton(image *img)
{
    img->filename = "../assets/img/optionsc.png";
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h + spacing;
}

void imageLoadClicked_quitbutton(image *img)
{
    img->filename = "../assets/img/exitc.png";
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h * 2 + spacing * 2;
}

// load the hovered images
void imageLoadHovered_playbutton(image *img)
{
    img->filename = "../assets/img/starth.png";
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
    img->img_pos.y = initial_y;
}

void imageLoadHovered_settingsbutton(image *img)
{
    img->filename = "../assets/img/optionsh.png";
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h + spacing;
}

void imageLoadHovered_quitbutton(image *img)
{
    img->filename = "../assets/img/exith.png";
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
    img->img_pos.x = ((SCREEN_W / 2) - (img->img_size.w / 2));
    img->img_pos.y = initial_y + img->img_size.h * 2 + spacing * 2;
}

// draw the images
void imageDraw_background(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDraw_gametitle(SDL_Surface *screen, image img)
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

// draw the clicked buttons
void imageDrawClicked_playbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}
void imageDrawClicked_settingsbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}

void imageDrawClicked_quitbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, NULL, screen, &img.img_pos);
}

// draw the hovered buttons
void imageDrawHovered_playbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}
void imageDrawHovered_settingsbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, &img.img_size, screen, &img.img_pos);
}
void imageDrawHovered_quitbutton(SDL_Surface *screen, image img)
{
    SDL_BlitSurface(img.img, NULL, screen, &img.img_pos);
}

// free the images
void imageFree(image img)
{
    SDL_FreeSurface(img.img);
}
