/*
** EPITECH PROJECT, 2019
** depla
** File description:
** deplacements
*/

#include "rpg.h"

void gameplay_haut2(rpg_t *my_struct, level2_t *my_level2)
{
    float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyUp) {
        my_level2->haut = 1;

        my_level2->pos_heroes2.y =  my_level2->pos_heroes2.y - y;
        if (my_level2->pos_heroes2.y < 600)
            my_level2->pos_heroes2.y =  my_level2->pos_heroes2.y + y;
        my_level2->pos_up.y = my_level2->pos_heroes2.y;
    } else if(my_level2->bas != 1) {
        my_level2->pos_heroes2.y = 700;
        my_level2->haut = 0;
    }
}

void gameplay_bas2(rpg_t *my_struct, level2_t *my_level2)
{
   float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyDown) {
        my_level2->bas = 1;
        my_level2->pos_heroes2.y =  my_level2->pos_heroes2.y + y;
        if (my_level2->pos_heroes2.y > 800)
        my_level2->pos_heroes2.y =  my_level2->pos_heroes2.y - y;
        my_level2->pos_up.y = my_level2->pos_heroes2.y;
    }
    else if (my_level2->haut != 1) {
        my_level2->pos_heroes2.y = 700;
        my_level2->bas = 0;
    }
}
