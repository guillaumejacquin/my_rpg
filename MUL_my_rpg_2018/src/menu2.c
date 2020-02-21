/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu
*/

#include "rpg.h"

void *set_sprite(char const *pathfile)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

void set_struct_volume(rpg_t *my_struct)
{
    my_struct->image = set_sprite("asset/menu/desole.png");
    my_struct->plus_menu = set_sprite("asset/menu/volume.png");
    my_struct->pos_plus.x = 10;
    my_struct->pos_plus.y = 300;
    my_struct->rect_plus.top = 0;
    my_struct->rect_plus.left = 0;
    my_struct->rect_plus.width = 130;
    my_struct->rect_plus.height = 125;
    my_struct->minus_menu = set_sprite("asset/menu/volume.png");
    my_struct->pos_minus.x = 10;
    my_struct->pos_minus.y = 430;
    my_struct->rect_minus.top = 0;
    my_struct->rect_minus.left = 135;
    my_struct->rect_minus.width = 130;
    my_struct->rect_minus.height = 125;
}

void my_howto(rpg_t *my_struct)
{
    if (my_struct->menu == 0) {
    sfRenderWindow_drawSprite(my_struct->window, my_struct->howto, NULL);
    sfSprite_setPosition(my_struct->howto, my_struct->pos_howto);
    
      if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_struct ->pos_howto.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_howto.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_struct->pos_howto.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_howto.y
            + my_struct->rect.height + 300) {
              my_struct->menu = 7;
        }
    }
    }
    if (my_struct->menu == 7) {
        sfRenderWindow_clear(my_struct->window, sfWhite);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->image, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->quit, NULL);
 if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_struct->pos_quit.x &&
            my_struct->event.mouseButton.x <= my_struct->pos_quit.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_struct ->pos_quit.y &&
            my_struct->event.mouseButton.y <= my_struct->pos_quit.y
            + my_struct->rect.height + 300) {
              my_struct->menu = 1;
                sfMusic_destroy(my_struct->bgm_menu);
        }
    }

    }
}