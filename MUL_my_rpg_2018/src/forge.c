/*
** EPITECH PROJECT, 2019
** level forge.c
** File description:
** forge
*/

#include "rpg.h"

void set_my_forge(forge_t *my_forge)
{
    my_forge->p = 0;
    my_forge->background = set_sprite("asset/level/auberge.PNG");
    my_forge->saler = set_sprite("asset/perso/marchand3.png");
    my_forge->heroes = set_sprite("asset/perso/perso_etat1.png");
    my_forge->pos_saler.x = 640;
    my_forge->pos_saler.y = 440;
    my_forge->rectsaler.height = 300;
    my_forge->rectsaler.width = 150;
    my_forge->clock = sfClock_create();
    my_forge->pos_heroes.x = 661;
    my_forge->pos_heroes.y = 835;
    my_forge->rectheroes.height = 100;
    my_forge->rectheroes.width = 100;
    my_forge->buttone = set_sprite("asset/level/interagir.png");
    my_forge->pos_buttone.x = 657;
    my_forge->pos_buttone.y = 316;
}

void anim_saler(forge_t *my_forge)
{
    my_forge->time = sfClock_getElapsedTime(my_forge->clock);
    if (my_forge->time.microseconds < 200000)
        my_forge->rectsaler.left = 0;
    if (my_forge->time.microseconds< 400000 &&
        my_forge->time.microseconds > 200000)
        my_forge->rectsaler.left = 125;
    if (my_forge->time.microseconds < 600000 &&
        my_forge->time.microseconds > 400000)
        my_forge->rectsaler.left = 250;
    if (my_forge->time.microseconds < 800000 &&
        my_forge->time.microseconds > 600000)
        my_forge->rectsaler.left = 370;
    if (my_forge->time.microseconds < 1000000 &&
        my_forge->time.microseconds > 800000)
        my_forge->rectsaler.left = 495;
    if (my_forge->time.microseconds > 1000000) {
        sfClock_restart (my_forge->clock);
    }
    anim_heroes_shop(my_forge);
}

void anim_heroes_shop(forge_t *my_forge)
{
    if (my_forge->time.microseconds < 200000)
        my_forge->rectheroes.left = 0;
    if (my_forge->time.microseconds< 400000 &&
	my_forge->time.microseconds > 200000)
	my_forge->rectheroes.left = 105;
    if (my_forge->time.microseconds < 600000 &&
	my_forge->time.microseconds > 400000)
	my_forge->rectheroes.left = 210;
    if (my_forge->time.microseconds > 600000)
        sfClock_restart (my_forge->clock);
}

void in_shop(rpg_t *my_struct, forge_t *my_forge)
{
    if (my_struct->quit_forge == 0) {
        sfSprite_setTextureRect(my_forge->saler, my_forge->rectsaler);
        anim_saler(my_forge);
        sfRenderWindow_drawSprite(my_struct->window,
				  my_forge->background, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_forge->saler, NULL);
        sfRenderWindow_drawSprite(my_struct->window, my_forge->heroes, NULL);
        sfSprite_setPosition(my_forge->saler, my_forge->pos_saler);
	sfSprite_setPosition(my_forge->heroes, my_forge->pos_heroes);
        heroes_shop(my_struct, my_forge);
    }
}
