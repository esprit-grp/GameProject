#ifndef ENEMY_H
#define ENEMY_H

typedef struct
{
    SDL_Rect img_pos;  // position of the sprite on the screen
    SDL_Rect img_size; // size of the sprite
    SDL_Surface *img;  // pointer to the sprite image
    int direction;     // 0 for idle, 1 for right , 2 for left
    float speed;       // steps per frame
    int max_steps;     // maximum number of steps before changing direction
    int idle_time;     // time when the enemy started idling
    int x;             // position of the enemy in the grid (screen coordinates)
    int y;             // position of the enemy in the grid (screen coordinates)
} enemy;

void initEnemy(enemy *e);
void drawEnemy(SDL_Surface *screen, enemy e);
void animateEnemy(enemy *e, int direction);
void moveEnemy(enemy *e);
int collisionBB(SDL_Rect player, SDL_Rect enemy);

//****************************************************

void initEnemytest(enemy *e);
void drawEnemytest(SDL_Surface *screen, enemy e);
void animateEnemytest(enemy *e, int direction);
void moveEnemytest(enemy *e);

#endif