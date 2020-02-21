/*
** EPITECH PROJECT, 2019
** forge3.c
** File description:
** zaaa
*/

#include"rpg.h"

void money(forge_t *my_forge)
{
    my_forge->text = sfText_create();
    my_forge->font = sfFont_createFromFile("asset/level/arial.ttf");
  //sfText_setString(my_forge->text, my_putnbr(my_struct->argent));
    sfText_setFont(my_forge->text, my_forge->font);
    sfText_setCharacterSize(my_forge->text, 50);
}

void music_shop(rpg_t *my_struct, forge_t *my_forge)
{
    my_forge->p = 1;

    if (my_forge->p == 1 && my_struct->world == 1 && my_struct->quitlevel == 1
        && my_struct->quit_forge == 0)
        sfSound_setBuffer(my_forge->sound, my_forge->soundbuffer);
    sfSound_play(my_forge->sound);
    sfSound_setVolume(my_forge->sound, 40);
    sfSound_setLoop(my_forge->sound, sfTrue);
    sfSound_getLoop(my_forge->sound);
}

void heroes_shop(rpg_t *my_struct, forge_t *my_forge)
{
    sfSprite_setTextureRect(my_forge->heroes, my_forge->rectheroes);
    sfRenderWindow_drawSprite(my_struct->window, my_forge->heroes, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_forge->saler, NULL);
}
