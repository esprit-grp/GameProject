#include <stdio.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Pour manipuler des images
#include <SDL/SDL_mixer.h> //Pour manipuler des textes
#include <SDL/SDL_ttf.h>   //Pour manipuler de l’audio

int main()
{
    SDL_Surface *screen;
    image *background;
    image *btn1;
    image *btn2;
    texte txte;
    Mix_Music *music;
    Mix_Music *mus;
    SDL_event event;
    int boucle = 1;

    // initialization des composants graphique ,textuels et son
    if (SLD_Init(SDL_INTI_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    // reglage de la fenetre
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    // initialisation
    initialiser_imageBACK(&background);
    initialiser_imageBOUTON1(&btn1);
    initialiser_imageBOUTON2(&btn2);
    initialiser_audio(music);
    initialiser_texte(&txte);

    // boucle du menu
    while (boucle)
    {
        // affichage
        afficher_background(screen, background); // affiche le background
        afficher_btn1(screen, btn1);             // affiche le button play
        afficher_btn2(screen, btn2);             // affiche le button quit
        afficher_texte(screen, txte);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEMOTION: // mouvement de la souris
                if (event.motion.y < 150 && event.motion.y >= 100 && (event.motion.x <= 423 && event.motion.x >= 213))
                {
                    initialiser_audiobref(mus);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button == SDL_BUTTON_LEFT && (event.motion.y <= 300 && event.motion.y >= 250 && event.motion.x <= 423 && event.motion.x > 213))
                {
                    boucle = 0;
                }
                break;
            case SDL_QUIT:
                boucle = 0;
                break;
            }
        }
        SDL_Flip(screen); // refresh the screen
    }
    // free the surfaces
    liberer_image(background);
    liberer_image(btn1);
    liberer_image(btn2);

    // free the music
    liberer_musique(music);
    liberer_musiquebref(mus);

    // free the txte
    liberer_texte(txte);

    // Quit SDL
    SDL_Quit();
    return 0;
}
