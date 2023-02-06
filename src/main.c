// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //for loading images
#include <SDL/SDL_ttf.h>   //for loading fonts
#include <SDL/SDL_mixer.h> //for loading sounds

// including the headers
#include "image.h"

// global variables
SDL_Surface *screen;
image *background;
image *startButton; // TODO: add hover effect
image *settingsButton;
image *exitButton;
int loop = 1;

int main()
{
    // initializing SDL
    if (SDL_Init(SDL_INIT_VIDEO) != -1)
    {
        printf("SDL_Init video Error: %s.\n", SDL_GetError());
        return 1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) != -1)
    {
        printf("SDL_Init audio Error: %s.\n", SDL_GetError());
        return 1;
    }
    if (SDL_Init(SDL_INIT_TIMER) != -1)
    {
        printf("SDL_Init timer Error: %s.\n", SDL_GetError());
        return 1;
    }

    // creating the window
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    image_load(background, "../assets/img/play.png", 0, 0, 0, 0); // var, filename, x, y, w, h
    draw_image(*screen, *background);                             // var, image

    // free memory section
    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
