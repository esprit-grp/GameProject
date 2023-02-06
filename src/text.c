// librairies
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "texte.h"
//released memory at each Foix we leave a course
void iniTexte(Text *A )
{
    A->position.x=0;
    A->position.y=0;
    //color 
    A->color.r=0;
    A->color.g=0;
    A->color.b=0;

    A->font = TTF_OpenFont("arial.ttf", 30);
}
void freeTexte(Text A)
{
    TTF_CloseFont(A.font);
}
void displayText(Text t ,SDL_Surface *screen)
{
  t.surfaceTexte = TTF_CreateText_Solid(t.font , "------" ; t.textColor);
  SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position );
}