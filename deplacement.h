#ifndef CASSEBRIQUE2_DEPLACEMENT_H
#define CASSEBRIQUE2_DEPLACEMENT_H

#endif //CASSEBRIQUE2_DEPLACEMENT_H

void DeplacementJoueur(SDL_Event event, SDL_bool *left,SDL_bool *right);
void MouvementJoueur (SDL_bool left,SDL_bool right, struct joueur *MonJoueur );
void MouvementBalle(  struct balle *BalleDuJeu, struct joueur *MonJoueur);
