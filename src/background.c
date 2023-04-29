/**
 * @file background.c
 * @brief the game loop code.
 * @author the KingsMan team
 * @version 0.3
 * @date Apr 23, 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "menu.h"

/**
 * @brief       Load the background image
 * @param[in,out] b     Pointer to the background structure
 */
void initBack(background *b)
{
    b->img = IMG_Load("../assets/img/background.png");
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
    SDL_Rect camera_pos;
    camera_pos.x = 0;
    camera_pos.y = 0;
}

/**
 * @brief       Display the background image on the screen
 * @param[in]   b       The background structure to be displayed
 * @param[in,out] screen    Pointer to the screen surface
 */
void afficherBack(background b, SDL_Surface *screen)
{
    SDL_BlitSurface(b.img, &b.img_size, screen, &b.img_pos);
}

/**
 * @brief       Load the music for the game level 1
 * @param[in,out] music   Pointer to the music structure
 */
void musicLoad1(Mix_Music *music)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music = Mix_LoadMUS("../assets/audio/music.mp3");
    if (music == NULL)
    {
        printf("unable to load music Error: %s.\n", Mix_GetError());
        return;
    }
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
}

/**
 * @brief       Scroll the background image in a given direction
 * @param[in,out] b       Pointer to the background position structure
 * @param[in]   direction   The direction to scroll (0 = right, 1 = left, 2 = up, 3 = down)
 * @param[in]   dx      The amount of horizontal scrolling
 * @param[in]   dy      The amount of vertical scrolling
 */
void scrolling(SDL_Rect *b, int direction, int dx, int dy)
{
    if (direction == 0)
    {
        b->x += dx;
    }
    else if (direction == 1)
    {
        b->x -= dx;
    }
    else if (direction == 2 && b->y > 0)
    {
        b->y -= dy;
    }
    else if (direction == 3 && b->y < (SCREEN_H - b->h))
    {
        b->y += dy;
    }
}

/**
 * @brief       Load the image for game level 1 background
 * @param[in,out] img     Pointer to the image structure
 */
void backgroundLoad_lvl1(image *img)
{
    img->filename = "../assets/img/ottoman.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load background Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = (img->img->w) / 5;
    img->img_size.h = (img->img->h);
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}

/**
 * @brief       Draw the image for game level 1 background on the screen
 * @param[in,out] screen    Pointer to the screen surface
 * @param[in]   img
 */

/**

Loads a specific image for level 1 background.
@param img a pointer to the image structure to be filled with the image data
*/
void backgroundLoad_lvl1(image *img)
{
    img->filename = "../assets/img/ottoman.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load background Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = (img->img->w) / 5;
    img->img_size.h = (img->img->h);
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}
/**

Draws the level 1 background image on the screen.
@param screen the SDL_Surface to which the image is to be drawn
@param img a pointer to the image structure to be drawn
*/
void backgroundDraw_lvl1(SDL_Surface *screen, image *img)
{
    SDL_BlitSurface(img->img, &img->img_size, screen, &img->img_pos);
}
/**

Animates the level 1 background image on the screen.
@param screen the SDL_Surface to which the image is to be animated
@param img a pointer to the image structure to be animated
*/
void backgroundAnimate(SDL_Surface *screen, image *img)
{
    int frame = 0;
    Uint32 last_time = 0;
    Uint32 current_time = SDL_GetTicks();
    if (current_time > last_time + 200)
    {
        frame++;
        if (frame >= 5)
        {
            frame = 0;
        }
        img->img_size.x = frame * (img->img->w / 5);
        last_time = current_time;
    }
    backgroundDraw_lvl1(screen, img);
}
/**

Loads a generic background image.
@param img a pointer to the image structure to be filled with the image data
*/
void backgroundLoad(image *img)
{
    img->filename = "../assets/img/sandglass5.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load background Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = (img->img->w) / 5;
    img->img_size.h = (img->img->h);
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}
/**

Draws the generic background image on the screen.
@param screen the SDL_Surface to which the image is to be drawn
@param img a pointer to the image structure to be drawn
*/
void backgroundDraw(SDL_Surface *screen, image *img)
{
    SDL_BlitSurface(img->img, &img->img_size, screen, &img->img_pos);
}

