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

SDL_Surface *screen; // the screen

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

    // loading the images
    Image *background = image_load("/assets/img/background.png");
    Image *button1 = image_load("/assets/img/play.png");
    Image *button2 = image_load("/assets/img/settings.png");
    Image *button3 = image_load("/assets/img/quit.png");

    // drawing the images
    image_draw(background, 0, 0, 640, 480); // x , y , width , height
    image_draw(button1, 125, 200, 50, 50);  // x , y , width , height
    image_draw(button2, 150, 200, 50, 50);  // x , y , width , height
    image_draw(button3, 175, 200, 50, 50);  // x , y , width , height

    // free memory section
    SDL_Delay(5000);
    image_free(background);
    SDL_Quit();
    return 0;
}
