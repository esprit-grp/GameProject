#include "display.h"

void toggle_fullscreen(SDL_Surface* screen) {
  SDL_WM_ToggleFullScreen(screen);
}
