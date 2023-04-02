#ifndef BACKGROUND_H
#define BACKGROUND_H

#define SCREEN_W 1280
#define SCREEN_H 720 

//structure du background
typedef struct {
    SDL_Rect img_pos;  // the position of the image
    SDL_Rect img_size; // the size of the image (width and height) to know how to animate if we have sprite sheet images
    SDL_Surface *img;  // pointer to the image
    int scrollingSpeed; 
    SDL_Rect camera_pos;
    int direction;
    char *filename;

}background;

typedef struct {
    int x, y; // position
    int speed; // vitesse de la chute
} RainDrop;


void initBack(background* b);
void afficherBack(background b, SDL_Surface *screen);
void scrolling(SDL_Rect *b, int direction);
void animerBack(background* b);


#endif
