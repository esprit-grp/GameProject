#ifndef ENIGMA_H
#define ENIGMA_H

#include <SDL/SDL.h>
//--------------------------------------------------------
typedef struct enigme
{
    char question_text[100];
    char reponse1[50];
    char reponse2[50];
    char reponse3[50];

    SDL_Surface *question;
    SDL_Surface *reponse1;
    SDL_Surface *reponse2;
    SDL_Surface *reponse3;
    SDL_Surface *enigmebackground;

    SDL_Rect position_question;
    SDL_Rect position_reponse1;
    SDL_Rect position_reponse2;
    SDL_Rect position_reponse3;
    SDL_Rect position_enigmebackground;

    SDL_Color color;
    TTF_Font *font;

    SDL_Surface *enigme_surf;

} enigme;

typedef struct personne
{
     int score;
} personne;

void afficherEnigme(enigme e, SDL_Surface *screen);

void genererEnigme(enigme *e, char *filename_question, char *filename_reponse1, char *filename_reponse2, char *filename_reponse3);

void animerEnigme(enigme *e);