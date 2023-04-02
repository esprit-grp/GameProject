#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"

// load the images
void initBack(background* b)
{
    b->filename = "../assets/img/carthage_lvl.png";
    if (b->img == NULL)
    {
        printf("unable to load background error : %s . \n", IMG_GetError());
        return;
    }
	b->img_pos.y = 0;
    	b->img_size.x = 0;
    	b->img_size.y = 0;
    	b->img_size.w = SCREEN_W;
    	b->img_size.h = SCREEN_H;
    // Set up camera position and dimensions
    SDL_Rect camera_pos;
    camera_pos.x = 0;
    camera_pos.y = 0;
   // camera_pos.w = SCREEN_W / screen;
    //camera_pos.h = SCREEN_H / screen;

}


void afficherBack(background b, SDL_Surface *screen)
{
SDL_BlitSurface(b.img, &b.img_size, screen, &b.img_pos);
}
// load the music

void musicLoad1(Mix_Music *music)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music = Mix_LoadMUS("../assets/audio/---------.mp3"); // mp3 file
    if (music == NULL)
    {
        printf("unable to load music Error: %s.\n", Mix_GetError());
        return;
    }
    Mix_PlayMusic(music, -1);            // music, loop (-1 for infinite)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // 2 for half volume, 0 for mute
}


/*
void animerBack(Back* b);
{
// check rain.c
}
*/
/*
void scrolling(SDL_Rect* b, int direction, int dx, int dy) 
{
    if (direction == 0) {
        b->x += dx;
    } else if (direction == 1) {
        b->x -= dx;
    } else if (direction == 2 && b->y > 0) {
        b->y -= dy;
    } else if (direction == 3 && b->y < (SCREEN_H - b->h)) {
        b->y += dy;
    }
}
*/
/*
// Function to scroll the background
void scrolling(SDL_Rect* b, int direction, int dx, int dy) {
    if (direction == 0 && b->x < BACKGROUND_WIDTH - SCREEN_WIDTH) {
        b->x += dx;
    } else if (direction == 1 && b->x > 0) {
        b->x -= dx;
    }
}

int main(int argc, char* argv[]) {
    SDL_Surface* screen = NULL;
    SDL_Surface* background = NULL;
    SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create the window and screen surface
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);

    // Load the background image
    background = SDL_LoadBMP("background.bmp");

    // Main game loop
    bool running = true;
    while (running) {
        // Scroll the background if necessary
        if (posJoueur.x >= SCREEN_WIDTH/2 && posJoueurAbsolue.x < BACKGROUND_WIDTH - joueur.w && directionJoueur == 0) {
            scrolling(&camera, 0, 10, 0);
        } else if (posJoueurAbsolue.x >= BACKGROUND_WIDTH - SCREEN_WIDTH && directionJoueur == 1) {
            scrolling(&camera, 1, 10, 0);
        }

        // Draw the background and player to the screen
        SDL_BlitSurface(background, &camera, screen, NULL);
        SDL_BlitSurface(joueur, NULL, screen, &posJoueur);

        // Update the screen
        SDL_Flip(screen);

        // Check for events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    // Clean up resources
    SDL_FreeSurface(background);
    SDL_Quit();
    return 0;
}
*/



// free the music
void musicFree1(Mix_Music *music)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
