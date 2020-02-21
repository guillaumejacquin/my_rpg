/*
** EPITECH PROJECT, 2019
** 3 part
** File description:
** for menu
*/

#include "rpg.h"

void set_sound(rpg_t *my_struct)
{
    sfMusic_play(my_struct->bgm_menu);
    sfMusic_setLoop(my_struct->bgm_menu, sfTrue);
    my_struct->mute = set_sprite("asset/menu/mute.jpg");
    my_struct->pos_mute.x = 10;
    my_struct->pos_mute.y = 100;
    my_struct->rect2.top = 0;
    my_struct->rect2.left = 0;
    my_struct->rect2.width = 81;
    my_struct->rect2.height = 81;
    set_struct_volume(my_struct);
}

void set_my_struct(rpg_t *my_struct)
{
    my_struct->z = 0;
    my_struct->world = 0;
    my_struct->menu = 0;
    my_struct->quitlevel = 0;
    my_struct->quit_forge = 0;
    my_struct->x = 0;
    my_struct->life = 1900000;
    my_struct->video_mode.width = 1600;
    my_struct->video_mode.height = 1000;
    my_struct->video_mode.bitsPerPixel = 32;
    my_struct->background = set_sprite("asset/menu/fondmenu.jpg");
    my_struct->play = set_sprite("asset/menu/play.png");
    my_struct->pos_play.x = 1350;
    my_struct->pos_play.y = 80;
    my_struct->quit = set_sprite("asset/menu/quit.png");
    my_struct->pos_quit.x = 1400;
    my_struct->pos_quit.y = 400;
    my_struct->bgm_menu = sfMusic_createFromFile("music/intro.ogg");
    set_sound(my_struct);
    my_struct->window = sfRenderWindow_create(my_struct->video_mode,
    "my_rpg", def, NULL);
//sfRenderWindow_setFramerateLimit(my_struct->window, 120);
    my_struct->howto = set_sprite("asset/menu/howto.png");
    my_struct->pos_howto.x = 400;
    my_struct->pos_howto.y = 50;
}

void get_play(rpg_t *my_struct)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_struct ->pos_play.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_play.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_struct ->pos_play.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_play.y
            + my_struct->rect.height + 300) {
            sfMusic_stop(my_struct->bgm_menu);
            sfMusic_destroy(my_struct->bgm_menu);
            my_struct->menu = 1;
        }
    }
}

void get_quit(rpg_t *my_struct)
{
    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_struct ->pos_quit.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_quit.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_struct ->pos_quit.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_quit.y
            + my_struct->rect.height + 300) {
            sfMusic_destroy(my_struct->bgm_menu);
            my_struct->menu = 2;
        }
    }
}

void set_mute(rpg_t *my_struct)
{
    if (my_struct->event.mouseButton.type ==  sfEvtMouseButtonPressed) {
        if (my_struct->event.mouseButton.x >= my_struct ->pos_mute.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_mute.x
            + my_struct->rect2.width &&
            my_struct->event.mouseButton.y >= my_struct ->pos_mute.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_mute.y
            + my_struct->rect2.height &&
            sfMusic_getVolume(my_struct->bgm_menu) != 0) {
            sfMusic_setVolume(my_struct->bgm_menu, 0);
            my_struct->rect2.left = 81;
            my_struct->pos_mute.x = 100;
        } else if (my_struct->event.mouseButton.x >= my_struct ->pos_mute.x &&
                   my_struct->event.mouseButton.x <= my_struct->pos_mute.x
                   + my_struct->rect2.width &&
                   my_struct->event.mouseButton.y >= my_struct ->pos_mute.y &&
                   my_struct->event.mouseButton.y <= my_struct->pos_mute.y
                   + my_struct->rect2.height &&
                   sfMusic_getVolume(my_struct->bgm_menu) != 100) {
            sfMusic_setVolume(my_struct->bgm_menu, 100);
            my_struct->rect2.left = 0;
            my_struct->pos_mute.x = 10;
        }
    }
}
