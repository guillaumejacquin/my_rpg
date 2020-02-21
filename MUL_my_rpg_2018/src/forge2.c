/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** forge2
*/

#include "rpg.h"

void set_my_forge2(forge_t *my_forge)
{
    my_forge->life = set_sprite("asset/level/Coeur1.png");
    my_forge->attack = set_sprite("asset/level/sword.png");
    my_forge->soundbuffer = sfSoundBuffer_createFromFile("music/menu.ogg");
    my_forge->sound = sfSound_create();
    my_forge->pos_attack.x = 440;
    my_forge->pos_attack.y = 440;
    my_forge->pos_life.x = 840;
    my_forge->pos_life.y = 440;
}

void deplacement_heroes(rpg_t *my_struct, forge_t *my_forge)
{
    int a = 0;

    if (my_struct->event.type == sfEvtKeyPressed  &&
        my_struct->event.key.code == sfKeyUp && my_forge->pos_heroes.y > 600) {
        my_forge->pos_heroes.y = my_forge->pos_heroes.y - 1;
    }
    if (my_forge->pos_heroes.y == 600) {
        sfRenderWindow_drawSprite(my_struct->window, my_forge->buttone, NULL);
        sfSprite_setPosition(my_forge->buttone, my_forge->pos_buttone);
        if (my_struct->event.key.code == sfKeyE) {
            a = 1;
            while (a != 0) {
                while (sfRenderWindow_pollEvent(my_struct->window,
                                                &my_struct->event))
                {
                    if (my_struct->event.type == sfEvtKeyPressed  &&
                        my_struct->event.key.code == sfKeyA)
                        a = 0;
                    sfRenderWindow_drawSprite(my_struct->window,
                                              my_forge->life, NULL);
                    sfSprite_setPosition(my_forge->life, my_forge->pos_life);
                    sfRenderWindow_drawSprite(my_struct->window,
                                              my_forge->attack, NULL);
                    sfSprite_setPosition(my_forge->attack,
                                         my_forge->pos_attack);
                    sfRenderWindow_display(my_struct->window);
                    toupie(my_struct, my_forge);
                    sshop(my_struct, my_forge);
                }
            }
        }
    }
    quitt_forge(my_struct, my_forge);
}

void toupie(rpg_t *my_struct, forge_t *my_forge)
{
    int achat2 = 0;

    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_forge->pos_life.x
            && my_struct->event.mouseButton.x <= my_forge->pos_life.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_forge->pos_life.y &&
            my_struct->event.mouseButton.y <= my_forge->pos_life.y
            + my_struct->rect.height + 300) {
            if (my_struct->argent >= 100 + achat2){
                my_struct->argent -= 100 + achat2;
                my_struct->attack_heroes += 1;
            }
        }
    }
}

void sshop(rpg_t *my_struct, forge_t *my_forge)
{
    int achat = 0;

    if (my_struct->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (my_struct->event.mouseButton.x >= my_forge->pos_attack.x &&
            my_struct->event.mouseButton.x <= my_forge->pos_attack.x
            + my_struct->rect.width + 300 &&
            my_struct->event.mouseButton.y >= my_forge->pos_attack.y &&
            my_struct->event.mouseButton.y <= my_forge->pos_attack.y
            + my_struct->rect.height + 300) {
            if (my_struct->argent >= 100 + achat){
                my_struct->argent -= 100 + achat;
                my_struct->life += 1;
                sfText_setString(my_forge->text, my_putnbr(my_struct->argent));
            }
        }
    }
}
void quitt_forge(rpg_t *my_struct, forge_t *my_forge)
{
    if (my_struct->event.type == sfEvtKeyPressed &&
        my_struct->event.key.code == sfKeyDown && my_forge->pos_heroes.y < 1400)
        my_forge->pos_heroes.y = my_forge->pos_heroes.y + 1;
    if (my_struct->event.type == sfEvtKeyPressed
        && my_struct->event.key.code == sfKeyDown
        && my_forge->pos_heroes.y > 1000) {
        my_struct->menu = 1;
        my_struct->quit_forge = 1;
        my_struct->world = 0;
        my_struct->quitlevel = 0;
        my_forge->p = 0;
    }
}

void money(forge_t *my_forge)
{
    my_forge->text = sfText_create();
    my_forge->font = sfFont_createFromFile("asset/level/arial.ttf");
  //  sfText_setString(my_forge->text, my_putnbr(my_struct->argent));
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
