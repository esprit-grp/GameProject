#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Pour manipuler des images
#include <SDL/SDL_mixer.h> //Pour manipuler des textes
#include <SDL/SDL_ttf.h>   //Pour manipuler de l’audio
#include "fonction.h"

void initialiser_imageBACK(image *imge)
{
    imge->url = "location of background";
    imge->img = SDL_LoadBMP(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = 0;
    imge->pos_img_ecran.y = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = SCREEN_H;
    imge->pos_img_affiche.w = SCREEN_W;
}

void initialiser_imageBOUTON1(image *imgbtn)
{
    imgbtn->url = "play button location";
    imgbtn->img = SDL_LoadBMP(imgbtn->url);
    if (imgbtn->img == NULL)
    {
        printf("Unable to load Button image %s \n", SDL_GetError());
        return;
    }
    imgbtn->pos_img_affiche.x = 0;
    imgbtn->pos_img_affiche.y = 0;
    imgbtn->pos_img_affiche.w = 237;
    imgbtn->pos_img_affiche.h = 58;
    imgbtn->pos_img_ecran.x = ((SCREEN_W - imgbtn->pos_img_affiche.w) / 2);
    imgbtn->pos_img_ecran.y = ((SCREEN_W - imgbtn->pos_img_affiche.h) / 3);
}

void initialiser_imageBOUTON2(image *imgbtn)
{
    // chargement de l'image
    imgbtn->url = "quit button location";
    imgbtn->img = SDL_LoadBMP(imgbtn->url);
    if (imgbtn->img == NULL)
    {
        printf("Unable to load Button image %s \n", SDL_GetError());
        return;
    }
    imgbtn->pos_img_affiche.x = 0;
    imgbtn->pos_img_affiche.y = 0;
    imgbtn->pos_img_affiche.w = 236;
    imgbtn->pos_img_affiche.h = 55;
    imgbtn->pos_img_ecran.x = ((SCREEN_W - imgbtn->pos_img_affiche.w) / 2);
    imgbtn->pos_img_ecran.y = ((SCREEN_W - imgbtn->pos_img_affiche.h) / 3);
}

void afficher_background(SDL_Surface *screen, image imge)
{
    // coller et afficher l'image du background dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_btn1(SDL_Surface *screen, image imge)
{
    // coller et afficher l'image du play bouton dans screen
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_btn2(SDL_Surface *screen, image imge)
{
    // coller et afficher l'image du quit bouton dans screen
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}

void initialiser_audio(Mix_Music *music)
{
    // initializer les fonction audio de SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("faild audio initialization %s \n", SDL_GetError());
    }
    music = Mix_LoadMUS("audio location"); // chargement de la muisc
    Mix_PlayMusic(music, -1);              // play the music
    Mix_VolumeMusic(MIX_MAX_VOLUME / 3.5);
}

void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music)
{
    Mix_OpenAudio(4410, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadWAV("music bref location");
    Mix_PlayChannel(-1, music, 0);
    if (music == NULL)
    {
        printf("failed audio breff initialization %s \n", SDL_GetError());
    }
}

void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

void initialiser_texte(texte txte)
{
    TTF_Init();                                     // initialiser SDL_ttf
    txte.police = TTF_OpenFont("Ubuntu-B.ttf", 45); // chargement d'une police et initialiser la taille
    txte.color_txt.r = 0;
    txte.color_txt.g = 0;
    txte.color_txt.b = 0;
    txte.pos_txt.x = 210;
    txte.pos_txt.y = 0;
}

void afficher_texte(SDL_Surface *screen, texte txte)
{
    txte.txt = TTF_RenderText_blended(txte.police, "Welcome", txte.color_txt); // ecrire le msg "Welcome"
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);                    // coller la surface
}

void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police);
    TTF_Quit(); // arreter la SDL_ttf
}
