#include "enigme_fichier.h"
#define QUESTION 3


void genererEnigme(Enigme * e,char *nomfichier) {
  char reponses[4][16];
  char question[32];
  char text[8];
  FILE * fp;
  char buff[255];
  fp = fopen(nomfichier, "r"); 
   
  int l = rand() % 3;
  l *= 5;
  
  for (int i = 0; i < l; i++)
    fscanf(fp, "%s\n", buff);
  fscanf(fp, "%s", question);
  for (int i = 0; i < 4; i++)
    fscanf(fp, "%s", reponses[i]);
  SDL_Delay(100);
  
  e -> bg = IMG_Load("bg.jpg");
  TTF_Font * font = TTF_OpenFont("Skatchboard.ttf", 50);
  SDL_Color color = {125,0,125};
  e -> question = TTF_RenderText_Blended(font, question, color);
  e -> corr = l;
  
  sprintf(question, "%s", reponses[e -> corr]);
  sprintf(reponses[e -> corr], "%s", reponses[0]);
  sprintf(reponses[0], "%s", question);
  
  for (int i = 0; i < 4; i++) {
    sprintf(text, "%c %s", 65 + i, reponses[i]);
    e -> reponses[i] = TTF_RenderText_Solid(font, text, color);
    e -> pos[i].x = 200;
    e -> pos[i].y = 200 + 100 * i;
    e -> pos[i].w = e -> reponses[i] -> w;
    e -> pos[i].h = 60;
  }
  
	sprintf(text, "** congratulation **");
	e->won = TTF_RenderText_Solid(font, text, color);

	
	sprintf(text, "** wrong **");
	e->lost = TTF_RenderText_Solid(font, text, color);

  e -> anim = 0;
  for (int i = 0; i < 16; i++) {
    sprintf(buff, "animation/Layer %d.png", i + 1);
    e -> clock[i] = IMG_Load(buff);
  }

}

void animerenigme(Enigme * e) {
  e -> anim++;
  if (e -> anim == 160) 
	e -> anim = 0;
}

void afficherEnigme(Enigme e, SDL_Surface * screen, int x) {
  SDL_Rect pos;
  pos.x = 200;
  pos.y = 90;
int i;
  SDL_BlitSurface(e.bg, NULL, screen, NULL);
  SDL_BlitSurface(e.question, NULL, screen, & pos);
 for (i = 0; i < 4; i++) {
    SDL_BlitSurface(e.reponses[i], NULL, screen, & e.pos[i]);
  }
  e.pos[3].y += 100;
  if (x == 1) SDL_BlitSurface(e.won, NULL, screen, & e.pos[3]);
  if (x == 0) SDL_BlitSurface(e.lost, NULL, screen, & e.pos[3]);
  pos.x = (screen -> w - e.clock[e.anim / 10] -> w);
  pos.y = screen -> h - e.clock[e.anim / 10] -> h;
  SDL_BlitSurface(e.clock[e.anim / 10], NULL, screen,NULL);
  SDL_Flip(screen);
}

int resolution(Enigme e) {
  Uint8 * keystate = SDL_GetKeyState(NULL);
  if (keystate[SDLK_ESCAPE]) return 4;
  if (keystate[SDLK_a]) return 0;
  if (keystate[SDLK_b]) return 1;
  if (keystate[SDLK_c]) return 2;
  if (keystate[SDLK_d]) return 3;
  int x, y;
  Uint32 buttons = SDL_GetMouseState( & x, & y);
  SDL_Rect pos;
  pos.w = 5;
  pos.h = 5;
  pos.x = x;
  pos.y = y;
  for (int i = 0; i < 4; i++) {
    if ((buttons & SDL_BUTTON_LMASK) != 0)
      if (collision(pos, e.pos[i]))
        return i;
  }
  return -1;
} 
