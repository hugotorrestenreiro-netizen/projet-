#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "physic.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} GameView;

GameView* init_view(int width, int height);
void draw_game(GameView *view, character *chara, room *salle);
void close_view(GameView *view);

#endif