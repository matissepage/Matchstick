/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** returns a number given in a string as an int
*/

#include <stddef.h>
#include <stdlib.h>

int my_count_word(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] != ' ')
            count += 1;
        i += 1;
    }
    count += 1;
    return (count);
}

int my_count_letter(char *str)
{
    int i = 0;

    while (str[i] == ' ')
        i += 1;

    while (str[i] != ' ' && str[i] != '\0') {
        i += 1;
    }
    return (i);
}

void my_add_tab(char *elem, char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] == ' ')
        i += 1;

    while (str[i] != ' ' && str[i] != '\0') {
        elem[j] = str[i];
        i += 1;
        j += 1;
    }
    elem[j] = '\0';
}

char **my_str_to_word_array(char *str)
{
    int j = 0;
    int count = my_count_word(str);
    int size_word = 0;
    int tmp = 0;

    char **tab = malloc(sizeof(*tab) * (count + 1));

    while (j != count) {
        tmp = size_word;
        size_word = my_count_letter(str + size_word);
        tab[j] = malloc(sizeof(*tab[j]) * (size_word + 1));
        my_add_tab(tab[j], (str + tmp));
        j += 1;
    }
    tab[j] = NULL;
    return (tab);
}