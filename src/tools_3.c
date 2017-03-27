/*
** tools_3.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Sat Mar 18 22:31:51 2017 Sébastien TAN
** Last update Sun Mar 19 16:51:47 2017 Sébastien TAN
*/

#include <ncurses.h>
#include "my.h"

void	init_use(int *use)
{
  use[0] = 0;
  use[1] = 1;
  use[2] = 0;
}

int	norme_move_turn(char *size_1, int *i)
{
  *i = 1;
  return (my_getnbr(size_1));
}

int	init_every_color()
{
  if (((init_pair(1, COLOR_WHITE, COLOR_WHITE)) == ERR) ||
      ((init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA)) == ERR) ||
      ((init_pair(3, COLOR_BLUE, COLOR_BLUE)) == ERR) ||
      ((init_pair(4, COLOR_RED, COLOR_RED)) == ERR) ||
      ((init_pair(5, COLOR_GREEN, COLOR_GREEN)) == ERR) ||
      ((init_pair(6, COLOR_YELLOW, COLOR_YELLOW)) == ERR) ||
      ((init_pair(7, COLOR_BLUE, COLOR_BLUE)) == ERR) ||
      ((init_pair(8, COLOR_MAGENTA, COLOR_MAGENTA)) == ERR) ||
      ((init_pair(9, COLOR_CYAN, COLOR_CYAN)) == ERR) ||
      ((init_pair(10, COLOR_WHITE, COLOR_WHITE)) == ERR) ||
      ((init_pair(11, COLOR_MAGENTA, COLOR_BLACK)) == ERR) ||
      ((init_pair(12, COLOR_BLUE, COLOR_BLACK)) == ERR) ||
      ((init_pair(13, COLOR_RED, COLOR_BLACK)) == ERR))
    return (84);
  return (0);
}

int	print_color_tetrimino(int color)
{
  attron(COLOR_PAIR(color));
  printw("*");
  attroff(COLOR_PAIR(color));
  return (1);
}

int	is_nbr(int nb)
{
  if (nb > 47 && nb < 58)
    return (1);
  return (0);
}
