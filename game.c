#include "physic.h"
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "renderer.h"

room *create_room(int room_id){
    room *salle = calloc(1,sizeof(room));
    switch (room_id){
        case 1:
            salle->floor_level = 500;
            salle->level = 1;
            break;
        case 2:
            salle->floor_level = 600;
            salle->level = 2;
            break;
        case 3:
            salle->floor_level = 700;
            salle->level = 1;
            break;
        case 4:
            salle->floor_level = 400;
            salle->level = 1;
            break;
        default:
            salle ->floor_level = 100;
            salle->level = 0;
            break;
    }
    return salle;
}

int main(int argc, char* argv[]){
    GameView *view = init_view(800, 600);
    room *salle = create_room(1);
    character *chara = create_char (700.0, 700.0);
    Uint64 temps_precedent = SDL_GetPerformanceCounter();
    double dt = 0;
    bool running = true;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = false;
            }
        }
        Uint64 maintenant = SDL_GetPerformanceCounter();
        dt = (double)(maintenant - temps_precedent)/SDL_GetPerformanceFrequency();
        temps_precedent = maintenant;
        chara_move(chara,salle);
        update_physics(chara, dt, salle);
        draw_game(view, chara, salle);
        SDL_Delay(dt);
    }
    free(chara);
    free(salle);
    close_view(view);
    return 0;
}

