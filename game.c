#include "physic.h"
#include <stdbool.h>


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
    room *salle = create_room(1);
    character *chara = create_char (700.0, 700.0);
    bool running = true;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = false;
            }
        }
        chara_move(chara);
        chara->hbox.speedy += 0.5;
        chara->hbox.pos_x += chara->hbox.speed_x;
        chara->hbox.pos_y += chara->hbox.speed_y;
        if(chara_in_ground(chara, salle)){
            if (chara->hbox.speed_y >= 0.0){
            chara->hbox.pos_y = salle->hbox.pos_y - chara->hbox.haut;
            }
        }
        SDL_Delay(16);
    }
    free(chara);
    free(salle);
    return 0;
}

