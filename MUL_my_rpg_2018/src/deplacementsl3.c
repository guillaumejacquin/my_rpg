/*
** EPITECH PROJECT, 2019
** deplac
** File description:
** dm
*/

#include "rpg.h"

void gameplay_haut3(rpg_t *my_struct, level3_t *my_level3)
{
    float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyUp) {
        my_level3->haut = 1;
        my_level3->pos_heroes3.y =  my_level3->pos_heroes3.y - y;
        if (my_level3->pos_heroes3.y < 600)
            my_level3->pos_heroes3.y =  my_level3->pos_heroes3.y + y;
        my_level3->pos_up.y = my_level3->pos_heroes3.y;
    } else if(my_level3->bas != 1) {
        my_level3->pos_heroes3.y = 700;
        my_level3->haut = 0;
    }
}

void gameplay_bas3(rpg_t *my_struct, level3_t *my_level3)
{
    float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyDown) {
        my_level3->bas = 1;
        my_level3->pos_heroes3.y =  my_level3->pos_heroes3.y + y;
        if (my_level3->pos_heroes3.y > 800)
            my_level3->pos_heroes3.y =  my_level3->pos_heroes3.y - y;
        my_level3->pos_up.y = my_level3->pos_heroes3.y;
    }
    else if (my_level3->haut != 1) {
        my_level3->pos_heroes3.y = 700;
        my_level3->bas = 0;
    }
}
