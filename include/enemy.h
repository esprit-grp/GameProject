#ifndef ENEMY_H
#define ENEMY_H

/**
 * @brief Structure representing an enemy.
 *
 * The enemy structure contains information about the enemy's position, size, sprite image,
 * direction of movement, speed, maximum steps before changing direction, idle time, and grid position.
 */
typedef enum
{
    WAITING,
    FOLLOWING,
    ATTACKING
} state;

typedef struct
{
    SDL_Rect img_pos;     //!< Position of the sprite on the screen.
    SDL_Rect img_size;    //!< Size of the sprite.
    SDL_Surface *img;     //!< Pointer to the sprite image.
    int direction;        //!< Direction of movement (0 for idle, 1 for right, 2 for left).
    float speed;          //!< Steps per frame.
    int max_steps;        //!< Maximum number of steps before changing direction.
    int idle_time;        //!< Time when the enemy started idling.
    int x;                //!< Position of the enemy in the grid (screen coordinates).
    int y;                //!< Position of the enemy in the grid (screen coordinates).
    states current_state; //!< Current state of the enemy.
    int vision_range;     //!< Range of vision of the enemy.
} enemy;

/**
 * @brief Initializes an enemy.
 *
 * This function initializes the enemy structure by loading the sprite image, setting the direction, speed, maximum steps,
 * idle time, and initial positions.
 *
 * @param e Pointer to the enemy structure.
 */
void initEnemy(enemy *e);

/**
 * @brief Draws the enemy on the screen.
 *
 * This function draws the enemy sprite on the given screen surface at its current position.
 *
 * @param screen Pointer to the screen surface.
 * @param e The enemy structure.
 */
void drawEnemy(SDL_Surface *screen, enemy e);

/**
 * @brief Animates the enemy sprite.
 *
 * This function updates the sprite frame of the enemy based on the given direction.
 *
 * @param e Pointer to the enemy structure.
 * @param direction The direction of movement (0 for idle, 1 for right, 2 for left).
 */
void animateEnemy(enemy *e, int direction);

/**
 * @brief Moves the enemy.
 *
 * This function moves the enemy based on its current direction and updates the sprite animation accordingly.
 *
 * @param e Pointer to the enemy structure.
 */
void moveEnemy(enemy *e);

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
int collisionBB(SDL_Rect player, SDL_Rect enemyy, enemy *e);
void updateEnemy(enemy *e, SDL_Rect posPlayer);
float distance(SDL_Rect player, SDL_Rect enemy);
void updateEnemyState(enemy *e, int distEP);

//****************************************************

void initEnemytest(enemy *e);
void drawEnemytest(SDL_Surface *screen, enemy e);
void animateEnemytest(enemy *e, int direction);
void moveEnemytest(enemy *e);

#endif