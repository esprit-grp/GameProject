#ifndef Texte_H
#define Texte_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
    SDL_Surface *surfaceTexte;
    SDL_Rect position;
    TTF_Font *Font;
    SDL_Color textColor;
    char texte [50];
}Text ;

void initText(Text *t);
void freeText(Text A);
void destroyText(Text t, DSL_Surface *screen);
#endif