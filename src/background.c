#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
#include "menu.h"

void initBack(background* b)
{
    b->img= IMG_Load("../assets/img/background.png");
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


void afficherBack(background b, SDL_Surface *screen)
{
SDL_BlitSurface(b.img, &b.img_size, screen, &b.img_pos);
}


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

void backgroundDraw_lvl1(SDL_Surface *screen, image *img)
{
    SDL_BlitSurface(img->img, &img->img_size, screen, &img->img_pos);
}

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

void backgroundDraw(SDL_Surface *screen, image *img)
{
    SDL_BlitSurface(img->img, &img->img_size, screen, &img->img_pos);
}

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

void afficherBest(SDL_Surface *SCREEN_H, ScoreInfo t[]) 
{ 
        SDL_BlitSurface(scoreSurface[0], NULL, screen, &scorePosition[0]);  
}


void musicFree1(Mix_Music *music)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
