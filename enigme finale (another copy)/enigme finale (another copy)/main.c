#include "enigme_fichier.h"
#include <stdbool.h>


int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    srand(time(NULL));
    SDL_Surface *screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE);

    // Wait for user to press 'E'
    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_e) {
            break;
        }
    }

    Enigme e;
    genererEnigme(&e, "../assets/text/enigme.txt");
    int b = 0;
    while (b == 0) {
        SDL_PumpEvents();
        if (resolution(e) == -1) {
            afficherEnigme(e, screen, -1);
            animerenigme(&e);
        } else {
            if (resolution(e) == e.corr) {
                afficherEnigme(e, screen, 1);
                SDL_Flip(screen);
                SDL_Delay(5000);
                return 1;
            } else {
                afficherEnigme(e, screen, 0);
                b = 1;
                SDL_Flip(screen);
                SDL_Delay(5000);
                return 0;
            }
        }
    }
    return 0;
}

