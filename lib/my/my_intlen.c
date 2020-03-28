/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_intlen.c
*/

int my_intlen(int *list)
{
    int i = 0;
    while (list[i])
        i++;
    return (i);
}