/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** asking.c
*/

#include "../include/matchstick.h"

int asking_line_number(void)
{
    char *buffer = NULL;
    size_t size;
    my_printf("Line: ");
    if (getline(&buffer, &size, stdin) == -1) {
        return (-1);
    }
    return (my_getnbr(buffer));
}

int asking_match_number(void)
{
    char *buffer = NULL;
    size_t size;
    if (getline(&buffer, &size, stdin) == -1)
        return (-1);
    return (my_getnbr(buffer));
}