/*
** EPITECH PROJECT, 2019
** attack
** File description:
** rpg
*/

#include "rpg.h"

void quitlevel1(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->life1 == 1 && my_level1->life2 == 1 && my_level1->life3
        == 1 && my_level1->life_munster1 == 1
        && my_level1->pos_heroes.x > 1460) {
    my_struct->accept = 1;
    my_struct->menu = 1;
    my_struct->quit_forge = 1;
    my_struct->world = 0;
    my_struct->quitlevel = 0;
    my_struct->argent = my_struct->argent + 1000;
    sfSound_destroy(my_level1->sound);
    }
}

void munster3(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur3 >= 9)
        my_level1->life3 = 1;
    if (my_level1->life3 == 1) {
        my_level1->pos_munster1_3.y = 2190;
        my_level1->compteur3 = 0;
        if (my_level1->pos_boule3.x < 00)
            my_level1->pos_boule3.y = -2000;
    }
    if (my_level1->pos_boule3.x < -20 &&  my_level1->life3 == 0)
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    if (my_level1->pos_boule3.x < -110 && my_level1->pos_boule3.x > -130)
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    if (my_level1->pos_boule3.x < my_level1->pos_heroes.x
        + 20 && my_level1->pos_boule3.x >
        my_level1->pos_heroes.x - 20 && my_level1->pos_boule3.y ==
        my_level1->pos_heroes.y &&  my_level1->life3 != 1) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    }
    animm3s(my_struct, my_level1);
}

void animm3s(rpg_t *my_struct, level1_t *my_level1)
{
if (my_level1->pos_attackl.x < my_level1->pos_munster1_3.x
        + 20 && my_level1->pos_attackl.x
        > my_level1->pos_munster1_3.x - 20 && my_level1->pos_attackl.y
        == my_level1->pos_munster1_3.y - 20) {
        my_level1->compteur3 = my_level1->compteur3 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}

void munster2(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur2 >= 9)
        my_level1->life2 = 1;
    if (my_level1->life2 == 1) {
        my_level1->pos_munster1_2.y = 2190;
        my_level1->compteur2 = 0;
        if (my_level1->pos_boule2.x < 00)
            my_level1->pos_boule2.y = -2000;
    }
    if (my_level1->pos_boule2.x < -110 &&
        my_level1->pos_boule1.x > -130 &&  my_level1->life2 == 0)
        my_level1->pos_boule2.x = my_level1->pos_munster1_2.x - 40;
    if (my_level1->pos_boule2.x < my_level1->pos_heroes.x + 20 &&
        my_level1->pos_boule2.x > my_level1->pos_heroes.x - 20 &&
        my_level1->pos_boule2.y == my_level1->pos_heroes.y &&
        my_level1->life2 == 0) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule2.x = my_level1->pos_munster1_1.x - 40;
    }
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_2.x + 20 &&
        my_level1->pos_attackl.x > my_level1->pos_munster1_2.x - 20 &&
        my_level1->pos_attackl.y == my_level1->pos_munster1_2.y - 20) {
        my_level1->compteur2 = my_level1->compteur2 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
    munster23(my_struct, my_level1);
}

void munster23(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_2.x + 20 &&
        my_level1->pos_attackl.x > my_level1->pos_munster1_2.x - 20 &&
        my_level1->pos_attackl.y == my_level1->pos_munster1_2.y - 20) {
        my_level1->compteur2 = my_level1->compteur2 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_2.x + 20 &&
        my_level1->pos_attackl.x > my_level1->pos_munster1_2.x - 20 &&
        my_level1->pos_attackl.y == my_level1->pos_munster1_2.y - 20) {
        my_level1->compteur2 = my_level1->compteur2 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}