/**

Animates the background image on the screen by changing its position.
@param screen the SDL_Surface to which the image is to be animated
@param img a pointer to the image structure to be animated
*/
void backgroundAnimate(SDL_Surface *screen, image *img)
{
    static int frame = 0;
    static Uint32 last_time = 0;
    Uint32 current_time = SDL_GetTicks();
    if (current_time > last_time + 200)
    {
        frame++;
        if (frame >= 5)
        {
            frame = 0;
        }
        img->img_size.x = frame * (img->img->w / 5);
        last_time = current_time;
    }
    backgroundDraw_lvl1(screen, img);
}
/**

Loads a generic background image and fills the image structure with its data.
@param img a pointer to the image structure to be filled with the image data
*/
void backgroundLoad(image *img)
{
    img->filename = "../assets/img/sandglass5.png";
    img->img = IMG_Load(img->filename);
    if (img->img == NULL)
    {
        printf("unable to load background Error: %s.\n", IMG_GetError());
        return;
    }
    img->img_size.x = 0;
    img->img_size.y = 0;
    img->img_size.w = (img->img->w) / 5;
    img->img_size.h = (img->img->h);
    img->img_pos.x = 0;
    img->img_pos.y = 0;
}
/**

Draws the background image onto the screen.
@param screen the SDL_Surface onto which the image is to be drawn
@param img a pointer to the image structure to be drawn
*/
void backgroundDraw(SDL_Surface *screen, image *img)
{
    SDL_BlitSurface(img->img, &img->img_size, screen, &img->img_pos);
}
/**

Animates the background image on the screen by changing its position.
@param screen the SDL_Surface to which the image is to be animated
@param img a pointer to the image structure to be animated
*/
void backgroundAnimate2(SDL_Surface *screen, image *img)
{
    static int frame = 0;
    static Uint32 last_time = 0;
    Uint32 current_time = SDL_GetTicks();
    if (current_time > last_time + 200)
    {
        frame++;
        if (frame >= 5)
        {
            frame = 0;
        }
        img->img_size.x = frame * (img->img->w / 5);
        last_time = current_time;
    }
    backgroundDraw_lvl1(screen, img);
}
/**

Saves score information to a file.
@param s a ScoreInfo structure containing the score information to be saved
@param fileName the name of the file to which the score information is to be saved
*/
void saveScore(ScoreInfo s, char *fileName)
{
    FILE *file = fopen(fileName, "a");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    fprintf(file, "%d %d %s\n", s.score, s.temps, s.playerName);
    fclose(file);
}
/**

Loads the best three scores from a file and sorts them based on score and time.

@param filename the name of the file from which the scores are to be loaded

@param trois an array of three ScoreInfo structures to be filled with the best scores
*/
void bestScore(char *filename, ScoreInfo trois[])
{
    SDL_Rect scorePosition[3];
    SDL_Surface *scoreSurface[3];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    int i = 0;
    ScoreInfo s;

    while (fscanf(file, "%d %d %s\n", &s.score, &s.temps, s.playerName) == 3)
    {
        trois[i] = s;
        i++;
        if (i == 3)
        {
            break;
        }
    }

    fclose(file);

    int j;
    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (trois[j].score > trois[i].score || (trois[j].score == trois[i].score && trois[j].temps < trois[i].temps))
            {
                ScoreInfo tmp = trois[i];
                trois[i] = trois[j];
                trois[j] = tmp;
            }
        }
    }

    TTF_Font *font = TTF_OpenFont("../assets/font/test.ttf", 20);
    if (font == NULL)
    {
        printf("unable to load font Error: %s.\n", TTF_GetError());
        return;
    }

    SDL_Color color = {255, 255, 255}; // red, green, blue

    char ch[50];
}

/**

Displays the best three scores onto the screen.
@param SCREEN_H the SDL_Surface onto which the scores are to be displayed
@param t an array of three ScoreInfo structures containing the best scores to be displayed
*/
void afficherBest(SDL_Surface *SCREEN_H, ScoreInfo t[])
{
    SDL_BlitSurface(scoreSurface[0], NULL, screen, &scorePosition[0]);
}
/**

Frees the memory allocated to a music file and closes the audio device.
@param music a pointer to the Mix_Music structure to be freed
*/
void musicFree1(Mix_Music *music)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
