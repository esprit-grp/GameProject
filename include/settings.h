#ifndef SETTINGS_H
#define SETTINGS_H

#define SCREEN_W 1280
#define SCREEN_H 720 // screen height and width

//! LOAD AREA
void imageLoad_sounddown(image *img);
void imageLoad_soundup(image *img);
void imageLoad_soundmute(image *img);
void imageLoad_fullscreen(image *img);

//! DRAW AREA
void imageDraw_sounddown(SDL_Surface *screen, image img);
void imageDraw_soundup(SDL_Surface *screen, image img);
void imageDraw_soundmute(SDL_Surface *screen, image img);
void imageDraw_fullscreen(SDL_Surface *screen, image img);

#endif // SETTINGS_H