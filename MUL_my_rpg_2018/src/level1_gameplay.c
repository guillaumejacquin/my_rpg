/*
** EPITECH PROJECT, 2019
** level1
** File description:
** level1
*/

#include "rpg.h"

void set_my_level1_1(level1_t *my_level1)
{
    my_level1->haut = 0;
    my_level1->bas = 0;
    my_level1->a = 0;
    my_level1->compteur1 = 0;
    my_level1->life_munster1 = 0;
    my_level1->up = set_sprite("asset/perso/perso_etat1_2.png");
    my_level1->down = set_sprite("asset/perso/perso_etat1_1.png");
    my_level1->pos_down.x = -100;
    my_level1->pos_down.y = -100;
    my_level1->pos_up.x = 100;
    my_level1->pos_up.y = 100;
    my_level1->rectup.top = 0;
    my_level1->rectup.left = 0;
    my_level1->rectup.height = 100;
    my_level1->rectup.width = 100;
    my_level1->rectdown.top = 0;
    my_level1->rectdown.left = 0;
    my_level1->rectdown.height = 200;
    my_level1->rectdown.width = 200;
    my_level1->clock2 = sfClock_create();
}

void gameplay_haut(rpg_t *my_struct, level1_t *my_level1)
{
    float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyUp) {
        my_level1->haut = 1;
        sfSprite_setTextureRect(my_level1->up, my_level1->rectup);
        sfSprite_setPosition(my_level1->up, my_level1->pos_heroes);
        my_level1->pos_heroes.y =  my_level1->pos_heroes.y - y;
        if ( my_level1->pos_heroes.y < 600)
            my_level1->pos_heroes.y =  my_level1->pos_heroes.y + y;
        my_level1->pos_up.y =   my_level1->pos_heroes.y;
    } else if(my_level1->bas != 1) {
        my_level1->pos_heroes.y = 700;
        my_level1->haut = 0;
    }
}

void gameplay_bas(rpg_t *my_struct, level1_t *my_level1)
{
    float y = 1;

    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyDown) {
        my_level1->bas = 1;
        sfSprite_setTextureRect(my_level1->down, my_level1->rectdown);
        sfRenderWindow_drawSprite(my_struct->window, my_level1->down, NULL);
        sfSprite_setPosition(my_level1->down, my_level1->pos_down);
        my_level1->pos_heroes.y =  my_level1->pos_heroes.y + y;
        if ( my_level1->pos_heroes.y > 800)
            my_level1->pos_heroes.y =  my_level1->pos_heroes.y - y;
        my_level1->pos_up.y =   my_level1->pos_heroes.y;
    }
    else if (my_level1->haut != 1) {
        my_level1->pos_heroes.y = 700;
        my_level1->bas = 0;
    }
}

void anim_up(level1_t *my_level1, rpg_t *my_struct)
{
    my_level1->time2 = sfClock_getElapsedTime(my_level1->clock2);
    if (my_level1->time2.microseconds < 200000)
        my_level1->rectup.left = 0;
    if (my_level1->time2.microseconds< 400000 &&
        my_level1->time2.microseconds > 200000)
        my_level1->rectup.left = 70;
    if (my_level1->time2.microseconds < 600000 &&
        my_level1->time2.microseconds > 400000)
        my_level1->rectup.left = 140;
    if (my_level1->time2.microseconds > 600000)
        sfClock_restart (my_level1->clock2);
    anim_down(my_level1, my_struct);
}

void anim_down(level1_t *my_level1, rpg_t *my_struct)
{
    if (my_level1->time2.microseconds < 100000)
        my_level1->rectdown.left = 0;
    if (my_level1->time2.microseconds< 400000 &&
        my_level1->time2.microseconds > 200000)
        my_level1->rectdown.left = 100;
    if (my_level1->time2.microseconds < 600000 &&
        my_level1->time2.microseconds > 400000)
        my_level1->rectdown.left = 200;
    if (my_level1->time2.microseconds > 6000000)
        sfClock_restart (my_level1->clock2);
}
