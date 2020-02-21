/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "rpg.h"

void set_all_struct(rpg_t *my_struct, level_t *my_level, forge_t *my_forge
                    , level1_t *my_level1)
{
    set_my_struct(my_struct);
    set_level(my_level);
    set_my_forge(my_forge);
    set_my_forge2(my_forge);
    set_my_level1(my_level1);
    set_my_level1_1(my_level1);
    my_struct->attack_heroes = 1;
    set_my_attackl1_3(my_level1);
    my_level1->compteur1 = 0;
    my_level1->compteur2 = 0;
    my_level1->compteur3 = 0;
    my_level1->life1 = 0;
    my_level1->life2 = 0;
    my_level1->life3 = 0;
    my_level1->compteur11 = 0;
    my_struct->argent = 0;
    my_struct->dest = 0;
    set_my_pause(my_struct);
}

void set_all_struct2(level2_t *my_level2, level3_t *my_level3)
{
    set_my_level2(my_level2);
    set_my_level3(my_level3);
    set_attack_boss(my_level3);
    my_level3->compteur = 0;
    my_level3->haut = 0;
    my_level3->up = 0;
    my_level3->bas = 0;
    my_level2->up = 0;
    my_level2->haut = 0;
    my_level2->bas = 0;
    my_level2->compteur = 0;
    my_level2->lifemunster1 = 0;
    my_level2->lifemunster2 = 0;
    my_level2->lifemunster3 = 0;
    my_level2->compteur1 = 0;
    my_level2->compteur2 = 0;
    my_level2->compteur3 = 0;
    int accept = 0;
}

int game(void)
{
    rpg_t my_struct;
    level_t my_level;
    forge_t my_forge;
    level1_t my_level1;
    level2_t my_level2;
    level3_t my_level3;
    inventaire_t my_inv;

    set_all_struct(&my_struct, &my_level, &my_forge, &my_level1);
    set_all_struct2(&my_level2, &my_level3);
    set_my_attackl1(&my_level1);
    setmy_attack(&my_struct, &my_level2);
    set_my_inv(&my_inv);
    sfRenderWindow_setFramerateLimit(my_struct.window, 500);
    // my_struct.attack_heroes = 1;
    while (sfRenderWindow_isOpen(my_struct.window)) { 
        button_stop(&my_struct);
        inventaire(&my_struct, &my_inv);
        if (my_struct.menu == 1)
            set_my_level(&my_struct, &my_level);
        my_howto(&my_struct);
        display_menu(&my_struct, &my_level);
        if (my_struct.menu == 2)
            return (2);
        if (my_struct.world == 1) {
            sfRenderWindow_drawSprite(my_struct.window, my_forge.saler, NULL);
            sfRenderWindow_drawSprite(my_struct.window, my_forge.heroes, NULL);
            in_shop(&my_struct, &my_forge);
            //heroes_shop(&my_struct, &my_forge);
            deplacement_heroes(&my_struct, &my_forge);
            money(&my_forge);
            music_shop(&my_struct, &my_forge);
            sfRenderWindow_drawSprite(my_struct.window, my_forge.saler, NULL);
            sfRenderWindow_drawSprite(my_struct.window, my_forge.heroes, NULL);
        }
        if (my_struct.world == 3) {
            in_level1(&my_struct, &my_level1);
            deplacement_heroes_level1(&my_struct, &my_level1);
            gameplay_haut(&my_struct, &my_level1);
            gameplay_bas(&my_struct, &my_level1);
            attack_of_perso(&my_level1, &my_struct);
            quitlevel1(&my_struct, &my_level1);
        }
        if (my_struct.world == 4) {
            in_level2(&my_struct, &my_level2);
            deplacement_heroes_level2(&my_struct, &my_level2);
            gameplay_bas2(&my_struct, &my_level2);
            gameplay_haut2(&my_struct, &my_level2);
            animl2(&my_struct, &my_level2);
            
        }
        if (my_struct.world == 5) {
            in_level3(&my_struct, &my_level3);
            attackboss3(&my_struct, &my_level3);
            gameplay_haut3(&my_struct, &my_level3);
            gameplay_bas3(&my_struct, &my_level3);
            finish_game(&my_struct, &my_level3);
        }
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        my_putstr("Have a nice play!\n");
    else if (ac == 1)
        game();
    else {
        write(2, "Invalid Command.\n", 17);
        return (84);
    }
    return (0);
}
