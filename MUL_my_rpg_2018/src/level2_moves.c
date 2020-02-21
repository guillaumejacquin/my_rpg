/*
** EPITECH PROJECT, 2019
** move
** File description:
** for level2
*/

#include "rpg.h"

void movement_for_heroes2(rpg_t *my_struct, level2_t *my_level2)
{
    static int a = 0;

    if (my_level2->pos_heroes2.x >= 1520 && a < 4) {
        a = a + 1;
        my_level2->pos_heroes2.x = 50;
    }
    if (my_level2->pos_heroes2.x >= 1520 && a == 4) {
        my_level2->pos_heroes2.x = 1520;
    }
    if (my_level2->pos_heroes2.x < 0 && a > 0) {
        a = a - 1;
        my_level2->pos_heroes2.x = 50;
    }
    if (my_level2->pos_heroes2.x < 0 && a == 0)
        my_level2->pos_heroes2.x = 50;
    transition_for_heroes2(my_struct, my_level2, a);
}

void transition_for_heroes2(rpg_t *my_struct, level2_t *my_level2, int a)
{
    if (a == 0)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level2->background, NULL);
    if (a == 1)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level2->background2, NULL);
    if (a == 2)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level2->background3, NULL);
    if (a == 3)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level2->background4, NULL);
    if (a == 4)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level2->background5, NULL);
}
