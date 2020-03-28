/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_remove.c
*/

#include "../include/matchstick.h"

int user_turn(char **map, int line, int match)
{
    int remove_line = asking_line_number();
    int remove_match;

    if (remove_line == -1)
        return (-1);
    if (error_line_number(remove_line, line) == 1) {
        if (user_turn(map, line, match) == -1)
            return (-1);
        return (0);
    } else {
        my_printf("Matches: ");
        remove_match = asking_match_number();
        if (remove_match == -1)
            return (-1);
        if (error_match_number(map, remove_match, match, remove_line) == 1) {
            if (user_turn(map, line, match) == -1)
                return (-1);
            return (3);
        }
    }
    remove_stick(map, remove_line, remove_match);
    return (0);
}

void remove_stick(char **map, int line, int match)
{
    int size = test_last(map[line]);
    for (int i = 0; i < match; i += 1) {
        if (map[line][size - i] == '|')
            map[line][size - i] = ' ';
    }
    my_printf("Player removed %d match(es) from line %d\n", match, line);
}