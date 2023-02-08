// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //for loading images
#include <SDL/SDL_ttf.h>   //for loading fonts
#include <SDL/SDL_mixer.h> //for loading sounds

// including the headers
#include "../include/image.h"
#include "../include/music.h"

// images
SDL_Surface *screen;
image background;
image playButton;
image settingsButton;
image exitButton;

// music
Mix_Music *music;
Mix_Chunk *FX;

// logic
SDL_Event event;
int loop = 1;
int main()
{
    // initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL_Init Error: %s.\n", SDL_GetError());
        return 1;
    }

    // creating the window
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("Error creating the screen: %s\n", SDL_GetError());
        return 1;
    }

    // loading images
    imageLoad_background(&background);
    imageLoad_playbutton(&playButton);
    imageLoad_settingsbutton(&settingsButton);
    imageLoad_quitbutton(&exitButton);
    // loading music
    musicLoad(music);
    // game loop
    while (loop)
    {
        imageDraw_background(screen, background);
        imageDraw_playbutton(screen, playButton);
        imageDraw_settingsbutton(screen, settingsButton);
        imageDraw_quitbutton(screen, exitButton);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                break;

            default:
                break;
            }
        }

        // refreshing the screen
        SDL_Flip(screen);
    }



// heni changes


int main(int argc, char *argv[]) {
    SDL_Surface *screen;
    SDL_Rect rect;
    SDL_Event event;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Set up the screen
    screen = SDL_SetVideoMode(640, 480, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (screen == NULL) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    // Set the initial position of the character rectangle
    rect.x = 320;
    rect.y = 240;
    rect.w = 40;
    rect.h = 40;

    // Main event loop
    while (1) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            rect.y -= 10;
                            break;
                        case SDLK_DOWN:
                            rect.y += 10;
                            break;
                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_QUIT:
                    return 0;
                default:
                    break;
            }
        }

        // Clear the screen
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        // Draw the character rectangle
        SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 255, 0, 0));

        // Update the screen
        SDL_Flip(screen);
    }
    




















    SDL_Delay(5000);
    SDL_Quit();


    return 0;
}