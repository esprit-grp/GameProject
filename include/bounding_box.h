#ifndef _BOUNDING_BOX_H_
#define _BOUNDING_BOX_H_
#include <SDL/SDL.h>

int in_bounds(SDL_Rect x1,SDL_Rect x2);
int collision(SDL_Rect x1,SDL_Rect x2);

#endif
