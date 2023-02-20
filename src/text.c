#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../include/text.h"

void textLoad(text *txt)
{
    TTF_Init();
    txt->font = TTF_OpenFont("../assets/font/test.ttf", 20); // font , size
    if (txt->font == NULL)
    {
        printf("unable to load font Error: %s.\n", TTF_GetError());
        return;
    }

    txt->color.r = 255; // red
    txt->color.g = 255; // green
    txt->color.b = 255; // blue

    txt->pos.x = 950; // x position
    txt->pos.y = 700; // y position
}

void textDraw(SDL_Surface *screen, text txt, char *str)
{
    txt.txt = TTF_RenderText_Solid(txt.font, str, txt.color);
    SDL_BlitSurface(txt.txt, NULL, screen, &txt.pos);
    SDL_FreeSurface(txt.txt);
}

void textFree(text txt)
{
    TTF_CloseFont(txt.font);
    TTF_Quit();
}