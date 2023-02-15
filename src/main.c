// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //for loading images
#include <SDL/SDL_ttf.h>   //for loading fonts
#include <SDL/SDL_mixer.h> //for loading sounds

// including the headers
#include "../include/menu.h" //menu header
#include "../include/music.h"
#include "../include/text.h"

// screen
SDL_Surface *screen;

// images (_C for clicked)
image background;
image playButton;
image playButton_C;
image settingsButton;
image settingsButton_C;
image exitButton;
image exitButton_C;

// music
Mix_Music *music;
Mix_Chunk *clickFX;

// text
text score;

// logic
SDL_Event event;
int loop = 1;             // game loop
int anim_B = 0;           // animation for the buttons
int isButtonAnimated = 0; // check if the button animated (to prevent FX spam)
int selectedButton = 0;   // selected button (keyboard)
/*
********************
*****GAME BEGIN*****
********************
*/

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

    // loading background
    imageLoad_background(&background);
    // loading buttons
    imageLoad_playbutton(&playButton);
    imageLoad_settingsbutton(&settingsButton);
    imageLoad_quitbutton(&exitButton);

    // loading clicked buttons
    imageLoadClicked_playbutton(&playButton_C);
    imageLoadClicked_settingsbutton(&settingsButton_C);
    imageLoadClicked_quitbutton(&exitButton_C);

    // loading music
    musicLoad(music);

    // loading text
    textLoad(&score);

    /*
     ********************
     *****GAME LOOP******
     ********************
     */

    while (loop)
    {
        // drawing images
        imageDraw_background(screen, background);
        imageDraw_playbutton(screen, playButton);
        imageDraw_settingsbutton(screen, settingsButton);
        imageDraw_quitbutton(screen, exitButton);

        // drawing text
        textDraw(screen, score, "Score: 0");

        // events
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    loop = 0;
                    break;
                case SDLK_f:
                    SDL_WM_ToggleFullScreen(screen); // TODO Move this to a button NOT A KEY PRESS
                    break;

                // controlling the buttons by arrow keys
                // ! not stable we need to add an arrow or smth to show the selected button
                case SDLK_UP:
                    selectedButton = (selectedButton - 1 + 3) % 3; // do the math here
                    break;
                case SDLK_DOWN:
                    selectedButton = (selectedButton + 1) % 3;
                    break;
                case SDLK_RETURN:
                    switch (selectedButton)
                    {
                    case 0:
                        // start button pressed
                        imageDrawClicked_settingsbutton(screen, settingsButton_C);
                        FXLoad(clickFX);
                        break;
                    case 1:
                        // settings button pressed
                        imageDrawClicked_settingsbutton(screen, settingsButton_C);
                        FXLoad(clickFX);
                        break;
                    case 2:
                        // exit button pressed
                        imageDrawClicked_quitbutton(screen, exitButton_C);
                        FXLoad(clickFX);
                        break;
                    }
                    break;
                default:
                    break;
                }
                break; // this break for preventing the mouse motion event from being triggered

            case SDL_MOUSEMOTION:
                if (event.motion.x >= playButton.img_pos.x && event.motion.x <= playButton.img_pos.x + playButton.img_size.w && event.motion.y >= playButton.img_pos.y && event.motion.y <= playButton.img_pos.y + playButton.img_size.h)
                {
                    if (isButtonAnimated != 1)
                    {
                        anim_B = 1;
                        FXLoad(clickFX);
                    }
                }
                else if (event.motion.x >= settingsButton.img_pos.x && event.motion.x <= settingsButton.img_pos.x + settingsButton.img_size.w && event.motion.y >= settingsButton.img_pos.y && event.motion.y <= settingsButton.img_pos.y + settingsButton.img_size.h)
                {
                    if (isButtonAnimated != 2)
                    {
                        anim_B = 2;
                        FXLoad(clickFX);
                    }
                }
                else if (event.motion.x >= exitButton.img_pos.x && event.motion.x <= exitButton.img_pos.x + exitButton.img_size.w && event.motion.y >= exitButton.img_pos.y && event.motion.y <= exitButton.img_pos.y + exitButton.img_size.h)
                {
                    if (isButtonAnimated != 3)
                    {
                        anim_B = 3;
                        FXLoad(clickFX);
                    }
                }
                else
                {
                    anim_B = 0;
                }
                break;

            case SDL_QUIT: // if the user clicks on the close button
                loop = 0;
                break;
            default:
                break;
            }
        }

        // button animation logic
        if (anim_B == 1)
        {
            imageDrawClicked_playbutton(screen, playButton_C);
        }
        else if (anim_B == 2)
        {
            imageDrawClicked_settingsbutton(screen, settingsButton_C);
        }
        else if (anim_B == 3)
        {
            imageDrawClicked_quitbutton(screen, exitButton_C);
        }

        // rereshing the screen
        SDL_Flip(screen);
        // checking which button is animated
        isButtonAnimated = anim_B;
    }

    // free memory
    imageFree(background);
    imageFree(playButton);
    imageFree(playButton_C);
    imageFree(settingsButton);
    imageFree(settingsButton_C);
    imageFree(exitButton);
    imageFree(exitButton_C);
    musicFree(music);

    SDL_Quit();
    return 0;
}