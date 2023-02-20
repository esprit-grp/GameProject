#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

#include "../include/stars.h"

void init_star(Star *star, SDL_Surface *image, int x, int y, int speed)
{
    star->image = image;
    star->rect.x = x;
    star->rect.y = y;
    star->rect.w = image->w;
    star->rect.h = image->h;
    star->speed = speed;
}

void move_star(Star *star, int delta_time)
{
    star->rect.x -= star->speed * delta_time / 1000;
    star->rect.y -= star->speed * delta_time / 1000;
    star->rect.w += star->speed * delta_time / 1000;
    star->rect.h += star->speed * delta_time / 1000;
}

void draw_star(SDL_Surface *surface, Star *star)
{
    SDL_BlitSurface(star->image, NULL, surface, &star->rect);
}
