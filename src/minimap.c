/**
 * @file minimap.c
 * @brief Minimap code.
 * @author Malek Hammami
 */

#include "minimap.h"

/**
 * @brief Initializes the minimap by setting its coordinates, size, image, and the surface it will be drawn on.
 * @param m A pointer to a minimap structure.
 */
void initmap(minimap *m)
{
    m->x = (1280 / 2) - 125;
    m->y = 0;
    m->largeur = 250;
    m->hauteur = 180;
    m->image = IMG_Load("minimap.png");
    m->carte = SDL_CreateRGBSurface(0, m->largeur, m->hauteur, 32, 0, 0, 0, 0);
    SDL_BlitSurface(m->image, NULL, m->carte, NULL);
}

/**
 * @brief Displays the minimap on the screen.
 * @param m A minimap structure.
 * @param screen The surface on which the minimap will be displayed.
 */
void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_Rect position;
    position.x = m.x;
    position.y = m.y;
    SDL_BlitSurface(m.carte, NULL, screen, &position);
}

/**
 * @brief Displays the elapsed time in seconds since a given reference time in milliseconds.
 * @param temps The reference time in milliseconds.
 */
void affichertemps(int temps)
{
    int temps_ecoule = SDL_GetTicks() - temps;
    int temps_restant = temps_ecoule % 1000;
    printf("Elapsed time: %d seconds\nRemaining time: %d seconds\n", temps_ecoule, temps_restant);
}

/**
 * @brief Checks if there is a collision between a person and a specified mask.
 * @param p A person structure.
 * @param Masque A mask surface.
 * @return 1 if a collision is detected, 0 otherwise.
 */
int collisionPP(Personne p, SDL_Surface *Masque)
{
    int collision = 0;
    Uint32 *pixels = (Uint32 *)Masque->pixels;
    int x = 0;
    int y = 0;
    for (x = p.x; x < p.x + p.largeur; x++)
    {
        for (y = p.y; y < p.y + p.hauteur; y++)
        {
            Uint32 pixel = pixels[(y * Masque->w) + x];
            if (pixel == 0xFFFFFFFF)
            {
                collision = 1;
            }
        }
    }
    return collision;
}

/**
 * @brief Updates the minimap display.
 * @param m A pointer to a carte structure.
 * The function blits the minimap surface onto the carte image surface and updates the area of the screen where the minimap is located.
 */
void animerMinimap(carte *m)
{

    SDL_Rect position;
    position.x = m->x;
    position.y = m->y;
    SDL_BlitSurface(m->carte, NULL, m->image, &position);
    SDL_UpdateRect(m->image, position.x, position.y, m->largeur, m->hauteur);
}
