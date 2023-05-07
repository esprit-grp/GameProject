#ifndef Text_H
#define Text_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "background.h"
#include "constants.h"

typedef struct personnage
{
	int vie;
	float vitesse;
	float acceleration;
	SDL_Rect position_personnage;
	SDL_Rect posSprit;
	SDL_Surface *imgperso;
	float score;
	SDL_Rect pos_score;
	int sens;
	int crouch;
	int up;
	SDL_Rect posrel;
} personnage;

void initPerso(personnage *p); //!< Position of the sprite on the screen.

void afficher_personnage(personnage p, SDL_Surface *ecran); //!< drawing of the sprite on the screen.

void animerPerso(int action, personnage *p);

void deplacerPerso(personnage *p, int action, Uint32 dt);
; //!< Direction of movement (0 for idle, 1 for right, 2 for left).

void Saute(personnage *p, int action);

void vitesse_perso(personnage *p, int action, Uint32 dt); //!< Maximum number of steps before changing direction.

void mis_a_jour(personnage *p, int *action, int *att, int *jum, int *retl, int *retr);

/*......afficher une background......*/
// void init_bg(image *D);
// void afficher(image p,SDL_Surface *ecran);

typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img, image;
	SDL_Rect camera;
} image;

typedef struct
{
	SDL_Surface *bg;
	SDL_Surface *background;
	SDL_Rect camera;
	SDL_Rect pos;
} background;

#endif
