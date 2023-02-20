#ifndef START_H
#define START_H

#define SCREEN_W 1280
#define SCREEN_H 720 // screen height and width

//! LOAD AREA
void imageLoad_lvlmenutitle(image *img);
void imageLoad_lvl1(image *img);

//! DRAW AREA
void imageDraw_lvlmenutitle(SDL_Surface *screen, image img);
void imageDraw_lvl1(SDL_Surface *screen, image img);

#endif