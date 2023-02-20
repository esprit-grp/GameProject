#ifndef MENU_H
#define MENU_H

#define SCREEN_W 1280
#define SCREEN_H 720 // screen height and width
typedef struct
{

    char *filename;    // the filename of the image (url)
    SDL_Rect img_pos;  // the position of the image
    SDL_Rect img_size; // the size of the image (width and height) to know how to animate if we have sprite sheet images
    SDL_Surface *img;  // pointer to the image
} image;

//! LOAD AREA

void imageLoad_background(image *img);
void imageLoad_gametitle(image *img);

// load buttons assets
void imageLoad_playbutton(image *img);
void imageLoad_settingsbutton(image *img);
void imageLoad_quitbutton(image *img);

void imageLoadClicked_playbutton(image *img);
void imageLoadClicked_settingsbutton(image *img);
void imageLoadClicked_quitbutton(image *img);

void imageLoadHovered_playbutton(image *img);
void imageLoadHovered_settingsbutton(image *img);
void imageLoadHovered_quitbutton(image *img);

//! DRAW AREA

void imageDraw_gametitle(SDL_Surface *screen, image img);
void imageDraw_background(SDL_Surface *screen, image img);

// draw buttons
void imageDraw_playbutton(SDL_Surface *screen, image img);
void imageDraw_settingsbutton(SDL_Surface *screen, image img);
void imageDraw_quitbutton(SDL_Surface *screen, image img);

// animate buttons
void imageDrawClicked_playbutton(SDL_Surface *screen, image img);
void imageDrawClicked_settingsbutton(SDL_Surface *screen, image img);
void imageDrawClicked_quitbutton(SDL_Surface *screen, image img);

void imageDrawHovered_playbutton(SDL_Surface *screen, image img);
void imageDrawHovered_settingsbutton(SDL_Surface *screen, image img);
void imageDrawHovered_quitbutton(SDL_Surface *screen, image img);

// TODO make universal functions .h and .c files
//**UNIVERSAL FUNCTION**//
//  free buttons
void imageFree(image img);

#endif
