// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //for loading images
#include <SDL/SDL_ttf.h>   //for loading fonts
#include <SDL/SDL_mixer.h> //for loading sounds

// including the headers
#include "../include/menu.h"  //menu header
#include "../include/music.h" //music header
#include "../include/text.h"  //text header
#include "stars.h"

// screen
SDL_Surface *screen;
#define SCREEN_W 1280
#define SCREEN_H 720 // screen height and width
#define STARS_COUNT 10
#define STARS_LAYERS 4
#define DELTA_TIME 16 // 1000ms / 60fps = 16.6666

//* regular -> hovered -> clicked
// images (_C for clicked) (_H for hovered)
image background;
image gametitle;
image playButton;
image playButton_C;
image playButton_H;
image settingsButton;
image settingsButton_C;
image settingsButton_H;
image exitButton;
image exitButton_C;
image exitButton_H;

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

    // loading stars layers
    SDL_Surface *star_images[STARS_LAYERS];
    star_images[0] = IMG_Load("../assets/img/star1.png");
    star_images[1] = IMG_Load("../assets/img/star2.png");
    star_images[2] = IMG_Load("../assets/img/star3.png");
    star_images[3] = IMG_Load("../assets/img/star4.png");

    Star stars[STARS_COUNT];

    for (int i = 0; i < STARS_COUNT; i++)
    {
        int layer = rand() % STARS_LAYERS;
        int x = rand() % SCREEN_W;
        int y = rand() % SCREEN_H;
        int speed = 50 + rand() % 150;
        init_star(&stars[i], star_images[layer], x, y, speed);
    }

    imageLoad_gametitle(&gametitle);

    // loading buttons
    imageLoad_playbutton(&playButton);
    imageLoad_settingsbutton(&settingsButton);
    imageLoad_quitbutton(&exitButton);

    // loading clicked buttons
    imageLoadClicked_playbutton(&playButton_C);
    imageLoadClicked_settingsbutton(&settingsButton_C);
    imageLoadClicked_quitbutton(&exitButton_C);

    // loading hovered buttons
    imageLoadHovered_playbutton(&playButton_H);
    imageLoadHovered_settingsbutton(&settingsButton_H);
    imageLoadHovered_quitbutton(&exitButton_H);

    // loading music
    musicLoad(music);

    // loading text
    textLoad(&score);

    Uint32 last_time = SDL_GetTicks();

    /*
     ********************
     *****GAME LOOP******
     ********************
     */

    while (loop)
    {

        Uint32 current_time = SDL_GetTicks();
        Uint32 delta_time = current_time - last_time;
        last_time = current_time;

        // drawing background and game title
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); // black background

        for (int i = 0; i < STARS_COUNT; i++)
        {
            move_star(&stars[i], delta_time);
            draw_star(screen, &stars[i]);
        }

        imageDraw_gametitle(screen, gametitle);

        // drawing intial buttons
        imageDraw_playbutton(screen, playButton);
        imageDraw_settingsbutton(screen, settingsButton);
        imageDraw_quitbutton(screen, exitButton);

        // drawing text
        textDraw(screen, score, "KingsMan Team, 2023");

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
            imageDrawHovered_playbutton(screen, playButton_H);
        }
        else if (anim_B == 2)
        {
            imageDrawHovered_settingsbutton(screen, settingsButton_H);
        }
        else if (anim_B == 3)
        {
            imageDrawHovered_quitbutton(screen, exitButton_H);
        }

        // checking which button is animated
        isButtonAnimated = anim_B;
        // rereshing the screen
        SDL_Flip(screen);
        SDL_Delay(DELTA_TIME);
    }

    // free memory
    imageFree(background);
    imageFree(playButton);
    imageFree(playButton_C);
    imageFree(playButton_H);
    imageFree(settingsButton);
    imageFree(settingsButton_C);
    imageFree(settingsButton_H);
    imageFree(exitButton);
    imageFree(exitButton_C);
    imageFree(exitButton_H);
    musicFree(music);
    SDL_FreeSurface(star_images[0]);
    SDL_FreeSurface(star_images[1]);
    SDL_FreeSurface(star_images[2]);
    SDL_FreeSurface(star_images[3]);

    SDL_Quit();
    return 0;
}