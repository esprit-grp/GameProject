#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../include/music.h"

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
    FX = Mix_LoadWAV("../assets/audio/FX.wav"); // wav file
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