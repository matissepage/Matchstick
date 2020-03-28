/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** display_map.c
*/

#include "../include/matchstick.h"

void display_map(char **map)
{
    for (int i = 0; map[i]; i++)
        my_printf("%s\n", map[i]);
}

char **pipe_display(int size, char **map)
{
    int line = size;
    int column = 1;
    int count = 0;

    for (count = 0; column <= size; count++) {
        line = (size - count);
        while (line < (size + count + 1)) {
            map[column][line] = '|';
            line++;
        }
        column++;
    }
    return (map);
}

char *my_line(char *str, char c, int size)
{
    int ligne;

    for (ligne = 0; ligne < size; ligne++)
        str[ligne] = c;
    str[ligne] = '\0';
    return (str);
}

char **generate_map(int size)
{
    char **map;
    int ligne = 1;
    int pos = 0;

    map = malloc(sizeof(map) * (size + 3));
    for (;pos < (size + 2); pos += 1)
        map[pos] = malloc(sizeof(char) * (size * 2) + 3);
    map[pos] = NULL;
    map[0] = my_line(map[0], '*', (size * 2) + 1);
    for (; ligne < size + 1; ligne += 1) {
        map[ligne] = my_line(map[ligne], ' ', (size * 2) + 1);
        map[ligne][0] = '*';
        map[ligne][size * 2] = '*';
    }
    map[size + 1] = my_line(map[size + 1], '*', (size * 2) + 1);
    return (map);
}

int test_last(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|' && str[i + 1] != '|')
        return (i);
    }
    return (0);
}