#ifndef CASSEBRIQUE2_MENU_H
#define CASSEBRIQUE2_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

void menuDuJeu(SDL_Renderer *renderer);
void menuNiveaux(SDL_Renderer *renderer);
void menuOption(SDL_Renderer *renderer);
void generateMenuItem(SDL_Renderer *renderer, TTF_Font *police, SDL_Color *color, int x, int y,  const char *text);

#endif //CASSEBRIQUE2_MENU_H