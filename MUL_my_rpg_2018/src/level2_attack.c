/*
** EPITECH PROJECT, 2019
** le
** File description:
** e
*/

#include "rpg.h"

void setmy_attack(rpg_t *my_struct, level2_t *my_level2)
{
    my_level2->attack_heroes = set_sprite("asset/perso/attack.png");
    my_level2->pos_attheroes.x = my_level2->pos_heroes2.x;
    my_level2->pos_attheroes.y = my_level2->pos_heroes2.y;
    my_level2->munster1 = set_sprite("asset/monstre/monstre2.png");
    my_level2->pos_monster1.x = 900;
    my_level2->pos_monster1.y = 700;
}

void animl2(rpg_t *my_struct, level2_t *my_level2)
{
    if (my_level2->compteur1 >= 9)
        my_level2->lifemunster1 = 1;
    if (my_level2->lifemunster1 == 1) {
        my_level2->pos_monster1.y = 1299;
    }
    sfRenderWindow_drawSprite(my_struct->window,
                              my_level2->attack_heroes, NULL);
    sfSprite_setPosition(my_level2->attack_heroes, my_level2->pos_attheroes);
    sfRenderWindow_drawSprite(my_struct->window, my_level2->munster1, NULL);
    sfSprite_setPosition(my_level2->munster1, my_level2->pos_monster1);
    my_level2->pos_attheroes.x = my_level2->pos_attheroes.x + 1;
    if (my_level2->pos_attheroes.x > 1500) {
        my_level2->pos_attheroes.x = my_level2->pos_heroes2.x;
        my_level2->pos_attheroes.y = my_level2->pos_heroes2.y;
    }
    if (my_level2->pos_attheroes.x < my_level2->pos_monster1.x + 20 &&
        my_level2->pos_attheroes.x > my_level2->pos_monster1.x - 20 &&
        my_level2->pos_attheroes.y == my_level2->pos_monster1.y &&
        my_level2->lifemunster1 != 1) {
        my_level2->pos_attheroes.x = my_level2->pos_heroes2.x;
        my_level2->pos_attheroes.y = my_level2->pos_heroes2.y;
        my_level2->compteur1 = my_level2->compteur1 + my_struct->attack_heroes;
    }
}
