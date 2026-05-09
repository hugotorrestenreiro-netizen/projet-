#include <SDL2/SDL.h>
#include <stdio.h>

character *create_char (double spawn_x,double spawn_y){
    character *chara = calloc (1, sizeof(character))
    if (chara == NULL){
        return NULL;
    }
    chara->pos.pos_x = spawn_x;                                   //Initialisation du personnage (au lancement du jeu)
    chara->pos.pos_y = spawn_y;
    chara->pos.haut = CHAR_HEIGHT;
    chara->pos.large = CHAR_WIDTH;
    return chara;
}

void chara_move (character *chara){
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
    if (state[SDL_SCANCODE_UP]){
        if(state[SDL_SCANCODE_DOWN]){
            chara->speed_y = 0.0;
        }
        else{
            chara->speed_y = -10.0;
        }
    }
}

bool chara_