/*
** EPITECH PROJECT, 2019
** ak
** File description:
** ak
*/

#include "rpg.h"

void set_my_level1(level1_t *my_level1)
{
    my_level1->background = set_sprite("asset/level/level1/level1_Plan1.png");
    my_level1->background2 = set_sprite("asset/level/level1/level1_Plan2.png");
    my_level1->background3 = set_sprite("asset/level/level1/level1_Plan3.png");
    my_level1->monster = set_sprite("asset/monstre/monstre2.png");
    my_level1->heroes = set_sprite("asset/perso/perso_etat1.png");
    my_level1->munster1 = set_sprite("asset/monstre/monstre2.png");
    my_level1->attack = set_sprite("asset/monstre/attackboss.png"); 
    my_level1->pos_attack.x = 900;
    my_level1->pos_attack.y = 680;
    my_level1->pos_heroes.x = 50;
    my_level1->pos_heroes.y = 700;
    my_level1->rectheroes.top = 0;
    my_level1->rectheroes.left = 0;
    my_level1->rectheroes.height = 100;
    my_level1->rectheroes.width = 100;
    my_level1->clock1 = sfClock_create();
    my_level1->soundbuffer = sfSoundBuffer_createFromFile("music/level1.ogg");
    my_level1->sound = sfSound_create();
    my_level1->pos_munster1.x = 900;
    my_level1->pos_munster1.y = 680;
    my_level1->rectmunster1.top = 0;
    my_level1->rectmunster1.left = 0;
    my_level1->rectmunster1.height = 65;
    my_level1->rectmunster1.width = 65;
    my_level1->pos_attack.x = 50;
    my_level1->pos_attack.y = 500;
}

void anim_heroes(level1_t *my_level1, rpg_t *my_struct)
{
    my_level1->time1 = sfClock_getElapsedTime(my_level1->clock1);
    if (my_level1->time1.microseconds < 200000)
        my_level1->rectheroes.left = 0;
    if (my_level1->time1.microseconds< 400000 &&
        my_level1->time1.microseconds > 200000)
        my_level1->rectheroes.left = 105;
    if (my_level1->time1.microseconds < 600000 &&
        my_level1->time1.microseconds > 400000)
        my_level1->rectheroes.left = 210;
    if (my_level1->time1.microseconds > 600000)
        sfClock_restart (my_level1->clock1);
    anim_munster(my_level1, my_struct);
}

void deplacement_heroes_level1(rpg_t *my_struct, level1_t *my_level1)
{
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyRight)
        my_level1->pos_heroes.x = my_level1->pos_heroes.x + 1.5;
    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyLeft)
        my_level1->pos_heroes.x = my_level1->pos_heroes.x - 1.5;
}

void music_level1(level1_t *my_level1)
{
    static int a = 0;

    if (a == 0) {
        sfSound_setBuffer(my_level1->sound, my_level1->soundbuffer);
        sfSound_play(my_level1->sound);
        sfSound_setVolume(my_level1->sound, 100);
        sfSound_setLoop(my_level1->sound, sfTrue);
        sfSound_getLoop(my_level1->sound);
        a = a + 1;
    }
}

void in_level1(rpg_t *my_struct, level1_t *my_level1)
{
    sfSprite_setTextureRect(my_level1->heroes, my_level1->rectheroes);
    anim_heroes(my_level1, my_struct);
    anim_up(my_level1, my_struct);
    movement_for_heroes(my_struct, my_level1);
    sfRenderWindow_drawSprite(my_struct->window, my_level1->heroes, NULL);
    sfSprite_setPosition(my_level1->heroes, my_level1->pos_heroes);
    music_level1(my_level1);
}