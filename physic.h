#ifndef PHYSIC_H
#define PHYSIC_H

#include <stdbool.h>

typedef struct {
    double pos_x;
    double pos_y;
    double haut;
    double large;
}hbox;

typedef enum{
    NORMAL
}buff;

typedef struct{
    hbox pos;
    double speed_x;
    double speed_y;
    int health;
    buff state;
}character;

typedef struct{
    double floor_level;
    int level;
}room;

#define CHAR_HEIGHT 100.0

#define CHAR_WIDTH 50.0

#define STANDARD_FLOOR_HEIGHT 500.0


character *create_char (double spawn_x,double spawn_y);

void chara_move (character *chara);

bool chara_in_ground(character *chara, room *salle);

bool collision(hbox hbox1, hbox hbox2);

#endif



