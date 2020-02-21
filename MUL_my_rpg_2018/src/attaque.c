/*
** EPITECH PROJECT, 2019
** attack
** File description:
** attack
*/

#include "rpg.h"

void set_my_attackl1(level1_t *my_level1)
{

    my_level1->atth = set_sprite("asset/perso/attack.png");
    my_level1->pos_attackl.x = 50;
    my_level1->pos_attackl.y = 680;
    my_level1->attack_monster1 = set_sprite("asset/monstre/attackboss.png");
    my_level1->pos_attack_monster1.x =  my_level1->pos_munster1.x - 40;
    my_level1->pos_attack_monster1.y = my_level1->pos_munster1.y + 20;
}
void attack_of_perso(level1_t *my_level1, rpg_t *my_struct)
{
    sfRenderWindow_drawSprite(my_struct->window, my_level1->atth, NULL);
    sfSprite_setPosition(my_level1->atth, my_level1->pos_attackl);

    my_level1->pos_attackl.x = my_level1->pos_attackl.x + 1;

    if (my_level1->pos_attackl.x >= my_level1->pos_munster1.x - 100 &&
        my_level1->pos_attackl.x <= my_level1->pos_munster1.x - 60  &&
        my_level1->life_munster1 != 1
        && my_level1->pos_attackl.y == my_level1->pos_munster1.y) {
        my_level1->compteur1 = my_level1->compteur1 + my_struct->attack_heroes;;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
    if (my_level1->compteur1 >= 9) {
        my_level1->pos_munster1.y = 2000;
        my_level1->life_munster1 = 1;
        my_level1->compteur1 = 0;
    }
    if (my_level1->pos_attackl.x > 1700) {
        my_level1->pos_attackl.x = my_level1->pos_heroes.x;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}

void set_my_attackl1_3(level1_t *my_level1)
{
    my_level1->munster1_1 = set_sprite("asset/monstre/monstre2.png");
    my_level1->pos_munster1_1.x = 1100;
    my_level1->pos_munster1_1.y = 800;
    my_level1->munster1_2 = set_sprite("asset/monstre/monstre2.png");
    my_level1->pos_munster1_2.x = 1100;
    my_level1->pos_munster1_2.y = 600;
    my_level1->munster1_3 = set_sprite("asset/monstre/monstre2.png");
    my_level1->pos_munster1_3.x = 900;
    my_level1->pos_munster1_3.y = 700;
    my_level1->boule1 = set_sprite("asset/monstre/attackboss.png");
    my_level1->pos_boule1.x = my_level1->pos_munster1_1.x - 20;
    my_level1->pos_boule1.y = my_level1->pos_munster1_1.y;
    my_level1->boule2 = set_sprite("asset/monstre/attackboss.png");
    my_level1->pos_boule2.x = my_level1->pos_munster1_2.x - 20;
    my_level1->pos_boule2.y = my_level1->pos_munster1_2.y;
    my_level1->boule3 = set_sprite("asset/monstre/attackboss.png");
    my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 20;
    my_level1->pos_boule3.y = my_level1->pos_munster1_3.y;
}

void monster2(rpg_t *my_struct, level1_t *my_level1, int a)
{
    if (a == 2) {
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_level1->munster1_1, NULL);
        sfSprite_setPosition(my_level1->munster1_1, my_level1->pos_munster1_1);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_level1->munster1_2, NULL);
        sfSprite_setPosition(my_level1->munster1_2, my_level1->pos_munster1_2);
        sfRenderWindow_drawSprite(my_struct->window,
                                  my_level1->munster1_3, NULL);
        sfSprite_setPosition(my_level1->munster1_3, my_level1->pos_munster1_3);
        sfRenderWindow_drawSprite(my_struct->window, my_level1->boule1, NULL);
        sfSprite_setPosition(my_level1->boule1, my_level1->pos_boule1);
        sfRenderWindow_drawSprite(my_struct->window, my_level1->boule2, NULL);
        sfSprite_setPosition(my_level1->boule2, my_level1->pos_boule2);
        sfRenderWindow_drawSprite(my_struct->window, my_level1->boule3, NULL);
        sfSprite_setPosition(my_level1->boule3, my_level1->pos_boule3);
        anim_monster2(my_struct, my_level1);
        sfSprite_setTextureRect(my_level1->munster1_3, my_level1->rectmunster1);
        sfSprite_setTextureRect(my_level1->munster1_2, my_level1->rectmunster1);
        sfSprite_setTextureRect(my_level1->munster1_1, my_level1->rectmunster1);
    }
}

