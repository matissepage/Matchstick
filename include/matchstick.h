/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq.h
*/

#ifndef MY_MATCHSTICK_H_
#define MY_MATCHSTICK_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "../lib/my/my_printf.h"


/*####### Display #######*/

void display_map(char **map);
char **pipe_display(int size, char **map);
char *my_line(char *str, char c, int size);
char **generate_map(int size);
int test_last(char *str);
int commpt_data(char **map);
char **first_display(int line);
int print_game_board(int line, int colums);

/*####### Get input #######*/

int user_turn(char **map, int line, int match);
int asking_line_number(void);
int asking_match_number(void);
void remove_stick(char **map, int line, int match);


/*####### Remove stick #######*/

void remove_stick(char **map, int line, int match);

/*####### Error Case #######*/

int error_line_number(int nb, int base_line);
int error_match_number(char **map, int nb, int base_match, int line);
int my_pipe_line(char **map, int i);

/*####### Ia One One #######*/

int where_is_first(char **map);
void my_ia_getfirst(char **map);
int victory(char **map);
void ia_turn(char **map);
void ia_disp(char **map);

/*####### Victory #######*/

int victory(char **map);

#endif /*MY_MATCHSTICK_H*/