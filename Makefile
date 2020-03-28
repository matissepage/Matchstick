##
## EPITECH PROJECT, 2019
## PSU_my_printf_bootstrap_2019
## File description:
## Makefile
##

SRC		=	./src/matchstick.c 			\
			./src/ia_oneone.c 			\
			./src/display_map.c 		\
			./src/user.c 				\
			./src/asking.c 				\
			./src/my_error.c 			\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

LIB		= make -C ./lib/my

RM		= rm -f

NAME	=  matchstick

CFLAGS	= -W -Wall -Wextra -g3

all: 		$(NAME)

$(NAME):
		$(LIB)
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) ./lib/libmy.a
		@echo "\033[5m\033[1m\033[32m>$(NAME) DONE\033[0m"

tests_run:
		gcc -o units tests/*.c ./src/my_error.c --coverage -lcriterion ./lib/libmy.a
		./units

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		$(RM) *.gcda
		$(RM) *.gcno

fclean: clean
		$(RM) $(NAME)
		$(RM) units
		$(LIB) fclean

re:		fclean all