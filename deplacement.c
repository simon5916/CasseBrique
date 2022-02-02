#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL.h>
#include <stdbool.h>
#include "structures.h"

void MouvementJoueur(SDL_bool left, SDL_bool right, struct joueur *MonJoueur) {
    if (left) {
        MonJoueur->x -= MonJoueur->speedx;
    }
    if (right) {
        MonJoueur->x += MonJoueur->speedx;
    }
}

void DeplacementJoueur(SDL_Event event, SDL_bool *left, SDL_bool *right) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_RIGHT) {
            *right = true;
        }
        if (event.key.keysym.sym == SDLK_LEFT) {
            *left = true;
        }

    }
    if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_RIGHT) {
            *right = false;
        }
        if (event.key.keysym.sym == SDLK_LEFT) {
            *left = false;
        }
    }
}

void MouvementBalle(struct balle *BalleDuJeu, struct joueur *MonJoueur) {
    BalleDuJeu->x = BalleDuJeu->x + BalleDuJeu->speedx;
    BalleDuJeu->y = BalleDuJeu->y + BalleDuJeu->speedy;

    if (BalleDuJeu->x + BalleDuJeu->w >= 1080 || BalleDuJeu->x <= 0) {
        BalleDuJeu->speedx = BalleDuJeu->speedx * -1;
    }

    if (BalleDuJeu->y <= 0) {
        BalleDuJeu->speedy = BalleDuJeu->speedy * -1;
    }

    if (BalleDuJeu->y + BalleDuJeu->h >= 675) {
        MonJoueur->nbVie -= 1;
        BalleDuJeu->y = 200;
        BalleDuJeu->x = 200;
    }
}   
