/*
** EPITECH PROJECT, 2019
** level2
** File description:
** level2
*/

#include "rpg.h"

void set_my_level2(level2_t *my_level2)
{
    my_level2->background = set_sprite("asset/level/level2/level2_Plan1.png");
    my_level2->background2 = set_sprite("asset/level/level2/level2_Plan2.png");
    my_level2->background3 = set_sprite("asset/level/level2/level2_Plan3.png");
    my_level2->background4 = set_sprite("asset/level/level2/level2_Plan4.png");
    my_level2->background5 = set_sprite("asset/level/level2/level2_Plan5.png");
    my_level2->monster2 = set_sprite("asset/monstre/monster1.gif");
    my_level2->heroes2 = set_sprite("asset/perso/perso1.png");
    my_level2->pos_heroes2.x = 50;
    my_level2->pos_heroes2.y = 700;
    my_level2->rectheroes2.top = 0;
    my_level2->rectheroes2.left = 0;
    my_level2->rectheroes2.height = 120;
    my_level2->rectheroes2.width = 70;
    my_level2->clock2 = sfClock_create();
}

void anim_heroes2(level2_t *my_level2)
{
    my_level2->time2 = sfClock_getElapsedTime(my_level2->clock2);
    if (my_level2->time2.microseconds < 200000) {
        my_level2->rectheroes2.left = 0;
    }
    if (my_level2->time2.microseconds< 400000 &&
        my_level2->time2.microseconds > 200000) {
        my_level2->rectheroes2.left = 55;
    }
    if (my_level2->time2.microseconds < 600000 &&
        my_level2->time2.microseconds > 400000)
        my_level2->rectheroes2.left = 135;
    if (my_level2->time2.microseconds > 600000) {
        sfClock_restart (my_level2->clock2);
    }
}

void deplacement_heroes_level2(rpg_t *my_struct, level2_t *my_level2)
{
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyRight) {
        my_level2->pos_heroes2.x = my_level2->pos_heroes2.x + 1;
    }
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyLeft) {
        my_level2->pos_heroes2.x = my_level2->pos_heroes2.x - 1.5;
    }
}

void in_level2(rpg_t *my_struct, level2_t *my_level2)
{
    sfSprite_setTextureRect(my_level2->heroes2, my_level2->rectheroes2);
    anim_heroes2(my_level2);
    movement_for_heroes2(my_struct, my_level2);
    sfRenderWindow_drawSprite(my_struct->window, my_level2->heroes2, NULL);
    sfSprite_setPosition(my_level2->heroes2, my_level2->pos_heroes2);
}

