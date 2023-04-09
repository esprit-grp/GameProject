#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <time.h>

#include <SDL/SDL.h>

#include <SDL/SDL_ttf.h>   

#include <SDL/SDL_mixer.h>

#include "enigme.h"

#include <SDL/SDL_image.h>



#define SPRITE_WIDTH 250

#define SPRITE_HEIGHT 280  

#define TOTAL_FRAMES 30

  

int main(void) {

    SDL_Surface* screen; 

    TTF_Font* font;

    TTF_Init();

    SDL_Color textColor = { 255, 255, 255 };

    SDL_Color textColor_RED = {255, 0, 0, 255};

    SDL_Color textColor_GREEN = { 0, 255, 0, 255 };

    SDL_Color textColor_YELLOW = {255, 255, 0, 255};

    SDL_Rect textLocation = { 0, 0, 0 };

    SDL_Surface* textSurface;

    Enigme e;

    genererEnigme(&e, "enigmes.txt");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1) {

        printf("Erreur d'initialisation de SDL : %s\n", SDL_GetError());

        return 1;

    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Chunk *congrats = Mix_LoadWAV("congratulations.wav");

    Mix_Chunk *wrong = Mix_LoadWAV("wrong.wav");

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (screen == NULL) {

        printf("Impossible d'ouvrir la fenetre SDL : %s\n", SDL_GetError());

        return 1;

    }

    TTF_Init();

    font = TTF_OpenFont("test.ttf", 18);

    if (font == NULL) {

        printf("Impossible de charger la police : %s\n", TTF_GetError());

        return 1;

    }



    // Load background image

    SDL_Surface *background = IMG_Load("background.png");

    if (!background) {

        printf("Error loading image: %s\n", IMG_GetError());

        return 1;

    }

    



     // Load background-wrong image

    SDL_Surface *backgroundwrong = IMG_Load("background_wrong.png");

    if (!background) {

        printf("Error loading image: %s\n", IMG_GetError());

        return 1;

    }

    

    //----------------------------------------------------------------------

     SDL_Surface  *spriteSheet, *currentFrame;

    SDL_Rect framePosition;

    int frame = 0;

    Uint32 frameStart;

     // Load the sprite sheet

    spriteSheet = IMG_Load("horses.png");



    // Set up the frame position and size

    framePosition.x = -30;

    framePosition.y = -30;

    framePosition.w = SPRITE_WIDTH+35;

    framePosition.h = SPRITE_HEIGHT;



    // Start the frame timer

    frameStart = SDL_GetTicks();

    //----------------------------------------------------------------------

		 

	

      

    bool show_enigme = false;

    SDL_Event event;

         //---

	textSurface = TTF_RenderText_Solid(font, "press H to start", textColor_YELLOW);

    	textLocation.x = 10;

    	textLocation.y = 15;

    	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

   	

   	//---

    while (!show_enigme) {

        while (SDL_PollEvent(&event)) {

            switch (event.type) {

                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_h) {

                        show_enigme = true; 

                        // Render the background image

			 SDL_BlitSurface(background, NULL, screen, NULL);                         

                        SDL_Flip(screen);

                    }

                    break;

                case SDL_QUIT:

                    SDL_FreeSurface(textSurface);

                    TTF_CloseFont(font);

                    TTF_Quit();

                    Mix_FreeChunk(congrats);

                    Mix_FreeChunk(wrong);

                    Mix_CloseAudio();

                    SDL_Quit();

                    return 0;

                    break;

                default:

                    break;

            }

        }



     // Set the current frame

        currentFrame = SDL_CreateRGBSurface(SDL_SWSURFACE, SPRITE_WIDTH, SPRITE_HEIGHT, 32, 0, 0, 0, 0);

        SDL_Rect source = {frame * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT};

        SDL_BlitSurface(spriteSheet, &source, currentFrame, NULL);



        // Draw the current frame to the screen

        SDL_BlitSurface(currentFrame, NULL, screen, &framePosition);



        // Update the screen

        SDL_Flip(screen);



      

        

    }





//score

int score = 100;



// Convert the score to a string

char scoreStr[20];

sprintf(scoreStr, "Score: %d", score);



// Create a surface for the text

textSurface = TTF_RenderText_Solid(font, scoreStr, textColor);



// Free the text surface

SDL_FreeSurface(textSurface);



// Update the score text

sprintf(scoreStr, "Score: %d", score);

textSurface = TTF_RenderText_Solid(font, scoreStr, textColor);



// Blit the updated score text to the screen

textLocation.x = 560;

textLocation.y = 42;

SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

SDL_Flip(screen);



// Free the updated score text surface

