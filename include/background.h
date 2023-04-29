#ifndef BACKGROUND_H
#define BACKGROUND_H

//#define SCREEN_W 1280
//#define SCREEN_H 720 
#include "menu.h"
//structure du background
typedef struct 
{
    SDL_Rect img_pos;  
    SDL_Rect img_size; 
    SDL_Surface *img;  
    int scrollingSpeed; 
    SDL_Rect camera_pos;
    int direction;
    char *filename;
    posBack1(x = 0, y =(H_imgBack - H_screen)/2, w = W_screen/2, h = H_screen);
    posscreen1(x = 0, y = 0, w = W_screen/2, h = H_screen);
    posBack2(x = 0, y =(H_imgBack - H_screen)/2, w = W_screen/2, h = H_screen);
    posscreen2(x = W, y = 0, w = W_screen/2, h = H_screen);
}background;

typedef struct 
{
    int score;
    int temps;
    char playerName[20];
} ScoreInfo;


void initBack(background* b);
void afficherBack(background b, SDL_Surface *screen);
void scrolling(SDL_Rect* b, int direction, int dx, int dy);
void animerBack(background* b);
void backgroundLoad_lvl1(image *img);
void backgroundDraw_lvl1(SDL_Surface *screen,image *img);
void backgroundAnimate_lvl1(SDL_Surface *screen, image *img);
void backgroundAnimate(SDL_Surface *screen, image *img);
void backgroundLoad(image *img);
void backgroundAnimate2(SDL_Surface *screen, image *img);
void saveScore(ScoreInfo s, char *fileName);
void bestScore(char *filename, ScoreInfo trois[]);
void afficherBest(SDL_Surface *screen, ScoreInfo t[]);

#endif





void playMultiplayer()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("Multiplayer Game",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return;
    }

    // Create SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return;
    }

    // Create player 1 and player 2 surfaces
    SDL_Surface* player1Surface = IMG_Load("../assets/player1.png");
    SDL_Surface* player2Surface = IMG_Load("../assets/player2.png");

    if (player1Surface == NULL || player2Surface == NULL)
    {
        printf("Unable to load player images Error: %s\n", SDL_GetError());
        return;
    }

    // Create textures for player 1 and player 2 surfaces
    SDL_Texture* player1Texture = SDL_CreateTextureFromSurface(renderer, player1Surface);
    SDL_Texture* player2Texture = SDL_CreateTextureFromSurface(renderer, player2Surface);

    if (player1Texture == NULL || player2Texture == NULL)
    {
        printf("Unable to create player textures Error: %s\n", SDL_GetError());
        return;
    }

    // Free player 1 and player 2 surfaces as they are no longer needed
    SDL_FreeSurface(player1Surface);
    SDL_FreeSurface(player2Surface);

    // Split screen into left and right parts
    SDL_Rect leftScreen = {0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT};
    SDL_Rect rightScreen = {SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT};

    // Create player 1 and player 2 rects
    SDL_Rect player1Rect = {100, 100, 50, 50};
    SDL_Rect player2Rect = {SCREEN_WIDTH - 150, 100, 50, 50};

    // Main game loop
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        // Handle events
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear renderer
        SDL_RenderClear(renderer);

        // Draw player 1 and player 2 in their respective parts of the screen
        SDL_RenderCopy(renderer, player1Texture, NULL, &leftScreen);
        SDL_RenderCopy(renderer, player2Texture, NULL, &rightScreen);

        // Draw player 1 and player 2 rects
        SDL_RenderFillRect(renderer, &player1Rect);
        SDL_RenderFillRect(renderer, &player2Rect);

        // Update renderer
        SDL_RenderPresent(renderer);
    }

    // Free resources and quit SDL
    SDL_DestroyTexture(player1Texture);
    SDL_DestroyTexture(player2Texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
