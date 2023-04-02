#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <rain.h>

// Initialisation des gouttes de pluie
void initRainDrops(RainDrop* drops) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        drops[i].x = rand() % SCREEN_WIDTH; // position horizontale aléatoire
        drops[i].y = -(rand() % SCREEN_HEIGHT); // position verticale aléatoire
        drops[i].speed = 2 + rand() % 5; // vitesse aléatoire entre 2 et 6 pixels par frame
    }
}

// Fonction pour animer la pluie
void animateRain(SDL_Surface* screen, SDL_Surface* rainSprite, RainDrop* drops) {
    // Boucle de jeu
    int quit = 0;
    while (!quit) {
        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

 // Effacement de l'écran
        SDL_FillRect(screen, NULL, 0x000000);

        // Mise à jour et affichage des gouttes de pluie
        for (int i = 0; i < MAX_RAIN_DROPS; i++) {
            // Déplacement de la goutte
            drops[i].y += drops[i].speed;

            // Si la goutte a atteint le bas de l'écran, on la replace en haut
            if (drops[i].y > SCREEN_HEIGHT) {
                drops[i].x = rand() % SCREEN_WIDTH;
                drops[i].y = -(rand() % SCREEN_HEIGHT);
            }

            // Affichage de la goutte
            SDL_Rect destRect = { drops[i].x, drops[i].y };
            SDL_BlitSurface(rainSprite, NULL, screen, &destRect);
        }  
        // Mise à jour de l'écran
        SDL_Flip(screen);

        // Pause pour limiter la vitesse de rafraîchissement
        SDL_Delay(20);
    }
}     






/*
// Fonction principale
int main(int argc, char* argv[]) {
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Création de la fenêtre
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);

    // Chargement du sprite pour la pluie
    SDL_Surface* rainSprite = SDL_LoadBMP("rain.bmp");

    // Initialisation des gouttes de pluie
    RainDrop drops[MAX_RAIN_DROPS];
    initRainDrops(drops);

    // Animation de la pluie
    animateRain(screen, rainSprite, drops);

    // Libération de la mémoire et fermeture de SDL
    SDL_FreeSurface(rainSprite);
    SDL_Quit();

    return 0;
}
*/