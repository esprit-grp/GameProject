#ifndef ENEMY_H
#define ENEMY_H

typedef struct
{
    SDL_Rect img_pos;
    SDL_Rect img_size;
    SDL_Surface *img;
    int direction; // 0 for idle, 1 for right , 2 for left
    float speed;
    int max_steps;
} enemy;

void initEnemy(enemy *e);
void drawEnemy(SDL_Surface *screen, enemy e);
void animateEnemy(enemy *e);
void moveEnemy(enemy *e, float speed);
// TODO : add collision detection

#endif