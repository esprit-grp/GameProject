#ifndef MUSIC_H
#define MUSIC_H
#include <SDL2/SDL.h>

//---------------------------------------// 
//here is better version ('i think so')  code  for the music //

int initAudio();
void cleanupAudio(); // music free all 
void musicLoad(Mix_Music *music); 
void FXLoad(Mix_Chunk *FX);
void playMusic();
void pauseMusic();
void stopMusic();
void increaseVolume();
void decreaseVolume();

//here end //
//---------------------------------------//
//the next code down is yours //

//............................................//

void musicLoad(Mix_Music *music);
void FXLoad(Mix_Chunk *FX);
void musicFree(Mix_Music *music);
void FXFree(Mix_Chunk *FX);

#endif