SDL_FreeSurface(textSurface);



/*

     //print enigma image bakground game

     animerEnigme(&e); 

  */



afficherEnigme(e, screen, font, textColor);

    // Add code to display the prompt for choosing the right response

  	textSurface = TTF_RenderText_Solid(font, "choose the right response : ", textColor_YELLOW); 

	textLocation.x = 475;

	textLocation.y = 220;

	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

	SDL_Flip(screen);







		

bool done = false;

Mix_Music *congratulations_music, *wrong_music;

Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

congratulations_music = Mix_LoadMUS("Congratulations.mp3");

wrong_music = Mix_LoadMUS("wrong.mp3");



done = false;

while (!done) {

    while (SDL_PollEvent(&event)) {

        switch (event.type) {

            case SDL_QUIT:

                done = true;

          SDL_FreeSurface(spriteSheet);

                break;

            default:

                break;

        }

    }       

    //---------------------------------------

      // Calculate which frame to display

        Uint32 elapsed = SDL_GetTicks() - frameStart;

        if (elapsed >= (33000) / TOTAL_FRAMES) {

            frame++;

            if (frame >= TOTAL_FRAMES) {

                frame = 0;

            }

            frameStart = SDL_GetTicks();

        }



        // Set the current frame

        currentFrame = SDL_CreateRGBSurface(SDL_SWSURFACE, SPRITE_WIDTH, SPRITE_HEIGHT, 32, 0, 0, 0, 0);

        SDL_Rect source = {frame * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT};

        SDL_BlitSurface(spriteSheet, &source, currentFrame, NULL);



        // Draw the current frame to the screen

        SDL_BlitSurface(currentFrame, NULL, screen, &framePosition);



        // Update the screen

        SDL_Flip(screen);



        // Free the current frame

        SDL_FreeSurface(currentFrame);

        

    //---------------------------------------

    // Check if user clicked in a specific zone

    SDL_Event clickEvent;

    while (SDL_PollEvent(&clickEvent)) {

       if (clickEvent.type == SDL_MOUSEBUTTONDOWN) {

        int x = clickEvent.button.x;

        int y = clickEvent.button.y;



        // Check if the word "hannibal" is present in the text file



            // Check if the click event occurred in the specific zone

            if (x > 600 && x < 920 && y > 300 && y < 440) {

                // User clicked in the correct zone

                Mix_PlayMusic(congratulations_music, 1);

                score += 10;

                textSurface = TTF_RenderText_Solid(font, "            **Congratulations!**  ", textColor_GREEN);

                textLocation.x = 560;

                textLocation.y = 530;

                // Render the background-wrong image

                SDL_BlitSurface(backgroundwrong, NULL, screen, NULL);

                score += 10;

            } else {

                // User clicked in the wrong zone

                Mix_PlayMusic(wrong_music, 1);

                score -= 10;

                textSurface = TTF_RenderText_Solid(font, "Wrong!  (>_-_<) ", textColor_RED);

                textLocation.x = 560;

                textLocation.y = 550;

                // Render the background-wrong image

                SDL_BlitSurface(backgroundwrong, NULL, screen, NULL);

                score -= 10;

            }   

 

		

            // The word "hannibal" is not present in the text file

            // Handle this case as appropriate

        

                SDL_Flip(screen);

            

		// Update the score text

		sprintf(scoreStr, "Score: %d", score);

		textSurface = TTF_RenderText_Solid(font, scoreStr, textColor);



		// Blit the updated score text to the screen

		textLocation.x = 560;

		textLocation.y = 42;

		SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

		

              afficherEnigme(e, screen, font, textColor);

            SDL_BlitSurface(textSurface, NULL, screen, &textLocation); // choose right reponse

            textSurface = TTF_RenderText_Solid(font, "choose the right response : ", textColor_YELLOW); 

            textLocation.x = 475;

	    textLocation.y = 220;



            SDL_BlitSurface(textSurface, NULL, screen, &textLocation);//wrong or Congratulation

            SDL_Flip(screen);        

        }    

    }	

}

 FILE* fp = fopen("last_score.txt", "w"); // Open the file in write mode

	if (fp != NULL) {

	  fprintf(fp, "%d", score); 

	  fclose(fp);  

	}



// Free the updated score text surface

  SDL_FreeSurface(currentFrame);

SDL_FreeSurface(textSurface);

SDL_FreeSurface(background);

SDL_FreeSurface(textSurface);

Mix_FreeMusic(congratulations_music);

Mix_FreeMusic(wrong_music);

TTF_CloseFont(font);

TTF_Quit();

SDL_Quit();

return 0;

}