void anim_monster2(rpg_t *my_struct, level1_t *my_level1)
{
    my_level1->pos_boule1.x = my_level1->pos_boule1.x - 1.1;
    my_level1->pos_boule2.x = my_level1->pos_boule2.x - 0.9;
    my_level1->pos_boule3.x = my_level1->pos_boule3.x - 1.3;
    munster1(my_struct, my_level1);
    munster2(my_struct, my_level1);
    munster3(my_struct, my_level1);
}

void munster1(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur11 >= 9)
        my_level1->life1 = 1;
    if (my_level1->life1 == 1) {
        my_level1->pos_munster1_1.y = 2190;
        my_level1->compteur11 = 0;
        if(my_level1->pos_boule1.x < 00)
            my_level1->pos_boule1.y = -2000;
    }
    if (my_level1->pos_boule1.x < -80 && my_level1->pos_boule1.x >
        -120 &&  my_level1->life1 == 0)
        my_level1->pos_boule1.x = my_level1->pos_munster1_1.x - 40;
    if (my_level1->pos_boule1.x < my_level1->pos_heroes.x + 20 &&
        my_level1->pos_boule1.x >
        my_level1->pos_heroes.x  - 20 && my_level1->pos_boule1.y
        == my_level1->pos_heroes.y
        &&  my_level1->life1 == 0) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule1.x = my_level1->pos_munster1_1.x - 40;
    }
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_1.x
        + 20 && my_level1->pos_attackl.x >
        my_level1->pos_munster1_1.x - 20 &&
        my_level1->pos_attackl.y == my_level1->pos_munster1_1.y - 20) {
        my_level1->compteur11 = my_level1->compteur11 +
            my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}

void munster2(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur2 >= 9)
        my_level1->life2 = 1;
    if (my_level1->life2 == 1) {
        my_level1->pos_munster1_2.y = 2190;
        my_level1->compteur2 = 0;
        if(my_level1->pos_boule2.x < 00)
            my_level1->pos_boule2.y = -2000;
    }
    if (my_level1->pos_boule2.x < -110 &&
        my_level1->pos_boule1.x > -130 &&  my_level1->life2 == 0)
        my_level1->pos_boule2.x = my_level1->pos_munster1_2.x - 40;
    if (my_level1->pos_boule2.x < my_level1->pos_heroes.x + 20 &&
        my_level1->pos_boule2.x > my_level1->pos_heroes.x - 20 &&
        my_level1->pos_boule2.y == my_level1->pos_heroes.y &&
        my_level1->life2 == 0) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule2.x = my_level1->pos_munster1_1.x - 40;
    }
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_2.x + 20 &&
        my_level1->pos_attackl.x > my_level1->pos_munster1_2.x - 20 &&
        my_level1->pos_attackl.y == my_level1->pos_munster1_2.y - 20) {
        my_level1->compteur2 = my_level1->compteur2 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }

}

void munster3(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->compteur3 >= 9)
        my_level1->life3 = 1;
    if (my_level1->life3 == 1) {
        my_level1->pos_munster1_3.y = 2190;
        my_level1->compteur3 = 0;
        if(my_level1->pos_boule3.x < 00)
            my_level1->pos_boule3.y = -2000;
    }
    if (my_level1->pos_boule3.x < -20 &&  my_level1->life3 == 0)
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    if (my_level1->pos_boule3.x < -110 && my_level1->pos_boule3.x > -130)
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    if (my_level1->pos_boule3.x < my_level1->pos_heroes.x
        + 20 && my_level1->pos_boule3.x >
        my_level1->pos_heroes.x - 20 && my_level1->pos_boule3.y ==
        my_level1->pos_heroes.y &&  my_level1->life3 != 1) {
        my_struct->life = my_struct->life - 1;
        my_level1->pos_boule3.x = my_level1->pos_munster1_3.x - 40;
    }
    if (my_level1->pos_attackl.x < my_level1->pos_munster1_3.x
        + 20 && my_level1->pos_attackl.x
        > my_level1->pos_munster1_3.x - 20 && my_level1->pos_attackl.y
        == my_level1->pos_munster1_3.y - 20) {
        my_level1->compteur3 = my_level1->compteur3 + my_struct->attack_heroes;
        my_level1->pos_attackl.x = my_level1->pos_heroes.x + 20;
        my_level1->pos_attackl.y = my_level1->pos_heroes.y - 20;
    }
}

void quitlevel1(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_level1->life1 == 1 && my_level1->life2 == 1 && my_level1->life3
        == 1 && my_level1->life_munster1 == 1
        && my_level1->pos_heroes.x > 1460) {
     my_struct->accept = 1;
     my_struct->menu = 1;
     my_struct->quit_forge = 1;
     my_struct->world = 0;
     my_struct->quitlevel = 0;
     my_struct->argent = my_struct->argent + 1000;
    sfSound_destroy(my_level1->sound);  
    }
}
