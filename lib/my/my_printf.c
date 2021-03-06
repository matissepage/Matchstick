/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include "my_printf.h"
#include "my.h"

static array fct_tab[] = {
    {'d', is_number},
    {'s', is_str},
    {'c', is_char},
    {'i', is_number},
    {'o', is_octal},
    {'x', is_hex},
    {'X', is_hexx},
    {'u', is_unsigned},
    {'b', is_binary},
};

void my_control(char c, va_list ap)
{
    for (int i = 0; i < 9; i += 1) {
        if (c == fct_tab[i].c) {
            fct_tab[i].fct(ap);
        }
    }
}

void my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '%') {
            i += 1;
            my_control(str[i], ap);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
}
