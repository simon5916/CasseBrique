#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include "gameloop.h"
#include "menu.h"

int main(int argc, char* argv[]){
    bool win = true;
    bool status = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int statut = EXIT_FAILURE;
    window = SDL_CreateWindow("BrickBreaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1080, 720, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
    statut = EXIT_SUCCESS;
    TTF_Init();


    menuDuJeu(renderer);
    Quit:
    TTF_Quit();
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}