#include "perso.h"
#include "background.h"
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "constants.h"

/**
 * @file mainperso.c
 * @brief Testing Program.
 * @author C Team
 * @version 0.1
 * @date Apr 01, 2015
 *
 * Testing program for background scrollilng  *
 */
/**
 * @file perso.c
 * @brief Testing Program.
 * @author C Team
 * @version 0.1
 * @date Apr 01, 2015
 *
 * Testing program for background scrollilng  *
 */

/**
 * @brief Initializes an perso.
 *
 * This function loads the perso image, sets initial values for perso properties,
 * and initializes the image position and size.
 *
 * @param p Pointer to the perso structure to be initialized.
 */
void initPerso(personnage *p)
{

	p->sens = 1;
	p->imgperso = IMG_Load("../assets/img/perso.png");
	p->position_personnage.x = 350;
	p->position_personnage.y = 350;

	p->crouch = 0;

	p->vie = 3;
	p->posSprit.x = 0;
	p->posSprit.y = 200;
	p->posSprit.w = 50;
	p->posSprit.h = 100;

	p->up = 0;

	p->score = 0;
	p->pos_score.x = 600;
	p->pos_score.y = 30;

	p->posrel.x = -50;
	p->posrel.y = 0;

	p->vitesse = 0;
	p->acceleration = 0;
}
/**
 * @brief drawing an perso.
 *
 * This function draw the perso image,
 *
 * @param p Pointer to the perso structure to be initialized and screan
 */
void afficher_personnage(personnage p, SDL_Surface *ecran)
{
	SDL_BlitSurface(p.imgperso, &p.posSprit, ecran, &p.position_personnage);
}

/**
 * @brief animating a perso.
 *

 *
 * @param p Pointer to the perso structure to be animated
 */

void animerPerso(int action, personnage *p)
{

	switch (action)
	{

	case 1:

		p->posSprit.y = 1260;
		if (p->crouch == 0)
		{
			p->posSprit.x = p->posSprit.x + 100;
			if (p->posSprit.x >= 450)
				p->posSprit.x = 450;
		}
		else
		{
			p->crouch = 1;
			p->posSprit.x = 0;
		}
		break;
	case 2:
		p->crouch = 0;
		if (p->sens == 1)
		{
			p->posSprit.y = 150;

			if (p->posSprit.x > 900)
			{
				p->posSprit.x = 0;
			}
			else
				p->posSprit.x = p->posSprit.x + 100;
		}
		else if (p->sens == 0)
		{

			p->posSprit.y = 0;

			if (p->posSprit.x > 900)
			{
				p->posSprit.x = 0;
			}
			else
				p->posSprit.x = p->posSprit.x + 100;
		}
		break;

	case 3:
		p->crouch = 0;
		if (p->sens == 1)
		{

			p->posSprit.y = 470;

			if (p->posSprit.x > 1050)
			{
				p->posSprit.x = 0;
			}
			else
				p->posSprit.x = p->posSprit.x + 100;
		}
		else if (p->sens == 0)
		{
			p->posSprit.y = 320;
			if (p->posSprit.x > 1050)
			{
				p->posSprit.x = 0;
			}
			else
				p->posSprit.x = p->posSprit.x + 100;
		}
		break;

	case 4:
		p->crouch = 0;
		p->posSprit.y = 779;

		if (p->posSprit.x >= 1200)
		{
			p->posSprit.x = 0;
		}
		else
			p->posSprit.x = p->posSprit.x + 100;
		break;

	case 5:
		p->crouch = 0;
		p->posSprit.y = 630;

		if (p->posSprit.x >= 1200)
		{
			p->posSprit.x = 0;
		}
		else
			p->posSprit.x = p->posSprit.x + 100;
		break;

	case 6:
		p->posSprit.y = 779;
		p->posSprit.x = 0;
		break;

	case 8:
		p->posSprit.y = 630;
		p->posSprit.x = 0;
		break;

	case 7:
		p->crouch = 0;
		if (p->sens == 1)
		{
			p->posSprit.y = 1420;

			if (p->posSprit.x < 600)
			{
				p->posSprit.x = p->posSprit.x + 100;
			}
			else
			{
				p->vie--;
				SDL_Delay(500);
			}
			if (p->posSprit.x >= 600)
				p->posSprit.x = 0;
		}

		else if (p->sens == 0)
		{

			p->posSprit.y = 1570;

			if (p->posSprit.x < 600)
			{
				p->posSprit.x = p->posSprit.x + 156;
			}
			else
			{
				p->vie--;
				SDL_Delay(500);
			}
			if (p->posSprit.x >= 600)
				p->posSprit.x = 0;
		}
		break;
	}
}
/**
 * @brief moving a perso.
 *

 *
 * @param p Pointer to the perso structure to be moved.
 */
