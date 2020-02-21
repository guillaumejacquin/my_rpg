/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** epi
*/

#include "rpg.h"

void munster1(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur11 >= 9)
        my_level1->life1 = 1;
    if (my_level1->life1 == 1) {
        my_level1->pos_munster1_1.y = 2190;
        my_level1->compteur11 = 0;
        if (my_level1->pos_boule1.x < 00)
            my_level1->pos_boule1.y = -2000;
    }
    if (my_level1->pos_boule1.x < -80 && my_level1->pos_boule1.x >
        -120 &&  my_level1->life1 == 0)
        my_level1->pos_boule1.x = my_level1->pos_munster1_1.x - 40;
    if (my_level1->pos_boule1.x < my_level1->pos_heroes.x + 20
    && my_level1->pos_boule1.x >
        my_level1->pos_heroes.x  - 20 && my_level1->pos_boule1.y
        == my_level1->pos_heroes.y
        &&  my_level1->life1 == 0) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule1.x = my_level1->pos_munster1_1.x - 40;
    }
    munster111(my_struct, my_level1);
}

void munster111(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_1.x
        + 20 && my_level1->pos_attackl.x >
        my_level1->pos_munster1_1.x - 20
        && my_level1->pos_attackl.y == my_level1->pos_munster1_1.y - 20) {
        my_level1->compteur11 = my_level1->compteur11 +
            my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}