/**
 * @file enemy.c
 * @brief enemy implemetation en C.
 * @author Aymen Hmani
 */
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../include/constants.h"
#include "../include/enemy.h"

/**
 * @brief Initializes an enemy.
 *
 * This function loads the enemy image, sets initial values for enemy properties,
 * and initializes the image position and size.
 *
 * @param e Pointer to the enemy structure to be initialized.
 */
void initEnemy(enemy *e)
{
    e->img = IMG_Load("../assets/img/enemyrun.png");
    if (e->img == NULL)
    {
        printf("Error loading enemy image: %s\n", SDL_GetError());
    }
    e->direction = 1;
    e->speed = 1;
    e->max_steps = 300;
    e->idle_time = 2000;
    e->x = (SCREEN_W / 2 - (e->img->w / 6) - 96 / 2) - 100; // screen width - (width of img / sprite size) - (width of sprite / 2)
    e->y = (SCREEN_H / 2 - (e->img->h / 3) - 96 / 2) + 100; // screen height - (height of img / sprite size) - (height of sprite / 2)

    e->img_size.x = 0;
    e->img_size.y = 0;
    e->img_size.w = (e->img->w) / 6; // (width of img / sprite frames) :576/6 =96px
    e->img_size.h = (e->img->h) / 3; // (height of img / sprite frames) := 288/3= 96px
    e->img_pos.x = e->x;
    e->img_pos.y = e->y;

    e->current_state = WAITING;
    e->vision_range = 75;
}

/**
 * @brief Draws the enemy on the screen.
 *
 * This function blits the enemy image onto the specified screen surface at the enemy's image position.
 *
 * @param screen Pointer to the screen surface where the enemy will be drawn.
 * @param e The enemy to be drawn.
 */
void drawEnemy(SDL_Surface *screen, enemy e)
{
    SDL_BlitSurface(e.img, &(e.img_size), screen, &(e.img_pos));
}

/**
 * @brief Animates the enemy based on the given direction.
 *
 * This function updates the image size of the enemy to display the appropriate frame based on the direction.
 * It also handles the animation frame timing.
 *
 * @param e Pointer to the enemy structure to be animated.
 * @param direction The direction of the enemy animation (0 = idle, 1 = right, 2 = left).
 */
void animateEnemy(enemy *e, int direction) //! added new parameter dont forget
{
    static int frame = 0;
    int row = 0;
    if (direction == 1)
    {
        row = 0;
    }
    else if (direction == 2)
    {
        row = 1;
    }
    else if (direction == 0)
    {
        row = 2;
    }
    e->img_size.x = frame * e->img_size.w;
    e->img_size.y = row * e->img_size.h;

    Uint32 current_time = SDL_GetTicks();
    static Uint32 last_time = 0;
    Uint32 delta_time = current_time - last_time;
    if (delta_time >= 100)
    {
        frame++;
        if (frame >= 6)
        {
            frame = 0;
        }
        last_time = current_time;
    }
}

/**
 * @brief Moves the enemy according to its current direction.
 *
 * This function updates the enemy's image position based on its direction and speed.
 * It also calls the animateEnemy function to update the animation frame.
 *
 * @param e Pointer to the enemy structure to be moved.
 */
void moveEnemy(enemy *e)
{
    if (e->direction == 1)
    { // move right
        animateEnemy(e, 1);
        e->img_pos.x += e->speed;
        if (e->img_pos.x >= e->x + e->max_steps)
        {
            e->img_pos.x = e->x + e->max_steps;
            e->direction = 0;
            e->idle_time = SDL_GetTicks() + rand() % 1500 + 500;
        }
    }
    else if (e->direction == 2)
    { // move left
        animateEnemy(e, 2);
        e->img_pos.x -= e->speed;
        if (e->img_pos.x <= e->x)
        {
            e->img_pos.x = e->x;
            e->direction = 0;
            e->idle_time = SDL_GetTicks() + rand() % 1500 + 500;
        }
    }
    else if (e->direction == 0)
    { // idle
        animateEnemy(e, 0);
        Uint32 current_time = SDL_GetTicks();
        if (current_time >= e->idle_time)
        { // check if idle time is over
            if (e->img_pos.x == e->x)
            {
                e->direction = 1;
            }
            else if (e->img_pos.x == e->x + e->max_steps)
            {
                e->direction = 2;
            }
        }
    }
}

/**
 * @brief Checks for collision between two bounding boxes.
 *
 * This function determines whether there is a collision between the player's bounding box and the enemy's bounding box.
 * It returns 1 if there is a collision, and 0 otherwise.
 *
 * @param player The bounding box of the player.
 * @param enemy The bounding box of the enemy.
 * @return 1 if there is a collision, 0 otherwise.
 */
int collisionBB(SDL_Rect player, SDL_Rect enemyy, enemy *e)
{
    int collision = 0;
    if ((player.x + player.w < enemyy.x) || (player.x > enemyy.x + enemyy.w) || (player.y + player.h < enemyy.y) || (player.y > enemyy.y + enemyy.h))
    {
        collision = 0;
    }
    else
    {
        collision = 1;
        e->current_state = ATTACKING; // Set the enemy's current_state to ATTACKING
    }
    return collision;
}

