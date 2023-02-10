#ifndef TEXT_H
#define TEXT_H

typedef struct
{
    SDL_Surface *txt;
    SDL_Rect pos;
    SDL_Color color;
    TTF_Font *font;
} text;

void textLoad(text *txt);
void textDraw(SDL_Surface *screen, text txt, char *str); // screen, text var, string
void textFree(text txt);

#endif