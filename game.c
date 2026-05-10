#include <physic.h>


room *create_room(int room_id){
    room *salle = calloc(1,sizeof(room));
    switch (room_id){
        case 1:
            salle->floor_level = 500;
            salle->level = 1;
        case 2:
            salle->floor_level = 600;
            salle->level = 2;
        case 3:
            salle->floor_level = 700;
            salle->level = 1;
        case 4:
            salle->floor_level = 400;
            salle->level = 1;
        default:
            salle ->floor_level = 100;
            salle->level = 0;

    }
    return salle;
}