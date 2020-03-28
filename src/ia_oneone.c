/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** ia_oneone.c
*/

#include "../include/matchstick.h"

int where_is_first(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == '|')
                return (i);
        }
    }
    return (0);
}

void ia_remove(char **map, int line, int match)
{
    int size = test_last(map[line]);
    for (int i = 0; i < match; i += 1)
        map[line][size - i] = ' ';
}

void my_ia_getfirst(char **map)
{
    my_printf("\nAI's Turn...\n");
    int line = where_is_first(map);
    ia_remove(map, line, 1);
    my_printf("AI removed %d match(es) from line %d\n", 1, line);
}

int victory(char **map)
{
    int i = 0;
    int j = 0;
    int compteur = 0;

    for (; map[i]; i += 1) {
        for (; map[i][j]; j += 1) {
            if (map[i][j] == '|')
                compteur += 1;
        }
        j = 0;
    }
    if (compteur == 0)
        return (1);
    return (0);
}