#ifndef _ENIGME_FICHIER_H_
#define _ENIGME_FICHIER_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../include/bounding_box.h"
#include <time.h>

typedef struct{
SDL_Surface *bg;
SDL_Surface *question;
SDL_Surface *reponses[4];
SDL_Rect pos[4];
int corr;
SDL_Surface *won;
SDL_Surface *lost;
SDL_Surface *clock[16];
int anim;
}Enigme;


void genererEnigme(Enigme *e,char *nomfichier);
void animerenigme(Enigme * e);
void afficherEnigme(Enigme e, SDL_Surface * screen, int x);
int resolution(Enigme e);


#endif
