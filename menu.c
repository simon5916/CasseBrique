#include <stdio.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include "menu.h"
#include <SDL_main.h>
#include "gameloop.h"

void menuDuJeu(SDL_Renderer *renderer) {
    int selectedMenu = 0;
    SDL_Event event;
    SDL_bool menuInitiated = false;
    SDL_bool quit = false;
    SDL_Color greenColor = {0, 255, 0};
    SDL_Color blueColor = {0, 0, 255};

    TTF_Font *police = NULL;
    char* path = realpath(".", NULL);
    printf("path[%s]n", path);
    police = TTF_OpenFont(
            "../../victoria_typewriter/Victoria Typewriter Regular.ttf",
            40
    );

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type != SDL_KEYDOWN && menuInitiated) continue;
            else if(event.type == SDL_QUIT) { quit = true; break; }

            switch (event.key.keysym.sym) {
                default:
                    SDL_RenderClear(renderer);
                    break;
                case SDLK_DOWN:
                    selectedMenu = (selectedMenu + 1) % 3;
                    break;
                case SDLK_UP:
                    selectedMenu = (selectedMenu - 1) % 3;
                    if (selectedMenu == -1) selectedMenu = 2;
                    break;
                case SDLK_SPACE: {
                    switch (selectedMenu) {
                        case 0:
                            SDL_RenderClear(renderer);
                            menuNiveaux(renderer);
                            SDL_RenderClear(renderer);
                            break;
                        case 1:
                            printf("Options\n");
                            menuOption(renderer );
                            break;
                        case 2:
                            quit = true;
                            break;
                    }
                    break;
                }
            }

            SDL_RenderClear(renderer);
            // Print menu
            generateMenuItem(renderer, police, selectedMenu == 0 ? &blueColor : &greenColor, 510, 170, "Jouer");
            generateMenuItem(renderer, police, selectedMenu == 1 ? &blueColor : &greenColor, 510, 270, "Options");
            generateMenuItem(renderer, police, selectedMenu == 2 ? &blueColor : &greenColor, 510, 370, "Quitter");

            SDL_RenderPresent(renderer);

            menuInitiated = true;
        }
    }
}

void menuNiveaux(SDL_Renderer *renderer) {
    int selectedMenu2 = 0;
    SDL_Event event;
    SDL_bool menuInitiated = false;
    SDL_bool quit = false;
    SDL_Color greenColor = {0, 255, 0};
    SDL_Color blueColor = {0, 0, 255};

    TTF_Font *police = NULL;
    police = TTF_OpenFont(
            "../../victoria_typewriter/Victoria Typewriter Regular.ttf",
            40
    );

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type != SDL_KEYDOWN && menuInitiated){continue;}
            else if(event.type == SDL_QUIT) { quit = true; break; }

            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                    selectedMenu2 = (selectedMenu2 + 1) % 3;
                    break;
                case SDLK_UP:
                    selectedMenu2 = (selectedMenu2 - 1) % 3;
                    if (selectedMenu2 == -1) selectedMenu2 = 2;
                    break;
                case SDLK_SPACE: {
                    switch (selectedMenu2) {
                        case 0:
                            SDL_RenderClear(renderer);
                            gameloop(renderer);
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                            SDL_RenderClear(renderer);
                            break;
                        case 1:
                            SDL_RenderClear(renderer);
                            gameloop2(renderer);
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                            SDL_RenderClear(renderer);
                            break;
                        default:
                            quit = true;
                            break;
                    }
                    break;
                }
            }
            SDL_RenderClear(renderer);
            // Print menu
            generateMenuItem(renderer, police, selectedMenu2 == 0 ? &blueColor : &greenColor, 510, 170, "Niveau 1");
            generateMenuItem(renderer, police, selectedMenu2 == 1 ? &blueColor : &greenColor, 510, 270, "Niveau 2");
            generateMenuItem(renderer, police, selectedMenu2 == 2 ? &blueColor : &greenColor, 510, 370, "Retour");

            SDL_RenderPresent(renderer);

            menuInitiated = true;
        }
    }
}

void menuOption(SDL_Renderer *renderer){
    SDL_Event event;
    SDL_bool menuOptionInitiated = false;
    SDL_bool quit = false;
    SDL_Color greenColor = {0, 255, 0};
    SDL_Color blueColor = {0, 0, 255};
    int selectedOption = 0;

    TTF_Font *police = NULL;
    police = TTF_OpenFont(
            "../../victoria_typewriter/Victoria Typewriter Regular.ttf",
            40
    );
    SDL_RenderClear(renderer);

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type != SDL_KEYDOWN && menuOptionInitiated){continue;}
            else if(event.type == SDL_QUIT) { quit = true; break; }

            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                    selectedOption = (selectedOption + 1) % 3;
                    break;
                case SDLK_UP:
                    selectedOption= (selectedOption - 1) % 3;
                    if (selectedOption == -1) selectedOption = 2;
                    break;
                case SDLK_SPACE: {
                    switch (selectedOption) {
                        case 0:
                            SDL_RenderClear(renderer);
                            SDL_SetRenderDrawColor(renderer, 170, 125, 206, 255);
                            SDL_RenderClear(renderer);
                            quit =true;
                            break;
                        case 1:
                            quit = true;
                            break;
                    }
                    break;
                }
            }
            SDL_RenderClear(renderer);
            // Print menu
            generateMenuItem(renderer, police, selectedOption == 0 ? &blueColor : &greenColor, 510, 170, "fond mauve");
            generateMenuItem(renderer, police, selectedOption == 1 ? &blueColor : &greenColor, 510, 270, "Retour");

            SDL_RenderPresent(renderer);

            menuOptionInitiated = true;
        }
    }





}

void generateMenuItem(SDL_Renderer *renderer, TTF_Font *police, SDL_Color *color, int x, int y, const char *text) {
    SDL_Surface *playText = TTF_RenderText_Blended(police, text, *color);
    SDL_Texture *playTexture = SDL_CreateTextureFromSurface(renderer, playText);
    SDL_Rect playRect = {x, y, 80, 40};
    SDL_RenderCopy(renderer, playTexture, NULL, &playRect);
}