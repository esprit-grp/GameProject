#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../include/music.h"

 //---------------------------------------// 
 //here is better version ('i think so')  code  for the music //

    #define MAX_VOLUME MIX_MAX_VOLUME
    #define MIN_VOLUME 0
    #define VOLUME_STEP 16 // we 16 for the step because MAX_VOLUME is 128 so we get 8 steps and avoid what 'RIDHA' have of errors 
    #define MIX_DEFAULT_FREQUENCY 44100 
    static Mix_Music* music = NULL;
    static Mix_Chunk* FX = NULL; 
    static int volume = MIX_MAX_VOLUME / 2;  // 2 for half volume, 0 for mute

    int initAudio()  // Returns 0 on success, 1 on failure  // it think like that the code will run smoothly
   {
        if (SDL_Init(SDL_INIT_AUDIO) == -1) // Initialize SDL with audio support
        {
            printf("%s", SDL_GetError());
            return 1;
        }

        if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
        {
            printf("%s", Mix_GetError());
            return 1;
        }

        return 0;
   }
  
   // cleanup audio subsystem
    void cleanupAudio()
    {
        Mix_FreeMusic(musiMix_Music *music);
        Mix_FreeChunk(Mix_Chunk *FX);
        Mix_CloseAudio();
        SDL_Quit();
    }

    // load music file
    void musicLoad(Mix_Music *music)
    {
        music = Mix_LoadMUS("../assets/audio/music.mp3");
        if (music == NULL)
        {
            printf("unable to load music Error: %s.\n", Mix_GetError());
            return;
        }
        Mix_PlayMusic(music, -1);   // music, loop (-1 for infinite)
        Mix_VolumeMusic(volume);
    }

    // load sound effect file
void FXLoad(Mix_Chunk *FX)
{
    FX = Mix_LoadWAV("../assets/audio/click.wav");
    if (FX == NULL)
    {
        printf("unable to load FX Error: %s.\n", Mix_GetError());
        return;
    }
    Mix_PlayChannel(-1, FX, 0); // channel , sound effect , loop : -1 for taking the first avilble channel - 0 for no loop
}
  
  // free music
void musicFree()
{
    Mix_FreeMusic(music);
}

// free sound effect
void FXFree()
{
    Mix_FreeChunk(FX);
}

// increase music volume
void musicVolumeUp()
{
    if (volume + VOLUME_STEP <= MAX_VOLUME)
    {
        volume += VOLUME_STEP;
    }
    else
    {
        volume = MAX_VOLUME;
    }

    Mix_VolumeMusic(volume);
}

// decrease music volume
void musicVolumeDown()
{
    if (volume - VOLUME_STEP >= MIN_VOLUME)
    {
        volume -= VOLUME_STEP;
    }
    else
    {
        volume = MIN_VOLUME;
    }

    Mix_VolumeMusic(volume);
}




  //here end //
 //---------------------------------------//
//the next code down is yours //

//............................................//

// load the music
void musicLoad(Mix_Music *music)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music = Mix_LoadMUS("../assets/audio/music.mp3"); // mp3 file
    if (music == NULL)
    {
        printf("unable to load music Error: %s.\n", Mix_GetError());
        return;
    }
    Mix_PlayMusic(music, -1);            // music, loop (-1 for infinite)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // 2 for half volume, 0 for mute
}

// load the sound effects
void FXLoad(Mix_Chunk *FX)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1;
    FX = Mix_LoadWAV("../assets/audio/click.wav"); // wav file
    if (FX == NULL)
    {
        printf("unable to load FX Error: %s.\n", Mix_GetError());
        return;
    }
    Mix_PlayChannel(-1, FX, 0); // channel , sound effect , loop : -1 for taking the first avilble channel - 0 for no loop
    // maybe you will need this for controlling sound effects volume :
    // Mix_VolumeChunk(FX, MIX_MAX_VOLUME / 2); // 2 for half volume, 0 for mute
}

// free the music
void musicFree(Mix_Music *music)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

// free the sound effects
void FXFree(Mix_Chunk *FX)
{
    Mix_FreeChunk(FX);
    Mix_CloseAudio();
}