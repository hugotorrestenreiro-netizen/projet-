#include <SDL2/SDL.h>
#include <stdio.h>
#include "physic.h"

character *create_char (double spawn_x,double spawn_y){
    character *chara = calloc (1, sizeof(character));
    if (chara == NULL){
        return NULL;
    }
    chara->pos.pos_x = spawn_x;                                   //Initialisation du personnage (au lancement du jeu)
    chara->pos.pos_y = spawn_y;
    chara->pos.haut = CHAR_HEIGHT;
    chara->pos.large = CHAR_WIDTH;
    chara->speed_y = 10.0;
    chara->speed_x = 0.0;
    return chara;
}

void chara_move (character *chara, room *salle){
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (!state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_UP]&& !state[SDL_SCANCODE_DOWN]){
        chara->speed_x = 0.0;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        if (state[SDL_SCANCODE_LEFT]){
                chara->speed_x = 0.0;
        }
        else{
            chara->speed_x = 5.0;
        }
    }
    else if (state[SDL_SCANCODE_LEFT]){                 //Déplacement selon la direction
        chara->speed_x = -5.0;
    }
    if (state[SDL_SCANCODE_UP] && chara_in_ground(chara,salle)){
        if(state[SDL_SCANCODE_DOWN]){
            chara->speed_y = 0.0;
        }
        else {
            chara->speed_y = -10.0;
        }
    }
}

bool chara_in_ground(character *chara, room *salle){
    if(chara == NULL || salle == NULL){
        return false;
    }
    double foot_chara = chara->pos.pos_y + chara->pos.haut;
    if(foot_chara >= salle->floor_level){
        return true;
    }
    else{
        return false;
    }
}

bool collision(hbox hbox1, hbox hbox2){
    bool collision_x = (hbox1.pos_x < hbox2.pos_x + hbox2.large) && 
                       (hbox1.pos_x + hbox1.large > hbox2.pos_x);

    bool collision_y = (hbox1.pos_y < hbox2.pos_y + hbox2.haut) && 
                       (hbox1.pos_y + hbox1.haut > hbox2.pos_y);

    if(collision_x && collision_y){
        return true;
    }
    else{
        return false;
    }
}