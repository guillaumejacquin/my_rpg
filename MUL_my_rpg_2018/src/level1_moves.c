/*
** EPITECH PROJECT, 2019
** add moves for level1.c
** File description:
** .
*/

#include "rpg.h"

void movement_for_heroes(rpg_t *my_struct, level1_t *my_level1)
{
    static int a = 0;

    if (my_level1->pos_heroes.x >= 1520 && a < 2) {
        a = a + 1;
        my_level1->pos_heroes.x = 50;
    }
    if (my_level1->pos_heroes.x >= 1520 && a >= 2)
        my_level1->pos_heroes.x = 1520;
    if (my_level1->pos_heroes.x < 0 && a > 0) {
        a = a - 1;
        my_level1->pos_heroes.x = 200;
    }
    if (my_level1->pos_heroes.x < 0 && a == 0)
        my_level1->pos_heroes.x = 0;
    transition_for_heroes(my_struct, my_level1, a);
    monster(my_struct, my_level1, a);
}

void transition_for_heroes(rpg_t *my_struct, level1_t *my_level1, int a)
{
    if (a == 0)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level1->background, NULL);
    else if (a == 1)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level1->background2, NULL);
    else if (a == 2)
        sfRenderWindow_drawSprite(my_struct->window,
                                   my_level1->background3, NULL);
}

void attack_1(level1_t *my_level1, rpg_t *my_struct)
{
    int a = 0;

    if (a == 0) {
        sfRenderWindow_drawSprite(my_struct->window, my_level1->attack, NULL);
        a = 1;
    }
    if (a == 1)
    {
        my_level1->pos_attack.x = my_level1->pos_attack.x - 50;
        if (my_level1->pos_attack.x == my_level1->pos_heroes.x){}
        if (my_level1->pos_attack.x <= 0)
            my_level1->pos_attack.x = 680;
    }
}

void anim_munster(level1_t *my_level1, rpg_t *my_struct)
{
    attack_1(my_level1, my_struct);
    if (my_level1->time1.microseconds < 100000)
        my_level1->rectmunster1.left = 0;
    if (my_level1->time1.microseconds< 200000 &&
        my_level1->time1.microseconds > 100000)
        my_level1->rectmunster1.left = 65;
    if (my_level1->time1.microseconds < 300000 &&
        my_level1->time1.microseconds > 200000)
        my_level1->rectmunster1.left = 130;
    if (my_level1->time1.microseconds < 400000 &&
        my_level1->time1.microseconds > 300000)
        my_level1->rectmunster1.left = 195;
    if (my_level1->time1.microseconds < 500000 &&
        my_level1->time1.microseconds > 400000)
        my_level1->rectmunster1.left = 255;
    if (my_level1->time1.microseconds < 800000 &&
        my_level1->time1.microseconds > 500000)
        my_level1->rectmunster1.left = 320;
    if (my_level1->time1.microseconds > 1000000)
        sfClock_restart (my_level1->clock1);
}

void monster(rpg_t *my_struct, level1_t *my_level1, int a)
{
    if (a == 0) {
        sfRenderWindow_drawSprite(my_struct->window, my_level1->munster1, NULL);
        sfSprite_setPosition(my_level1->munster1, my_level1->pos_munster1);
        sfSprite_setTextureRect(my_level1->munster1, my_level1->rectmunster1);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_level1->attack_monster1, NULL);
        sfSprite_setPosition(my_level1->attack_monster1,
                             my_level1->pos_attack_monster1);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_level1->attack_monster1, NULL);
        sfSprite_setPosition(my_level1->attack_monster1,
                             my_level1->pos_attack_monster1);
        my_level1->pos_attack_monster1.x =
            my_level1->pos_attack_monster1.x - 0.75;
        if (my_level1->pos_attack_monster1.x < -100 &&
            my_level1->life_munster1 == 0)
            my_level1->pos_attack_monster1.x = my_level1->pos_munster1.x - 40;
        if (my_level1->pos_attack_monster1.x <= my_level1->pos_heroes.x + 30 &&
            my_level1->pos_attack_monster1.x >= my_level1->pos_heroes.x - 30 &&
            my_level1->pos_attack_monster1.y == my_level1->pos_heroes.y + 0) {
            my_level1->pos_attack_monster1.x = my_level1->pos_munster1.x - 40;
            my_struct->life = my_struct->life - 1;
            if (my_struct->life == 0)
                my_struct->menu = 2;
        }
    }
    monster2(my_struct, my_level1, a);
}
