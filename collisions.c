#include <stdbool.h>
#include <SDL.h>
#include "structures.h"
#include "collisions.h"

void CollisionBalleJoueur(struct balle *BalleDuJeu, struct joueur *MonJoueur) {
    if (BalleDuJeu->x <= MonJoueur->x + MonJoueur->w && BalleDuJeu->x + BalleDuJeu->h >= MonJoueur->x && BalleDuJeu->y - BalleDuJeu->w <= MonJoueur->y && BalleDuJeu->y >= MonJoueur->y - MonJoueur->h){
        if (MonJoueur->x <= (BalleDuJeu->x + BalleDuJeu->w) && (MonJoueur->x + MonJoueur->w) >= BalleDuJeu->x) {
            BalleDuJeu->speedy = BalleDuJeu->speedy * -1;
        }
    }
}


void CollisionBalleBloc(struct balle *BalleDuJeu, struct bloc *blocs, size_t nbBlocs, struct joueur *MonJoueur) {
    for (int i = 0; i < nbBlocs; i++) {
        if (BalleDuJeu->x <= blocs[i].x + blocs[i].h && BalleDuJeu->x + BalleDuJeu->w >= blocs[i].x && BalleDuJeu->y - BalleDuJeu->h <= blocs[i].y && BalleDuJeu->y >= blocs[i].y - blocs[i].w){ // est ce que le bas de la balle tape le bas du bloc ?
                if (blocs[i].solidite == 1) {
                    blocs[i].h = 0;
                    blocs[i].w = 0;
                    MonJoueur->nbPoint += 100;
                    BalleDuJeu->speedx = BalleDuJeu->speedx * -1;
                }
                if (blocs[i].solidite >= 1) {
                    if ((blocs[i].y + blocs[i].w) >= BalleDuJeu->y && blocs[i].y <= (BalleDuJeu->y + BalleDuJeu->w )) {
                        BalleDuJeu->speedy = BalleDuJeu->speedy * -1;
                    }

                    if (blocs[i].x <= (BalleDuJeu->x + BalleDuJeu->h) && (blocs[i].x + blocs[i].h) >= BalleDuJeu->x) {
                        BalleDuJeu->speedx = BalleDuJeu->speedx * -1;
                    }

                    blocs[i].solidite -= 1;
                }

        }
    }

}