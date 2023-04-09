#include "enigme.h"

#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include <SDL/SDL_ttf.h>



void afficherEnigme(Enigme e, SDL_Surface *screen, TTF_Font *font, SDL_Color textColor) 

{

    SDL_Surface *questionSurface = TTF_RenderText_Solid(font, e.question, textColor);

    SDL_Surface *reponseSurface = TTF_RenderText_Solid(font, e.reponse, textColor);

    SDL_Rect questionLocation = { 0, 0, 0 };

    SDL_Rect reponseLocation = { 0, 0, 0 };

    questionLocation.x = (screen->w - questionSurface->w) / 2;

    questionLocation.y = (screen->h - questionSurface->h) / 2 + 50;

    reponseLocation.x = (screen->w - reponseSurface->w) / 2;

    reponseLocation.y = (screen->h - reponseSurface->h) / 2 + 50;

    SDL_BlitSurface(questionSurface, NULL, screen, &questionLocation);

    SDL_BlitSurface(reponseSurface, NULL, screen, &reponseLocation);

    SDL_FreeSurface(questionSurface);

    SDL_FreeSurface(reponseSurface);

  //  SDL_Flip(screen);

}







void genererEnigme(Enigme *p, char *nomfichier) {



    srand(time(NULL));

    int num_lines = 0, i;

    char ligne[100];

    FILE *fp = fopen(nomfichier, "r");

    if (fp == NULL) {

        printf("Impossible d'ouvrir le fichier\n");

        return;

    }

    while (fgets(ligne, 100, fp) != NULL) {

        num_lines++;

    }

   fclose(fp);

    int random_index = rand() % (num_lines / 2) * 2;

    fp = fopen(nomfichier, "r");

    if (fp == NULL) {

        printf("Impossible d'ouvrir le fichier\n");

        return;

    }

    for (i = 0; i < random_index; i++) {

        fgets(ligne, 100, fp);

    }

    fgets(p->question, 100, fp);

    fgets(p->reponse, 100, fp);

    fclose(fp);

}



void animerEnigme(Enigme *e, SDL_Surface *screen) {

    if (e == NULL || screen == NULL) {

        return;

    }

    SDL_Rect srcRect = {e->currentFrame * 253, 0, 253, 253};

    SDL_Rect dstRect = {100, 100, e->frameWidth, e->frameHeight};

    SDL_BlitSurface(e->spriteSheet, &srcRect, screen, &dstRect);

    e->currentFrame = (e->currentFrame + 1) % e->totalFrames;

}







