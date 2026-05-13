#include "renderer.h"
#include <stdio.h>
#include <stdlib.h>

GameView* init_view(int width, int height) {
    GameView *view = malloc(sizeof(GameView));
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur SDL: %s\n", SDL_GetError());
        return NULL;
    }

    view->window = SDL_CreateWindow("Projet", 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    width, height, 
                                    SDL_WINDOW_RESIZABLE);

    view->renderer = SDL_CreateRenderer(view->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(view->renderer, 800, 600);

    return view;
}

void draw_game(GameView *view, character *chara, room *salle) {

    SDL_SetRenderDrawColor(view->renderer, 15, 15, 35, 255);
    SDL_RenderClear(view->renderer);



    SDL_Rect earth = {0, (int)salle->floor_level, 800, 600};
    SDL_SetRenderDrawColor(view->renderer, 70, 40, 15, 255);
    SDL_RenderFillRect(view->renderer, &earth);


    SDL_Rect grass = {0, (int)salle->floor_level, 800, 10};
    SDL_SetRenderDrawColor(view->renderer, 30, 180, 30, 255);
    SDL_RenderFillRect(view->renderer, &grass);


    SDL_Rect char_rect = {
        (int)chara->pos.pos_x, 
        (int)chara->pos.pos_y, 
        (int)chara->pos.large, 
        (int)chara->pos.haut
    };
    
 
    SDL_SetRenderDrawColor(view->renderer, 200, 30, 30, 255);
    SDL_RenderFillRect(view->renderer, &char_rect);
    
 
    SDL_SetRenderDrawColor(view->renderer, 255, 255, 255, 255); // Blanc
    SDL_RenderDrawRect(view->renderer, &char_rect);


    SDL_RenderPresent(view->renderer);
}

void close_view(GameView *view) {
    if (view) {
        SDL_DestroyRenderer(view->renderer);
        SDL_DestroyWindow(view->window);
        SDL_Quit();
        free(view);
    }
}