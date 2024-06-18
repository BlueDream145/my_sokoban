##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_engine.c \
		src/my_engine_fields.c \
		src/my_engine_menu.c \
		src/my_engine_select.c \
		src/my_engine_utils.c \
		src/my_report.c \
		src/my_utils.c \
		src/my_get.c \
		src/my_map.c \
		src/my_put.c \
		src/my_random_entity.c \
		src/my_random.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	gcc $(SRC) -Wall -Wextra -lncurses -I ../include -o $(NAME) -g -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
