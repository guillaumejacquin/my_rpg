/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu.c
*/

#include "rpg.h"

void set_volume(rpg_t *my_struct)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_struct ->pos_minus.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_minus.x
            + my_struct->rect_minus.width &&
            my_struct->event.mouseButton.y >= my_struct ->pos_minus.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_minus.y
            + my_struct->rect_minus.height &&
            sfMusic_getVolume(my_struct->bgm_menu) > 10)
            sfMusic_setVolume(my_struct->bgm_menu,
                              sfMusic_getVolume(my_struct->bgm_menu) - 5);
        else if (my_struct->event.mouseButton.x >= my_struct ->pos_plus.x &&
                 my_struct->event.mouseButton.x <= my_struct->pos_plus.x
                 + my_struct->rect_plus.width &&
                 my_struct->event.mouseButton.y >= my_struct ->pos_plus.y &&
                 my_struct->event.mouseButton.y <= my_struct->pos_plus.y
                 + my_struct->rect_plus.height &&
                 sfMusic_getVolume(my_struct->bgm_menu) != 100 && 
                 sfMusic_getVolume(my_struct->bgm_menu) != 0)
            sfMusic_setVolume(my_struct->bgm_menu,
                              sfMusic_getVolume(my_struct->bgm_menu) + 5);
    }
}

void set_position(rpg_t *my_struct)
{
    sfSprite_setPosition(my_struct->play, my_struct->pos_play);
    sfSprite_setPosition(my_struct->quit, my_struct->pos_quit);
    sfSprite_setPosition(my_struct->mute, my_struct->pos_mute);
    sfSprite_setPosition(my_struct->plus_menu, my_struct->pos_plus);
    sfSprite_setPosition(my_struct->minus_menu, my_struct->pos_minus);
}

void destroy_sound(rpg_t *my_struct)
{
    if (my_struct->menu == 0)
        sfMusic_destroy(my_struct->bgm_menu);
}

void ux_menu(rpg_t *my_struct)
{
    if (my_struct->menu == 0) {
        get_quit(my_struct);
        get_play(my_struct);
        set_mute(my_struct);
        set_volume(my_struct);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_struct->background, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_struct->play, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_struct->quit, NULL);
        sfSprite_setTextureRect(my_struct->mute, my_struct->rect2);
        sfRenderWindow_drawSprite(my_struct->window, my_struct->mute, NULL);
        sfSprite_setTextureRect(my_struct->plus_menu, my_struct->rect_plus);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_struct->plus_menu, NULL);
        sfSprite_setTextureRect(my_struct->minus_menu, my_struct->rect_minus);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_struct->minus_menu, NULL);
    }
}

void display_menu(rpg_t *my_struct, level_t *my_level)
{
    sfRenderWindow_display(my_struct->window);
    set_position(my_struct);
    while (sfRenderWindow_pollEvent(my_struct->window, &my_struct->event)
           || my_struct->life == 0) {
        if (my_struct->event.type == sfEvtClosed || my_struct->life == 0) {
            sfRenderWindow_close(my_struct->window);
            my_struct->life = my_struct->life - 1;
            destroy_sound(my_struct);
        }
        button_stop(my_struct);
    }
    ux_menu(my_struct);
    if (my_struct->menu == 1)
        my_level->x = 1;
    if (my_struct->menu == 1 && my_struct->quitlevel == 0)  {
        if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased)
            let_shop(my_struct, my_level);
        level1(my_struct, my_level);
        level2(my_struct, my_level);
        level3(my_struct, my_level);
    }
}
