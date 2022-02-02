#ifndef CASSEBRIQUE2_COLLISIONS_H
#define CASSEBRIQUE2_COLLISIONS_H
#endif //CASSEBRIQUE2_COLLISIONS_H

#include <stdbool.h>

void  CollisionBalleJoueur(struct balle *BalleDuJeu, struct joueur *MonJoueur);
void DestructionBrique(struct bloc *blocs, size_t nbBlocs);
void CollisionBalleBloc(struct balle *BalleDuJeu, struct bloc *blocs, size_t nbBlocs, struct joueur *MonJoueur);