#ifndef STARS_H
#define STARS_H

typedef struct
{
    SDL_Surface *image;
    SDL_Rect rect;
    int speed;
} Star;

void init_star(Star *star, SDL_Surface *image, int x, int y, int speed);
void move_star(Star *star, int delta_time);
void draw_star(SDL_Surface *surface, Star *star);

#endif /* STARS_H */