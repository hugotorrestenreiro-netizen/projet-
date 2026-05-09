character *create_char (double spawn_x,double spawn_y){
    character *chara = calloc (1, sizeof(character))
    if (chara == NULL){
        return;
    }
    chara->pos.pos_x = spawn_x;
    chara->pos.pos_y = spawn_y;
    chara->pos.haut = CHAR_HEIGHT;
    chara->pos.large = CHAR_WIDTH;
    return chara;
}