/**
 * Calculates the distance between two SDL_Rect objects based on their x-coordinates.
 *
 * @param player The SDL_Rect object representing the player's position.
 * @param enemy The SDL_Rect object representing the enemy's position.
 * @return The distance between the player and the enemy along the x-axis.
 */
float distance(SDL_Rect player, SDL_Rect enemy)
{
    int distanceX = abs(enemy.x - player.x);
    return distanceX;
}

/**
 * Updates the state of an enemy based on the distance between the enemy and the player.
 *
 * @param e A pointer to the enemy object to update.
 * @param distEP The distance between the enemy and the player along the x-axis.
 */
void updateEnemyState(enemy *e, int distEP)
{
    if (distEP <= e->vision_range)
    {
        e->current_state = FOLLOWING;
    }
    else
    {
        e->current_state = WAITING;
    }
}

/**
 * Updates the position and behavior of an enemy based on the player's position and the enemy's state.
 *
 * @param e A pointer to the enemy object to update.
 * @param posPlayer The SDL_Rect object representing the player's position.
 */
void updateEnemy(enemy *e, SDL_Rect posPlayer)
{
    int distEP = distance(posPlayer, (SDL_Rect){e->img_pos.x, e->img_pos.y, e->img_size.w, e->img_size.h});
    updateEnemyState(e, distEP);

    switch (e->current_state)
    {
    case WAITING:
        moveEnemy(e);
        break;
    case FOLLOWING:
        if (distEP <= e->vision_range)
        {
            if (e->img_pos.x > posPlayer.x)
            {
                animateEnemy(e, 2);
                e->img_pos.x -= e->speed;
            }
            else if (e->img_pos.x < posPlayer.x)
            {
                animateEnemy(e, 1);
                e->img_pos.x += e->speed;
            }
        }
        else
        {
            e->current_state = WAITING;
        }
        break;
    case ATTACKING:
        if (!collisionBB(posPlayer, (SDL_Rect){e->img_pos.x, e->img_pos.y, e->img_size.w, e->img_size.h}, e))
        {
            e->current_state = FOLLOWING;
            break;
        }
        else
        {
            animateEnemy(e, 0);
            e->current_state = WAITING;
            e->img_pos.x = e->x;
            e->direction = 0;
            e->idle_time = SDL_GetTicks() + rand() % 1500 + 500;
            moveEnemy(e);
            break;
        }
    }
}

//**************TESTING FINCTIONS*****************

void initEnemytest(enemy *e)
{
    e->img = IMG_Load("../assets/img/enemyrun.png");
    if (e->img == NULL)
    {
        printf("Error loading enemy image: %s\n", SDL_GetError());
    }
    e->direction = 1;
    e->speed = 1;
    e->max_steps = 100;
    e->idle_time = 2000;
    e->x = (SCREEN_W / 2 - (e->img->w / 6) - 96 / 2) + 200; // screen width - (width of img / sprite size) - (width of sprite / 2)
    e->y = (SCREEN_H / 2 - (e->img->h / 3) - 96 / 2) + 100; // screen height - (height of img / sprite size) - (height of sprite / 2)

    e->img_size.x = 0;
    e->img_size.y = 0;
    e->img_size.w = (e->img->w) / 6; // (width of img / sprite frames) :576/6 =96px
    e->img_size.h = (e->img->h) / 3; // (height of img / sprite frames) := 288/3= 96px
    e->img_pos.x = e->x;
    e->img_pos.y = e->y;
}

void drawEnemytest(SDL_Surface *screen, enemy e)
{
    SDL_BlitSurface(e.img, &(e.img_size), screen, &(e.img_pos));
}

void animateEnemytest(enemy *e, int direction) //! added new parameter dont forget
{
    static int frame = 0; // static variable to track current frame
    int row = 0;
    if (direction == 1)
    {
        row = 0;
    }
    else if (direction == 2)
    {
        row = 1;
    }
    else if (direction == 0)
    {
        row = 2;
    }
    e->img_size.x = frame * e->img_size.w;
    e->img_size.y = row * e->img_size.h;

    Uint32 current_time = SDL_GetTicks();
    static Uint32 last_time = 0;
    Uint32 delta_time = current_time - last_time;
    if (delta_time >= 100)
    {
        frame++;
        if (frame >= 6)
        {
            frame = 0;
        }
        last_time = current_time;
    }
}

void moveEnemytest(enemy *e)
{
    if (e->direction == 2)
    {
        animateEnemy(e, 1);
        e->img_pos.x += e->speed;
        if (e->img_pos.x >= e->x + e->max_steps)
        {
            e->img_pos.x = e->x + e->max_steps;
            e->direction = 0;
            e->idle_time = SDL_GetTicks();
        }
    }
    else if (e->direction == 1)
    { // move left
        animateEnemy(e, 2);
        e->img_pos.x -= e->speed;
        if (e->img_pos.x <= e->x)
        {
            e->img_pos.x = e->x;
            e->direction = 0;
            e->idle_time = SDL_GetTicks();
        }
    }
    else if (e->direction == 0)
    {
        animateEnemy(e, 0);
        Uint32 current_time = SDL_GetTicks();
        if (current_time - e->idle_time >= 2000)
        {
            if (e->img_pos.x == e->x)
            {
                e->direction = 1;
            }
            else if (e->img_pos.x == e->x + e->max_steps)
            {
                e->direction = 2;
            }
        }
    }
}
