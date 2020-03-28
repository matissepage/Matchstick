/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_error.c
*/

#include "../include/matchstick.h"

int error_line_number(int nb, int base_line)
{
    if (nb <= 0 || nb > base_line) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int error_match_number(char **map, int nb, int base_match, int line)
{
    int number_match = my_pipe_line(map, line);
    if (nb <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (nb > base_match) {
        my_printf("Error: you cannot remove more ");
        my_printf("than %d matches per turn\n", base_match);
        return (1);
    }
    if (nb > number_match) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int my_pipe_line(char **map, int i)
{
    int p_compteur = 0;
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == '|') {
            p_compteur += 1;
        }
    }
    return (p_compteur);
}
