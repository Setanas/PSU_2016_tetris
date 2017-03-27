##
## Makefile for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris
##
## Made by chanut
## Login   <guillaume1chanut@epitech.net>
##
## Started on  Mon Feb 20 18:57:39 2017 chanut
## Last update Sun Mar 19 23:29:50 2017 Sébastien TAN
##

CC	= gcc

CFLAGS	= -W -Wextra -Wall

CFLAGS	+= -I include

LDFLAGS	= -lncurses

RM	= rm -f

SRCS	= ./src/main.c	 		\
	  ./src/error.c			\
	  ./src/get_next_line.c		\
	  ./src/tools.c			\
	  ./src/tools_2.c		\
	  ./src/tools_3.c		\
	  ./src/fonct_tab.c		\
	  ./src/fonct_tab_2.c		\
	  ./src/fonct_tab_3.c		\
	  ./src/call_the_error.c	\
	  ./src/check.c			\
	  ./src/fill_linked_list.c	\
	  ./src/free_fonc.c		\
	  ./src/my_str_to_wordtab.c	\
	  ./src/my_put.c		\
	  ./src/my_getnbr.c		\
	  ./src/debug.c			\
	  ./src/start_game.c		\
	  ./src/map.c			\
	  ./src/gestion_tetrimino.c	\
	  ./src/tetromino_pos.c		\
	  ./src/print_color.c		\
	  ./src/mov_tetri.c		\
	  ./src/mov_tetri_2.c		\
	  ./src/score_and_defeat.c	\
	  ./src/which_touch.c		\
	  ./src/uid.c

OBJS	= $(SRCS:.c=.o)

NAME	= tetris

$(NAME): $(OBJS)
	 $(CC) $(OBJS) $(LDFLAGS) -o $(NAME) -lncurses

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