void deplacerPerso(personnage *p, int action, Uint32 dt)
{

	if ((action == 4) && (p->position_personnage.x < 800) && (p->vitesse >= 0))
		p->position_personnage.x += (p->vitesse) * dt;

	if ((action == 5) && (p->position_personnage.x > 30) && (p->vitesse >= 0))
		p->position_personnage.x -= (p->vitesse) * dt;

	if ((action == 7) && (p->position_personnage.x > 30) && (p->position_personnage.x < 800) && (p->vitesse >= 0))
	{
		if (p->sens == 1)
			p->position_personnage.x -= 30;
		if (p->sens == 0)
			p->position_personnage.x += 30;
	}
}

/**
 * @brief accelerating a perso.
 *
 *
 * @param p Pointer to the perso structure to be accelerated.
 */

void vitesse_perso(personnage *p, int action, Uint32 dt)
{

	(p->vitesse) += (p->acceleration) * dt;

	switch (action)
	{
	case 4:
		if ((p->vitesse) < 1)
			p->acceleration += 0.001;
		break;

	case 5:
		if ((p->vitesse) < 1)
			p->acceleration += 0.001;
		break;

	case 6:
		if ((p->vitesse) > 0.1)
			(p->acceleration) -= 0.005;
		break;

	case 8:
		if ((p->vitesse) > 0.1)
			(p->acceleration) -= 0.005;
		break;
	}

	if ((p->vitesse) > 0.5)
		p->vitesse = 0.5;
	if ((p->vitesse) < 0.1)
		p->vitesse = 0.1;
}

void Saute(personnage *p, int action)
{

	if ((p->up == 0) && (p->position_personnage.y > 380))
		p->position_personnage.y -= 70;
	else if ((p->up == 0) && (p->position_personnage.y == 380))
		p->up = 1;

	if ((p->up == 1) && (p->position_personnage.y < 520))
		p->position_personnage.y += 70;
	else if ((p->up == 1) && (p->position_personnage.y == 520))
		p->up = 0;

	if (p->sens == 1)
		p->position_personnage.x += 50;

	if (p->sens == 0)
		p->position_personnage.x -= 50;
}

void mis_a_jour(personnage *p, int *action, int *att, int *jum, int *retl, int *retr)
{

	switch (*action)
	{
	case 1:
		(*jum) = 0;
		(*att) = 0;
		(*retr) = 0;
		(*retl) = 0;
		break;

	case 2:
		(*att) = 0;
		(*retr) = 0;
		(*retl) = 0;
		(*jum)++;

		break;

	case 3:
		(*jum) = 0;
		(*att) = 0;
		(*retr) = 0;
		(*retl) = 0;
		(*action) = 0;
		break;

	case 4:
		(*jum) = 0;
		(*att) = 0;
		(*retr) = 0;
		(*retl) = 0;
		p->sens = 1;

		break;

	case 5:
		(*jum) = 0;
		(*att) = 0;
		(*retr) = 0;
		(*retl) = 0;
		p->sens = 0;

		break;

	case 7:
		(*jum) = 0;
		(*retr) = 0;
		(*retl) = 0;
		(*action) = 0;
		break;

	case 6:
		retr++;
		break;

	case 8:
		retr--;
		break;
	}
}
