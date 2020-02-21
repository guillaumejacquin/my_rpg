/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** level_next
*/

#include "rpg.h"

void let_shop(rpg_t *my_struct, level_t *my_level)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_level->pos_shop.x &&
               my_struct->event.mouseButton.x <= my_level->pos_shop.x
               + my_struct->rect.width + 300 &&
               my_struct->event.mouseButton.y >= my_level->pos_shop.y &&
               my_struct->event.mouseButton.y <= my_level->pos_shop.y
               + my_struct->rect.height + 300) {
            my_struct->world = 1;
            my_struct->quitlevel = 1;
            my_struct->quit_forge = 0;
        }
    }
}

void level1(rpg_t *my_struct, level_t *my_level)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_level->pos_lev2.x &&
               my_struct->event.mouseButton.x <= my_level->pos_lev2.x
               + my_struct->rect.width + 300 &&
               my_struct->event.mouseButton.y >= my_level->pos_lev2.y &&
               my_struct->event.mouseButton.y <= my_level->pos_lev2.y
               + my_struct->rect.height + 300) {
            my_struct->world = 3;
            my_struct->quitlevel = 1;
        }
    }
}

void level2(rpg_t *my_struct, level_t *my_level)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_level->pos_lev3.x &&
               my_struct->event.mouseButton.x <= my_level->pos_lev3.x
               + my_struct->rect.width + 300 &&
               my_struct->event.mouseButton.y >= my_level->pos_lev3.y &&
               my_struct->event.mouseButton.y <= my_level->pos_lev3.y
               + my_struct->rect.height + 300) {
            my_struct->world = 4;
            my_struct->quitlevel = 1;
        }
    }
} 

void level3(rpg_t *my_struct, level_t *my_level)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_level->pos_lev1.x &&
               my_struct->event.mouseButton.x <= my_level->pos_lev1.x
               + my_struct->rect.width + 300 &&
               my_struct->event.mouseButton.y >= my_level->pos_lev1.y &&
               my_struct->event.mouseButton.y <= my_level->pos_lev1.y
               + my_struct->rect.height + 300) {
            my_struct->world = 5;
            my_struct->quitlevel = 1;
        }
    }
}
