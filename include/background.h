#ifndef BACKGROUND_H
#define BACKGROUND_H
/**
 * @file background.h.c
 * @brief the game loop code.
 * @author the KingsMan team
 * @version 0.3
 * @date Apr 23, 2023
 */

/**

@file background.h
@brief Defines the background struct and related functions.
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/menu.h"
#include "constants.h"
#include "menu.h"


/**

@brief The struct representing a background image in the game.
This struct contains information about the position and size of the background image,
the SDL_Surface pointer to the actual image, the scrolling speed, the camera position,
the scrolling direction and the filename of the image file.
*/
typedef struct
{
        SDL_Rect img_pos;    //< The position of the background image. */
        SDL_Rect img_size;   //< The size of the background image. */
        SDL_Surface *img;    //< The SDL_Surface pointer to the background image. */
        int scrollingSpeed;  //< The scrolling speed of the background image. */
        SDL_Rect camera_pos; //< The position of the camera. */
        int direction;       //< The direction of the scrolling. */
        char *filename;      /**< The filename of the image file. */
} background;


/**

@struct ScoreInfo
@brief Struct representing the player's score and name.
*/
typedef struct
{
        int score;
         int temps;  
         char playerName[20]; 
} ScoreInfo;
/**

@brief Initializes a background struct.
@param b Pointer to the background struct to be initialized.
*/
void initBack(background *b);
/**

@brief Displays a background image on the given screen.
@param b The background struct containing the image to be displayed.
@param screen The screen surface on which the image should be displayed.
*/
void afficherBack(background b, SDL_Surface *screen);
/**

@brief Scrolls the background image in the given direction by the given amount.
@param b Pointer to the background struct representing the image to be scrolled.
@param direction Direction of the scrolling (1 for right, -1 for left).
@param dx Amount of horizontal scrolling.
@param dy Amount of vertical scrolling.
*/
void scrolling(SDL_Rect *b, int direction, int dx, int dy);
/**

@brief Animates the background image by scrolling it.
@param b Pointer to the background struct representing the image to be animated.
*/
void animerBack(background *b);
/**

@brief Loads the level 1 background image into the given image struct.
@param img Pointer to the image struct to be loaded with the background image.
*/
void backgroundLoad_lvl1(image *img);
/**

@brief Draws the level 1 background image on the given screen.
@param screen The screen surface on which the image should be drawn.
@param img Pointer to the image struct containing the background image to be drawn.
*/
void backgroundDraw_lvl1(SDL_Surface *screen, image *img);
/**

@brief Animates the level 1 background image by scrolling it.
@param screen The screen surface on which the image should be animated.
@param img Pointer to the image struct containing the background image to be animated.
*/
void backgroundAnimate_lvl1(SDL_Surface *screen, image *img);
/**

@brief Animates the background image by scrolling it.
@param screen The screen surface on which the image should be animated.
@param img Pointer to the image struct containing the background image to be animated.
*/
void backgroundAnimate(SDL_Surface *screen, image *img);
/**

@brief Loads the background image into the given image struct.
@param img Pointer to the image struct to be loaded with the background image.
*/
void backgroundLoad(image *img);
/**

@brief Animates the background image by scrolling it.
@param screen The screen surface on which the image should be animated.
@param img Pointer to the image struct containing the background image to be animated.
*/
void backgroundAnimate2(SDL_Surface *screen, image *img);
/**

@brief Saves the given score information to a file.
@param s The score information struct to be saved.
@param fileName The name of the file to which the score information should be written.
*/
void saveScore(ScoreInfo s, char *fileName);
/**

@brief Reads the top three scores from the given file into an array of ScoreInfo structs.
@param filename The name of the file from which the scores should be read.
@param trois Pointer to the array of ScoreInfo structs to be filled with the scores.
*/
void bestScore(char *filename, ScoreInfo trois[]);
/**

@brief Displays the top three scores on the given screen.
@param screen The screen surface on which the scores should be displayed.
@param t The array of ScoreInfo structs containing the top three scores.
*/
void afficherBest(SDL_Surface *screen, ScoreInfo t[]);
#endif
