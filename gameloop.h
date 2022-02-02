
#ifndef CASSEBRIQUE2_GAMELOOP_H
#define CASSEBRIQUE2_GAMELOOP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL.h>
#include <stdbool.h>
#include "structures.h"
#include "collisions.h"
#include "deplacement.h"

void Affichage(SDL_Renderer *renderer, struct bloc *blocs, size_t nbBloc);

int gameloop(SDL_Renderer *renderer);

int gameloop2(SDL_Renderer *renderer);

void affichageScoreEtVie(SDL_Renderer *renderer, struct joueur MonJoueur);

#endif //CASSEBRIQUE2_GAMELOOP_H

