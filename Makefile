##
## Makefile for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris
##
## Made by chanut
## Login   <guillaume1chanut@epitech.net>
##
## Started on  Mon Feb 20 18:57:39 2017 chanut
## Last update Mon Feb 20 18:57:39 2017 chanut
##

CC	= gcc

CFLAGS	= -Iinclude -Wextra -Wall

RM	= rm -f

SRCS	= ./src/main.c	 		\
	  ./src/error.c			\
	  ./src/get_next_line.c		\
	  ./src/tools.c			\
	  ./src/fonct_tab.c		\
	  ./src/fonct_tab_2.c		\
	  ./src/debug.c

OBJS	= $(SRCS:.c=.o)

NAME	= tetris

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
