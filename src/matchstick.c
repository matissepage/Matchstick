/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "../include/matchstick.h"

int commpt_data(char **map)
{
    int compteur = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == '|')
                compteur += 1;
        }
    }
    return (compteur);
}

char **first_display(int line)
{
    char **map;
    map = generate_map(line);
    map = pipe_display(line, map);
    display_map(map);
    return (map);
}

void ia_disp(char **map)
{
    my_ia_getfirst(map);
    display_map(map);
}

int print_game_board(int line, int colums)
{
    char **map;
    map = first_display(line);

    while (commpt_data(map) != 0) {
        my_printf("\nYour turn:\n");
        if (user_turn(map, line, colums) == -1) {
            return (0);
        }
        display_map(map);
        if (victory(map) == 1) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        ia_disp(map);
        if (victory(map) == 1) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1 || ac == 2) {
        return (84);
    } else if (ac == 3) {
        if (my_str_isnum(av[1]) == 0)
            return (84);
        if (my_str_isnum(av[2]) == 0)
            return (84);
        int line = my_getnbr(av[1]);
        int colum = my_getnbr(av[2]);
        return (print_game_board(line, colum));
    }
    return (0);
}