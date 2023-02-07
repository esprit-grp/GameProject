#ifndef MUSIC_H
#define MUSIC_H

void musicLoad(Mix_Music *music);
void FXLoad(Mix_Chunk *FX);
void musicFree(Mix_Music *music);
void FXFree(Mix_Chunk *FX);

#endif