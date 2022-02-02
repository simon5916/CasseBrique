#ifndef CASSEBRIQUE2_STRUCTURES_H
#define CASSEBRIQUE2_STRUCTURES_H
struct balle{
    int x;
    int y;
    int h;
    int w;
    int speedx;
    int speedy;
};

struct bloc{
    int x;
    int y;
    int h;
    int w;
    int solidite;
};

struct joueur{
    int x;
    int y;
    int h;
    int w;
    int nbPoint;
    int nbVie;
    int speedx;
};
#endif //CASSEBRIQUE2_STRUCTURES_H
