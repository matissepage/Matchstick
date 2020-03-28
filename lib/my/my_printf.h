/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** my_printf.h
*/

#ifndef MY_PRiNTF_H
#define MY_PRINTF_H

#include <stdarg.h>

void my_control(char c, va_list ap);
void my_printf(char *str, ...);
void is_number(va_list ap);
void is_str(va_list ap);
void is_char(va_list ap);
void is_octal(va_list ap);
void is_hex(va_list ap);
void is_hexx(va_list ap);
void is_unsigned(va_list ap);
void is_binary(va_list ap);

typedef struct array_fct {
    char c;
    void (*fct)(va_list);
}array;

#endif /*MY_PRINTF_H*/