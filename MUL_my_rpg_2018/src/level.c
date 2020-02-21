/*
** EPITECH PROJECT, 2019
** level.c
** File description:
** level
*/

#include "rpg.h"

void set_level(level_t *my_level)
{
    my_level->word = 0;
    my_level->x = 0;
    my_level->background = set_sprite("asset/level/fondlevel.jpg");
    my_level->shop = set_sprite("asset/level/shop.png");
    my_level->pos_shop.x = 250;
    my_level->pos_shop.y = 200;
    my_level->level1 = set_sprite("asset/level/level1.png");
    my_level->pos_lev1.x = 1000;
    my_level->pos_lev1.y = 200;
    my_level->level2 = set_sprite("asset/level/level2.png");
    my_level->pos_lev2.x = 500;
    my_level->pos_lev2.y = 200;
    my_level->level3 = set_sprite("asset/level/level3.png");
    my_level->pos_lev3.x = 750;
    my_level->pos_lev3.y = 200;
}

void set_my_level(rpg_t *my_struct, level_t *my_level)
{
    if (my_struct->world == 0) {
        sfRenderWindow_drawSprite(my_struct->window,
        my_level->background, NULL);
        sfSprite_setPosition(my_level->level1, my_level->pos_lev1);
        sfRenderWindow_drawSprite(my_struct->window, my_level->level1, NULL);
        sfSprite_setPosition(my_level->level2, my_level->pos_lev2);
        sfRenderWindow_drawSprite(my_struct->window, my_level->level2, NULL);
        sfSprite_setPosition(my_level->level3, my_level->pos_lev3);
        sfRenderWindow_drawSprite(my_struct->window, my_level->level3, NULL);
        sfSprite_setPosition(my_level->shop, my_level->pos_shop);
        sfRenderWindow_drawSprite(my_struct->window, my_level->shop, NULL);
    }
}
