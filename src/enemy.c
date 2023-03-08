#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "constants.h"
#include "enemy.h"

void initEnemy(enemy *e)
{
    e->img = IMG_Load("../assets/img/enemyrun.png");
    if (e->img == NULL)
    {
        printf("Error loading enemy image: %s\n", SDL_GetError());
    }
    e->direction = 1;
    e->speed = 1;
    e->max_steps = 30;

    e->img_size.x = 0;
    e->img_size.y = 0;
    e->img_size.w = (e->img->w) / 6; // (width of img / sprite size) :576/6 =96px
    e->img_size.h = e->img->h;       // image height = 96px
    e->img_pos.x = SCREEN_W / 2;
    e->img_pos.y = SCREEN_H / 2;
}

void drawEnemy(SDL_Surface *screen, enemy e)
{
    SDL_BlitSurface(e.img, &(e.img_size), screen, &(e.img_pos));
}

void animateEnemy(enemy *e)
{
    static int frame = 0;                  // static variable to track current frame
    e->img_size.x = frame * e->img_size.w; // set x position based on frame

    Uint32 current_time = SDL_GetTicks();
    static Uint32 last_time = 0;
    Uint32 delta_time = current_time - last_time;
    if (delta_time >= 100)
    {            // add a delay of 100 milliseconds between frames
        frame++; // increment frame counter
        if (frame >= 6)
        { // if we've reached the end of the sprite sheet, wrap around
            frame = 0;
        }
        last_time = current_time;
    }
}

void moveEnemy(enemy *e, float speed)
{
    if (e->direction == 1)
    { // move right
        e->img_pos.x += (int)(speed + e->speed);
        if (e->img_pos.x >= e->max_steps)
        {
            e->img_pos.x = e->max_steps;
            e->direction = 2; // change direction to left
        }
    }
    else
    { // move left
        e->img_pos.x -= (int)(speed + e->speed);
        if (e->img_pos.x <= 0)
        {
            e->img_pos.x = 0;
            e->direction = 1; // change direction to right
        }
    }
}
