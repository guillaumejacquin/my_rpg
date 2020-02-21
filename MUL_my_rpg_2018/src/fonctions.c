/*
** EPITECH PROJECT, 2019
** fonctions.c
** File description:
** fonctions
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int y = 0;
    int z = 0;
    int signe = 1;

    for (i = 0; str[i] != '\0' && z == 0; i = i + 1) {
        if (str[i] == '-')
            signe = -1 * signe;
        else if (str[i] < '0' || str[i] > '9') {
            z = 1;
        }
        if (str[i] >= '0' && str[i] <= '9'){
            y = y * 10 + (str[i] - '0' );
            if (str[i] < '0' && str[i] > '9' ){
                return ((y - 1) * 10 + (str[i] - '0' ));
            }
        }
    }
    return (y * signe);
}

char *my_putnbr(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int j = 1;

    while ((nb / j) >= 10)
        j = j * 10;
    while (j > 0) {
        str[i] = (nb/j) % 10 + '0';
        j = j / 10;
        i = i + 1;
    }
    while (i < 10) {
        str[i] = '\0';
        i += 1;
    }
    return (str);
}