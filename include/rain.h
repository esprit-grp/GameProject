#ifndef RAIN_H
#define RAIN_H


// Définition des constantes
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SPRITE_WIDTH  64
#define SPRITE_HEIGHT 64
#define MAX_RAIN_DROPS 100

// Structure pour les gouttes de pluie
typedef struct {
    int x, y; // position
    int speed; // vitesse de la chute
} RainDrop;

#endif 


/*
ypedef struct {
    SDL_Surface* image;
    int x;
    int y;
    int speed;
} Back;

void animerBack(Back* b) {
    while (1) {
        // Move the background to the left
        b->x -= b->speed;

        // If the background has gone off the screen, wrap it back around
        if (b->x <= -b->image->w) {
            b->x = 0;
        }

        // Clear the screen
        SDL_FillRect(SDL_GetVideoSurface(), NULL, 0x000000);

        // Draw the background
        SDL_Rect dest_rect = {b->x, b->y, 0, 0};
        SDL_BlitSurface(b->image, NULL, SDL_GetVideoSurface(), &dest_rect);

        // Update the screen
        SDL_Flip(SDL_GetVideoSurface());

        // Wait a short amount of time to control the animation speed
        SDL_Delay(20);
    }
}
*/