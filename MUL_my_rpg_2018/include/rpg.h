/*
** EPITECH PROJECT, 2018
** fichier.h
** File description:
** fichier.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Export.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Event.h>

typedef struct rpg_s
{
    int quit_forge;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *background;
    sfSprite *play;
    sfSprite *quit;
    sfSprite *plus_menu;
    sfSprite *minus_menu;
    sfVector2f pos_plus;
    sfVector2f pos_minus;
    sfIntRect rect_plus;
    sfIntRect rect_minus;
    sfMusic *bgm_menu;
    sfEvent event;
    sfIntRect rect;
    sfIntRect rect2;
    sfVector2f pos_play;
    sfVector2f pos_quit;
    int quitlevel;
    int accept;
    float x;
    int menu;
    int life;
    int world;
    int z;
    sfSprite *mute;
    sfVector2f pos_mute;
    int attack_heroes;
    int argent;
    int dest;
    sfSprite *fond;
    sfSprite *playy;
    sfSprite *quitt;
    sfVector2f pos_howto;
    sfSprite *howto;
    sfSprite *image;
} rpg_t;

typedef struct inventaire_s {
    sfSprite *inventaire1;
    sfSprite *inventaire2;
    sfSprite *inventaire3;
    sfVector2f pos_inventaire2;
    sfVector2f pos_inventaire3;
}inventaire_t;

typedef struct level_s {
    sfSprite *background;
    sfSprite *shop;
    sfVector2f pos_shop;
    sfSprite *level1;
    sfVector2f pos_lev1;
    sfSprite *level2;
    sfVector2f pos_lev2;
    sfSprite *level3;
    sfVector2f pos_lev3;
    sfSprite *level4;
    sfVector2f pos_lev4;
    sfSprite *level5;
    sfVector2f pos_lev5;
    sfSprite *level6;
    sfVector2f pos_lev6;
    int word;
    int x;

}level_t;

typedef struct forge_s
{
    sfSprite *background;
    sfIntRect rectsaler;
    sfIntRect rectheroes;
    sfTime time;
    sfText *text;
    sfFont *font;
    int p;
    sfClock *clock;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    sfSprite *buttone;
    sfVector2f pos_buttone;
    sfSprite *saler;
    sfVector2f pos_saler;
    sfSprite *attack;
    sfVector2f pos_attack;
    sfSprite *life;
    sfVector2f pos_life;
    sfSprite *heroes;
    sfVector2f pos_heroes;
}forge_t;

typedef struct level1_s
{
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    sfSprite *background;
    sfSprite *background2;
    sfSprite *background3;
    sfVector2f pos_atth;
    sfSprite *atth;
    sfSprite *up;
    sfSprite *down;
    sfIntRect rectup;
    sfTime time2;
    sfClock *clock2;
    sfIntRect rectdown;
    sfSprite *attackpistol;
    sfIntRect rectmunster1;
    sfSprite *attack;
    sfIntRect rectheroes;
    sfTime time1;
    sfClock *clock1;
    sfSprite *monster;
    sfVector2f pos_monster;
    sfVector2f pos_attack;
    sfSprite *heroes;
    sfVector2f pos_heroes;
    sfVector2f pos_up;
    sfVector2f pos_down;
    sfVector2f pos_munster1;
    sfSprite *munster1;
    sfVector2f pos_attackl;
    sfSprite *attackheroes;
    sfSprite *attack_monster1;
    sfVector2f pos_attack_monster1;
    int haut;
    int bas;
    int a;
    int life_munster1;
    int compteur1;

    sfSprite *munster1_1;
    sfVector2f pos_munster1_1;
    sfSprite *munster1_2;
    sfVector2f pos_munster1_2;
    sfSprite *munster1_3;
    sfVector2f pos_munster1_3;

    sfSprite *boule1;
    sfVector2f pos_boule1;
    sfSprite *boule2;
    sfVector2f pos_boule2;
    sfSprite *boule3;
    sfVector2f pos_boule3;
    int compteur11;
    int compteur2;
    int compteur3;
    int life1;
    int life2;
    int life3;

}level1_t;

typedef struct level2_s
{
    sfSprite *background;
    sfSprite *background2;
    sfSprite *background3;
    sfSprite *background4;
    sfSprite *background5;
    sfIntRect rectmonster2;
    sfIntRect rectheroes2;
    sfTime time2;
    sfClock *clock2;
    sfSprite *monster2;
    int lifemunster1;
    int lifemunster2;
    int lifemunster3;
    int compteur1;
    int compteur2;
    int compteur3;
    sfSprite *heroes2;
    sfVector2f pos_heroes2;
    sfVector2f pos_attackl;
    sfSprite *attack_heroes;
    sfVector2f pos_attheroes;
    int haut;
    int up;
    int bas;
    int compteur;
    sfVector2f pos_up;
    sfSprite *munster1;
    sfSprite *munster2;
    sfSprite *munster3;
    sfVector2f pos_monster1;
    sfVector2f pos_monster2;
    sfVector2f pos_monster3;
}level2_t;

typedef struct level3_s
{
    sfSprite *background3;
    sfIntRect rectmonster3;
    sfIntRect rectheroes3;
    sfTime time3;
    sfTime time4;
    sfClock *clock3;
    sfClock *clock4;
    sfSprite *monster3;
    sfVector2f pos_monster3;
    sfSprite *attack3;
    sfVector2f pos_attack3;
    sfSprite *heroes3;
    sfVector2f pos_heroes3;
    sfSprite *attack_heroes;
    sfVector2f pos_attheroes;
    int compteur;
    int life_boss1;
    int haut;
    sfTime time2;
    sfClock *clock2;
    int up;
    int bas;
    sfVector2f pos_up;
    sfSprite *victoire;

}level3_t;

#define def sfDefaultStyle

void my_putchar(char c);
void gameplay_haut3(rpg_t *my_struct, level3_t *my_level3);
void gameplay_bas3(rpg_t *my_struct, level3_t *my_level3);
int my_putstr(char const *str);
int my_getnbr(char const *str);
char *my_putnbr(int nb);
void *set_sprite(char const *pathfile);
void set_my_struct(rpg_t *my_struct);
void movement_for_heroes(rpg_t *my_struct, level1_t *my_level1);
void movement_for_heroes2(rpg_t *my_struct, level2_t *my_level2);
void movement_for_heroes3(level3_t *my_level3);
void transition_for_heroes2(rpg_t *my_struct, level2_t *my_level2, int a);
void transition_for_heroes(rpg_t *my_struct, level1_t *my_level1, int a);
int game();
void music_shop(rpg_t *my_struct, forge_t *my_forge);
void deplacement_heroes(rpg_t *my_struct, forge_t *my_forge);
void deplacement_heroes_level1(rpg_t *my_struct, level1_t *my_level1);
void deplacement_heroes_level2(rpg_t *my_struct, level2_t *my_level2);
void deplacement_heroes_level3(rpg_t *my_struct, level3_t *my_level3);
void set_my_level1(level1_t *my_level1);
void anim_heroes(level1_t *my_level1, rpg_t *my_struct);
void anim_heroes2(level2_t *my_level2);
void animl2(rpg_t *my_struct, level2_t *my_level2);
void gameplay_haut(rpg_t *my_struct, level1_t *my_level1);
void set_my_level1_1(level1_t *my_level1);
void in_level1(rpg_t *my_struct, level1_t *my_level1);
void anim_heroes2(level2_t *my_level2);
void in_level2(rpg_t *my_struct, level2_t *my_level2);
void set_my_level3(level3_t *my_level3);
void anim_heroes3(level3_t *my_level3);
void in_level3(rpg_t *my_struct, level3_t *my_level3);
void display_menu(rpg_t *my_struct, level_t *my_level);
void get_quit(rpg_t *my_struct);
void set_my_level(rpg_t *my_struct, level_t *my_level);
void set_my_level2(level2_t *my_level2);
void set_level(level_t *my_level);
void anim_down(level1_t *my_level1, rpg_t *my_struct);
void let_shop(rpg_t *my_struct, level_t *my_level);
void anim_up(level1_t *my_level1, rpg_t *my_struct);
void gameplay_bas(rpg_t *my_struct, level1_t *my_level1);
void set_my_forge(forge_t *my_forge);
void anim_saler(forge_t *my_forge);
void in_shop(rpg_t *my_struct, forge_t *my_forge);
void level1(rpg_t *my_struct, level_t *my_level);
void level2(rpg_t *my_struct, level_t *my_level);
void level3(rpg_t *my_struct, level_t *my_level);
void heroes_shop(rpg_t *my_struct, forge_t *my_forge);
void anim_heroes_shop(forge_t *my_forge);
void set_struct_volume(rpg_t *my_struct);
void set_sound(rpg_t *my_struct);
void anim_boss(level3_t *my_level3, rpg_t *my_struct);
void set_my_struct(rpg_t *my_struct);
void anim_munster(level1_t *my_level1, rpg_t *my_struct);
void get_play(rpg_t *my_struct);
void get_quit(rpg_t *my_struct);
void attack(level3_t *my_level3, rpg_t *my_struct);
void set_mute(rpg_t *my_struct);
void set_my_forge2(forge_t *my_forge);
void money(forge_t *my_forge);
void toupie(rpg_t *my_struct, forge_t *my_forge);
void monster(rpg_t *my_struct, level1_t *my_level1, int a);
void sshop(rpg_t *my_struct, forge_t *my_forge);
void quitt_forge(rpg_t *my_struct, forge_t *my_forge);
void attack_of_perso(level1_t *my_level1, rpg_t *my_struct);
void attack2(level1_t *my_level1, rpg_t *my_struct);
void attackl1(level1_t *my_level1, level3_t *my_level3, rpg_t *my_struct);
void set_my_attackl1(level1_t *my_level1);
void mounster1_life(level1_t *my_level1, rpg_t *my_struct);
void monster2(rpg_t *my_struct, level1_t *my_level1, int a);
int get_playyy(rpg_t *my_struct);
void set_my_attackl1_3(level1_t *my_level1);
void anim_monster2(rpg_t *my_struct, level1_t *my_level1);
void munster1(rpg_t *my_struct, level1_t *my_level1);
void munster2(rpg_t *my_struct, level1_t *my_level1);
void munster3(rpg_t *my_struct, level1_t *my_level1);
void quitlevel1(rpg_t *my_struct, level1_t *my_level1);
void button_stop(rpg_t *my_struct);
void set_my_pause(rpg_t *my_struct);
void anim_heroes22(level1_t *my_level1, rpg_t *my_struct, level2_t *my_level2);
void set_attack_boss(level3_t *my_level3);
void attackboss3(rpg_t *my_struct, level3_t *my_level3);
void my_howto(rpg_t *my_struct);
void gameplay_haut2(rpg_t *my_struct, level2_t *my_level2);
void gameplay_bas2(rpg_t *my_struct, level2_t *my_level2);
void finish_game(rpg_t *my_struct, level3_t *my_level3);
void setmy_attack(rpg_t *my_struct, level2_t *my_level2);
void inventaire(rpg_t *my_struct, inventaire_t *my_inv);
void set_my_inv(inventaire_t *my_inv);
#endif
