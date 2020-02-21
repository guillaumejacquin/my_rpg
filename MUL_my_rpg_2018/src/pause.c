/*
** EPITECH PROJECT, 2019
** pause
** File description:
** pause
*/

#include "rpg.h"

void set_my_pause(rpg_t *my_struct)
{
        my_struct->fond = set_sprite("asset/menu/fondmenu.jpg");
}

void set_my_inv(inventaire_t *my_inv)
{
    my_inv->inventaire1 = set_sprite("asset/menu/inventaire1.png");
    my_inv->inventaire2 = set_sprite("asset/menu/inventaire2.png");
    my_inv->inventaire3 = set_sprite("asset/menu/inventaire2.png");
    my_inv->pos_inventaire2.x = 280;
    my_inv->pos_inventaire2.y = 200;
    my_inv->pos_inventaire3.x = 280;
    my_inv->pos_inventaire3.y = 232;

}

void button_stop(rpg_t *my_struct)
{
    if (my_struct->event.type == sfEvtKeyPressed && my_struct->event.key.code
        == sfKeyEscape)
        my_struct->dest = 1;
    while (my_struct->dest == 1) {
        while (sfRenderWindow_pollEvent(my_struct->window, &my_struct->event)) {
            sfRenderWindow_drawSprite(my_struct->window, my_struct->background,
                                      NULL);
            sfRenderWindow_drawSprite(my_struct->window, my_struct->play, NULL);
            sfRenderWindow_drawSprite(my_struct->window, my_struct->quit, NULL);
            sfRenderWindow_display(my_struct->window);
        }
        if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
            if (my_struct->event.mouseButton.x >= my_struct ->pos_play.x &&
                my_struct->event.mouseButton.x <= my_struct->pos_play.x
                + my_struct->rect.width + 300 &&
                my_struct->event.mouseButton.y >= my_struct ->pos_play.y &&
                my_struct->event.mouseButton.y <= my_struct->pos_play.y
                + my_struct->rect.height + 300) {
                break;
            }
        }
        if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
            if (my_struct->event.mouseButton.x >= my_struct ->pos_quit.x &&
                my_struct->event.mouseButton.x <= my_struct->pos_quit.x
                + my_struct->rect.width + 300 &&
                my_struct->event.mouseButton.y >= my_struct ->pos_quit.y &&
                my_struct->event.mouseButton.y <= my_struct->pos_quit.y
                + my_struct->rect.height + 300) {
                my_struct->menu = 2;
                break;
            }
        }
    }
    my_struct->dest = 0;
}

void finish_game(rpg_t *my_struct, level3_t *my_level3)
{
    if (my_level3->life_boss1 == 1 && my_level3->pos_heroes3.x > 1500) {
        sfRenderWindow_drawSprite(my_struct->window, my_level3->victoire, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_struct->quit, NULL);
        if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
            if (my_struct->event.mouseButton.x >= my_struct ->pos_quit.x &&
                my_struct->event.mouseButton.x <= my_struct->pos_quit.x
                + my_struct->rect.width + 300 &&
                my_struct->event.mouseButton.y >= my_struct ->pos_quit.y &&
                my_struct->event.mouseButton.y <= my_struct->pos_quit.y
                + my_struct->rect.height + 300) {
                my_struct->menu = 2;
            }
        }
    }
}

void inventaire(rpg_t *my_struct, inventaire_t *my_inv)
{
    if (my_struct->event.type == sfEvtKeyReleased && my_struct->event.key.code
        == sfKeyQ)
        my_struct->dest = 2;
    if (my_struct->dest == 2) {
        sfRenderWindow_drawSprite(my_struct->window, my_inv->inventaire1, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_inv->inventaire2, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_inv->inventaire3, NULL);
        sfSprite_setPosition(my_inv->inventaire2, my_inv->pos_inventaire2);
        sfSprite_setPosition(my_inv->inventaire3, my_inv->pos_inventaire3);
        if (my_struct->accept == 1) {
            my_inv->pos_inventaire2.x = 500;
        }
        my_struct->dest = 0;
    }
}
