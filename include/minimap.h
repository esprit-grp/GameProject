/**
 * @file minimap.h
 * @brief Header file for the minimap functionality.
 * @author Malek Hammami
 */

#ifndef MINIMAP_H
#define MINIMAP_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
 * @brief Structure representing a map.
 */
typedef struct carte
{
    int x;              /**< x coordinate of the map */
    int y;              /**< y coordinate of the map */
    int largeur;        /**< width of the map */
    int hauteur;        /**< height of the map */
    SDL_Surface *image; /**< SDL_Surface containing the map image */
    SDL_Surface *carte; /**< SDL_Surface containing the map surface */
} carte;

/**
 * @brief Structure representing a minimap.
 */
typedef struct minimap
{
    int x;              /**< x coordinate of the minimap */
    int y;              /**< y coordinate of the minimap */
    int largeur;        /**< width of the minimap */
    int hauteur;        /**< height of the minimap */
    SDL_Surface *image; /**< SDL_Surface containing the minimap image */
    SDL_Surface *carte; /**< SDL_Surface containing the minimap surface */
} minimap;

/**
 * @brief Structure representing a person.
 */
typedef struct Personne
{
    int x;       /**< x coordinate of the person */
    int y;       /**< y coordinate of the person */
    int largeur; /**< width of the person */
    int hauteur; /**< height of the person */
} Personne;

/**
 * @brief Initializes the minimap by defining its coordinates, size, image, and the surface on which it will be drawn.
 *
 * @param m A pointer to a minimap structure.
 */
void initmap(minimap *m);

/**
 * @brief Displays the minimap on the screen.
 *
 * @param m The minimap structure.
 * @param screen The surface of the screen on which the minimap will be displayed.
 */
void afficherminimap(minimap m, SDL_Surface *screen);

/**
 * @brief Displays the time elapsed since a given moment in milliseconds.
 *
 * @param temps The reference time in milliseconds.
 */
void affichertemps(int temps);

/**
 * @brief Checks for collision between the person and the specified mask.
 *
 * @param p The person structure.
 * @param Masque The mask surface.
 * @return 1 if a collision is detected, 0 otherwise.
 */
int collisionPP(Personne p, SDL_Surface *Masque);

/**
 * @brief Updates the display of the minimap.
 *
 * @param m A pointer to a carte structure.
 */
void animerMinimap(carte *m);

#endif // MINIMAP_H
