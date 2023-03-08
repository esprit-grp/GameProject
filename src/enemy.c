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
    e->max_steps = 100;
    e->idle_time = 2000;
    e->x = (SCREEN_W / 2 - (e->img->w / 6) - 96 / 2) + 100; // screen width - (width of img / sprite size) - (width of sprite / 2)
    e->y = (SCREEN_H / 2 - (e->img->h / 3) - 96 / 2) + 100; // screen height - (height of img / sprite size) - (height of sprite / 2)

    e->img_size.x = 0;
    e->img_size.y = 0;
    e->img_size.w = (e->img->w) / 6; // (width of img / sprite frames) :576/6 =96px
    e->img_size.h = (e->img->h) / 3; // (height of img / sprite frames) := 288/3= 96px
    e->img_pos.x = e->x;
    e->img_pos.y = e->y;
}

void drawEnemy(SDL_Surface *screen, enemy e)
{
    SDL_BlitSurface(e.img, &(e.img_size), screen, &(e.img_pos));
}

void animateEnemy(enemy *e, int direction) //! added new parameter dont forget
{
    static int frame = 0; // static variable to track current frame
    int row = 0;
    if (direction == 1)
    {
        row = 0;
    }
    else if (direction == 2)
    {
        row = 1;
    }
    else if (direction == 0)
    {
        row = 2;
    }
    e->img_size.x = frame * e->img_size.w; // set x position based on frame
    e->img_size.y = row * e->img_size.h;   // set y position based on direction

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

void moveEnemy(enemy *e)
{
    if (e->direction == 1)
    { // move right
        animateEnemy(e, 1);
        e->img_pos.x += e->speed;
        if (e->img_pos.x >= e->x + e->max_steps)
        {
            e->img_pos.x = e->x + e->max_steps;
            e->direction = 0;              // change direction to idle
            e->idle_time = SDL_GetTicks(); // start idle time
        }
    }
    else if (e->direction == 2)
    { // move left
        animateEnemy(e, 2);
        e->img_pos.x -= e->speed;
        if (e->img_pos.x <= e->x)
        {
            e->img_pos.x = e->x;
            e->direction = 0;              // change direction to idle
            e->idle_time = SDL_GetTicks(); // start idle time
        }
    }
    else if (e->direction == 0)
    { // idle
        animateEnemy(e, 0);
        Uint32 current_time = SDL_GetTicks();
        if (current_time - e->idle_time >= 2000)
        { // check if idle time is over
            if (e->img_pos.x == e->x)
            {
                e->direction = 1; // change direction to right
            }
            else if (e->img_pos.x == e->x + e->max_steps)
            {
                e->direction = 2; // change direction to left
            }
        }
    }
}