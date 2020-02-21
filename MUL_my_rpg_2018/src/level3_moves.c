/*
** EPITECH PROJECT, 2019
** move
** File description:
** move
*/

#include "rpg.h"

void movement_for_heroes3(level3_t *my_level3)
{
    if (my_level3->pos_heroes3.x >= 1520)
        my_level3->pos_heroes3.x = 1520;
    if (my_level3->pos_heroes3.x < 0)
        my_level3->pos_heroes3.x = 0;
}

void deplacement_heroes_level3(rpg_t *my_struct, level3_t *my_level3)
{
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyRight) {
        my_level3->pos_heroes3.x = my_level3->pos_heroes3.x + 1.5;
    }
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyLeft) {
        my_level3->pos_heroes3.x = my_level3->pos_heroes3.x - 1.5;
    }
}
