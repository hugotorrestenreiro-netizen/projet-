#include "renderer.h"
#include <stdio.h>

GameView* init_view(int width, int height) {
    GameView *view = malloc(sizeof(GameView));
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur SDL: %s\n", SDL_GetError());
        return NULL;
    }

    view->window = SDL_CreateWindow("Mon Jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    view->renderer = SDL_CreateRenderer(view->window, -1, SDL_RENDERER_ACCELERATED);

    if (!view->window || !view->renderer) {
        printf("Erreur Fenetre/Renderer: %s\n", SDL_GetError());
        return NULL;
    }

    return view;
}

void draw_game(GameView *view, character *chara, room *salle) {

    SDL_SetRenderDrawColor(view->renderer, 0, 0, 0, 255);
    SDL_RenderClear(view->renderer);

    SDL_Rect floor_rect = {0, (int)salle->floor_level, 800, 50}; 
    SDL_SetRenderDrawColor(view->renderer, 34, 139, 34, 255); // Vert forêt
    SDL_RenderFillRect(view->renderer, &floor_rect);

    SDL_Rect char_rect = {
        (int)chara->pos.pos_x, 
        (int)chara->pos.pos_y, 
        (int)chara->pos.large, 
        (int)chara->pos.haut
    };
    SDL_SetRenderDrawColor(view->renderer, 220, 20, 60, 255); // Rouge vif
    SDL_RenderFillRect(view->renderer, &char_rect);


    SDL_RenderPresent(view->renderer);
}

void close_view(GameView *view) {
    SDL_DestroyRenderer(view->renderer);
    SDL_DestroyWindow(view->window);
    SDL_Quit();
    free(view);
}