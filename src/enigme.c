#include "enigme.h"

#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include <SDL/SDL_ttf.h>

void afficherEnigme(Enigme e, SDL_Surface *screen, TTF_Font *font, SDL_Color textColor)

{

    SDL_Surface *questionSurface = TTF_RenderText_Solid(font, e.question, textColor);

    SDL_Surface *reponseSurface = TTF_RenderText_Solid(font, e.reponse, textColor);

    SDL_Rect questionLocation = {0, 0, 0};

    SDL_Rect reponseLocation = {0, 0, 0};

    questionLocation.x = (screen->w - questionSurface->w) / 2;

    questionLocation.y = (screen->h - questionSurface->h) / 2 - 50;

    reponseLocation.x = (screen->w - reponseSurface->w) / 2;

    reponseLocation.y = (screen->h - reponseSurface->h) / 2 + 50;

    SDL_BlitSurface(questionSurface, NULL, screen, &questionLocation);

    SDL_BlitSurface(reponseSurface, NULL, screen, &reponseLocation);

    SDL_FreeSurface(questionSurface);

    SDL_FreeSurface(reponseSurface);
}

void genererEnigme(Enigme *p, char *nomfichier)
{

    srand(time(NULL));

    int num_lines = 0, i;

    char ligne[100];

    FILE *fp = fopen(nomfichier, "r");

    if (fp == NULL)
    {

        printf("Impossible d'ouvrir le fichier\n");

        return;
    }

    while (fgets(ligne, 100, fp) != NULL)
    {

        num_lines++;
    }

    fclose(fp);

    int random_index = rand() % (num_lines / 2) * 2;

    fp = fopen(nomfichier, "r");

    if (fp == NULL)
    {

        printf("Impossible d'ouvrir le fichier\n");

        return;
    }

    for (i = 0; i < random_index; i++)
    {

        fgets(ligne, 100, fp);
    }

    fgets(p->question, 100, fp);

    fgets(p->reponse, 100, fp);

    fclose(fp);
}

/*

void animerEnigme(Enigme* e)

{

    // Load the sand watch image

    SDL_Surface* sand_watch = IMG_Load("sand_watch.png");

    if (!sand_watch) {

        printf("Error loading image: %s\n", IMG_GetError());

        return;

    }



    // Set the angle and position of the sand watch

    double angle = 0;

    int x = 100;

    int y = 100;



    // Loop to animate the sand watch

    while (true) {

        // Clear the screen

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));



        // Rotate the sand watch surface by the angle

        SDL_Surface* rotated_sand_watch = rotozoomSurface(sand_watch, angle, 1.0, 0);

        angle += 1;  // Increase the angle to make the sand watch rotate



        // Blit the rotated sand watch surface onto the screen

        SDL_Rect rect = { x, y, rotated_sand_watch->w, rotated_sand_watch->h };

        SDL_BlitSurface(rotated_sand_watch, NULL, screen, &rect);

        // Delay the loop to control the animation speed

        SDL_Delay(10);



        // Free the rotated sand watch surface to avoid memory leaks

        SDL_FreeSurface(rotated_sand_watch);



        // Exit the loop if the animation duration is over

        if ( check if the animation duration is over) {

           // break;

        }

    }



    // Free the sand watch surface to avoid memory leaks

  //  SDL_FreeSurface(sand_watch);

}



*/
