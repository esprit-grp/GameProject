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

SDL_Surface *screen;                   // the screen
Mix_Music *music;                      // the music
Mix_Chunk *sound;                      // the sound
TTF_Font *font;                        // the font
SDL_Color textColor = {255, 255, 255}; // the text color
SDL_Event event;                       // the event
int quit = 0;                          // the quit variable
int score = 0;                         // the score variable
char scoreText[20];                    // the score text
int loop = 1;                          // the loop variable

// inisializing the SDL
int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not in initialize SDL: %s.\n", SDL_GetError());
    }

    // inisializing the screen
    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    Image *image = image_load("/assets/img/test.png");
    image_draw(image, 100, 100);
    image_free(image);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
