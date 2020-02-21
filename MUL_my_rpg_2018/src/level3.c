/*
** EPITECH PROJECT, 2019
** level3
** File description:
** level3
*/

#include "rpg.h"

void set_my_level3(level3_t *my_level3)
{
    my_level3->background3 = set_sprite("asset/level/Boss/level3_Plan1.png");
    my_level3->monster3 = set_sprite("asset/monstre/boss_1.png");
    my_level3->heroes3 = set_sprite("asset/perso/perso1.png");
    my_level3->attack3 = set_sprite("asset/monstre/attackboss.png");
    my_level3->pos_attack3.x = 900;
    my_level3->pos_attack3.y = 700;
    my_level3->pos_heroes3.x = 675;
    my_level3->pos_heroes3.y = 700;
    my_level3->rectheroes3.top = 00;
    my_level3->rectheroes3.left = 00;
    my_level3->rectheroes3.height = 100;
    my_level3->rectheroes3.width = 70;
    my_level3->pos_monster3.x = 1050;
    my_level3->pos_monster3.y = 700;
    my_level3->rectmonster3.top = 00;
    my_level3->rectmonster3.left = 00;
    my_level3->rectmonster3.height = 100;
    my_level3->rectmonster3.width = 80;
    my_level3->clock3 = sfClock_create();
    my_level3->clock4 = sfClock_create();
}

void attack(level3_t *my_level3, rpg_t *my_struct)
{

}

void anim_boss(level3_t *my_level3, rpg_t *my_struct)
{
    my_level3->time4 = sfClock_getElapsedTime(my_level3->clock4);
    if (my_level3->time4.microseconds < 100000) {
        my_level3->rectmonster3.left = 0;
        attack(my_level3, my_struct);
    }
    if (my_level3->time4.microseconds< 300000 &&
        my_level3->time4.microseconds > 100000) {
        my_level3->rectmonster3.left = 60;
        attack(my_level3, my_struct);
        }
    if (my_level3->time4.microseconds < 500000 &&
        my_level3->time4.microseconds > 300000) {
        my_level3->rectmonster3.left = 120;
        attack(my_level3, my_struct);
    }
    if (my_level3->time4.microseconds < 700000 &&
        my_level3->time4.microseconds > 500000) {
        my_level3->rectmonster3.left = 180;
        attack(my_level3, my_struct);
        }
    if (my_level3->time4.microseconds > 700000)
        sfClock_restart (my_level3->clock4);
}

void anim_heroes3(level3_t *my_level3)
{
    my_level3->time3 = sfClock_getElapsedTime(my_level3->clock3);
    if (my_level3->time3.microseconds < 200000)
        my_level3->rectheroes3.left = 0;
    if (my_level3->time3.microseconds< 400000 &&
        my_level3->time3.microseconds > 200000)
        my_level3->rectheroes3.left = 55;
    if (my_level3->time3.microseconds < 600000 &&
        my_level3->time3.microseconds > 400000)
        my_level3->rectheroes3.left = 135;
    if (my_level3->time3.microseconds > 600000)
        sfClock_restart (my_level3->clock3);
}

void in_level3(rpg_t *my_struct, level3_t *my_level3)
{
    sfSprite_setTextureRect(my_level3->heroes3, my_level3->rectheroes3);
    anim_heroes3(my_level3);
    sfRenderWindow_drawSprite(my_struct->window, my_level3->background3, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_level3->monster3, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_level3->heroes3, NULL);
    sfSprite_setPosition(my_level3->heroes3, my_level3->pos_heroes3);
    sfSprite_setTextureRect(my_level3->monster3, my_level3->rectmonster3);
    sfSprite_setPosition(my_level3->monster3, my_level3->pos_monster3);
    sfSprite_setPosition(my_level3->attack3, my_level3->pos_attack3);
    anim_boss(my_level3, my_struct);
    deplacement_heroes_level3(my_struct, my_level3);
    movement_for_heroes3(my_level3);
}
