#include "menu.h"
#include "gameloop.h"
#include "structures.h"
#include <SDL_ttf.h>
void affichageScoreEtVie(SDL_Renderer *renderer, struct joueur MonJoueur ) {

    SDL_Rect squareScore = {500, 500, 100,
                      100};

    char scoreJoueur [20];
    char NbViesRestantes [20];
    SDL_Color couleurBlanche={255,255,255};
    TTF_Font *policeScore = NULL;
    policeScore = TTF_OpenFont(
            "../../victoria_typewriter/Victoria Typewriter Regular.ttf",
            40
    );
    sprintf(scoreJoueur, " Score: %d", MonJoueur.nbPoint);
    sprintf(NbViesRestantes, " Vies: %d", MonJoueur.nbVie);

    SDL_Surface *playText = TTF_RenderText_Blended(policeScore, scoreJoueur, couleurBlanche);
    SDL_Texture *playTexture = SDL_CreateTextureFromSurface(renderer, playText);
    SDL_Rect playRect = {0, 675, 80, 40};
    SDL_RenderCopy(renderer, playTexture, NULL, &playRect);

    playText = TTF_RenderText_Blended(policeScore, NbViesRestantes, couleurBlanche);
    playTexture = SDL_CreateTextureFromSurface(renderer, playText);
    SDL_Rect playRect2 = {100, 675, 80, 40};
    SDL_RenderCopy(renderer, playTexture, NULL, &playRect2);
}

void remplirBlocs(struct bloc *pBloc, struct bloc bloc1);

void Affichage(SDL_Renderer *renderer, struct bloc *blocs, size_t nbBlocs) {
    for (int i = 0; i < nbBlocs; i++) {
        SDL_Rect PremierBloc = {
                blocs[i].x,
                blocs[i].y,
                blocs[i].h,
                blocs[i].w
        };
        if (blocs[i].solidite == 1) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        }
        SDL_RenderFillRect(renderer, &PremierBloc);
    }
}


void launchParty(SDL_Renderer *renderer, struct balle BalleDuJeu, struct joueur MonJoueur, struct bloc *blocs, size_t nbBlocs) {
    int lastTimer = SDL_GetTicks();
    SDL_Event event;
    SDL_bool right = false;
    SDL_bool left = false;
    SDL_bool quit = false;
    SDL_RenderPresent(renderer); // affiche tout le bordel fait précédemment (blocs, joueur, balle)

    while (!quit) {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }

            DeplacementJoueur(event, &left, &right);
            MouvementJoueur(left, right, &MonJoueur);
        }
        if (SDL_GetTicks() - lastTimer > 15) {
        MouvementBalle(&BalleDuJeu, &MonJoueur);
        CollisionBalleJoueur(&BalleDuJeu, &MonJoueur);
        CollisionBalleBloc(&BalleDuJeu, blocs, 14, &MonJoueur);
            lastTimer = SDL_GetTicks();
        }
        SDL_Rect Balle = {BalleDuJeu.x, BalleDuJeu.y, BalleDuJeu.w,
                          BalleDuJeu.h}; // Les 3 lignes suivantes sont pour afficher la balle.
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderFillRect(renderer, &Balle);
        // Render blocs
        Affichage(renderer, blocs, 14);

        SDL_Rect RectangleJoueur = {MonJoueur.x, MonJoueur.y, MonJoueur.w,
                                    MonJoueur.h};   //SDL_Rect rest un type cette ligne créer la structure Rectangle joueur(rectangle)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Les 3 lignes suivantes sont pour afficher le rectange
        SDL_RenderFillRect(renderer, &RectangleJoueur);
        affichageScoreEtVie(renderer, MonJoueur );
        SDL_RenderPresent(renderer);

        if (MonJoueur.nbPoint == 1400) {
            quit = true;
            break;
        } else if (MonJoueur.nbVie == 0) {
            quit = true;
            break;
        }
    }

}

int gameloop(SDL_Renderer *renderer) {

    // Afficher le score et les vies
    struct balle BalleDuJeu = {510, 350, 25, 25, 5, 5};
    struct joueur MonJoueur = {400, 650, 25, 100, 0, 3, 50};

    struct bloc *blocs = malloc(14 * sizeof(struct bloc));
    struct bloc monBloc = {50, 30, 160, 50, 1};
    remplirBlocs(blocs, monBloc);

    launchParty(renderer, BalleDuJeu, MonJoueur, blocs, 14);
}

void remplirBlocs(struct bloc *pBloc, struct bloc bloc1) {
    struct bloc _bloc = bloc1;
    pBloc[0] = bloc1;
    bloc1.x += 170;
    pBloc[1] = bloc1;
    bloc1.x += 170;
    pBloc[2] = bloc1;
    bloc1.x += 170;
    pBloc[3] = bloc1;
    bloc1.x += 170;
    pBloc[4] = bloc1;
    bloc1.x += 170;
    pBloc[5] = bloc1;
    bloc1.x = _bloc.x;
    bloc1.y += 60;
    pBloc[6] = bloc1;
    bloc1.x += 170;
    pBloc[7] = bloc1;
    bloc1.x += 170;
    pBloc[8] = bloc1;
    bloc1.x += 170;
    pBloc[9] = bloc1;
    bloc1.x += 170;
    pBloc[10] = bloc1;
    bloc1.x += 170;
    pBloc[11] = bloc1;
    bloc1.x = _bloc.x + 170;
    bloc1.y += 60;
    bloc1.solidite = 2;
    pBloc[12] = bloc1;
    bloc1.x += 170 * 3;
    pBloc[13] = bloc1;
}

int gameloop2(SDL_Renderer *renderer) {
    struct balle BalleDuJeu = {510, 350, 25, 25, 3, 5};
    struct joueur MonJoueur = {400, 650, 25, 100, 0, 3, 10};


    struct bloc *blocs = malloc(14 * sizeof(struct bloc));
    struct bloc monBloc = {50, 30, 160, 50, 1};
    remplirBlocs(blocs, monBloc);
    launchParty(renderer, BalleDuJeu, MonJoueur, blocs, 14);
}

