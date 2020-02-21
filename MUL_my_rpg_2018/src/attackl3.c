/*
** EPITECH PROJECT, 2019
** attac
** File description:
** ck
*/

#include "rpg.h"

void set_attack_boss(level3_t *my_level3)
{
    my_level3->attack_heroes = set_sprite("asset/perso/attack.png");
    my_level3->pos_attheroes.x = my_level3->pos_heroes3.x;
    my_level3->pos_attheroes.y = my_level3->pos_heroes3.y;
    my_level3->victoire = set_sprite("asset/menu/victoire.png");
}

void attackboss3(rpg_t *my_struct, level3_t *my_level3)
{
    sfRenderWindow_drawSprite(my_struct->window, my_level3->attack_heroes, NULL);
    sfSprite_setPosition(my_level3->attack_heroes, my_level3->pos_attheroes);
    if (my_level3->pos_attheroes.x > 1600) {
        my_level3->pos_attheroes.x = my_level3->pos_heroes3.x;
        my_level3->pos_attheroes.y = my_level3->pos_heroes3.y;
    }
    my_level3->pos_attheroes.x = my_level3->pos_attheroes.x + 1;
    sfRenderWindow_drawSprite(my_struct->window, my_level3->attack3, NULL);

    my_level3->pos_attack3.x = my_level3->pos_attack3.x - 1;
    if(my_level3->pos_attack3.x < 2)
        my_level3->pos_attack3.x = 900;
    if (my_level3->pos_attheroes.x < my_level3->pos_monster3.x - 20 &&
        my_level3->pos_attheroes.x  > my_level3->pos_monster3.x - 50 &&
        my_level3->pos_attheroes.y == my_level3->pos_monster3.y) {
        my_level3->pos_attheroes.x = my_level3->pos_heroes3.x;
        my_level3->pos_attheroes.y = my_level3->pos_heroes3.y;
        my_level3->compteur = my_level3->compteur + my_struct->attack_heroes;
    }
    if (my_level3->compteur == 70) {
        my_level3->life_boss1 = 1;
        my_level3->pos_monster3.y = 1200;
        my_level3->pos_attack3.y = 1120;
    }
    if (my_level3->pos_attack3.x > my_level3->pos_heroes3.x - 10 &&
        my_level3->pos_attack3.x < my_level3->pos_heroes3.x + 10 &&
        my_level3->pos_attack3.y <= my_level3->pos_heroes3.y + 10 &&
        my_level3->pos_attack3.y >= my_level3->pos_heroes3.y - 10) {
        my_level3->pos_attack3.x = 900;
        my_level3->pos_attack3.y = 700;
        my_struct->life = my_struct->life - 2;
    }
    if (my_level3->pos_monster3.x < 2)
        my_level3->pos_monster3.x = 900;
}
