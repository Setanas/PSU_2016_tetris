/*
** print_color.c for Semestre 1 in /home/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Sat Mar 11 20:30:10 2017 chanut
** Last update Sun Mar 19 16:18:10 2017 Sébastien TAN
*/

#include <fcntl.h>
#include <ncurses.h>
#include "my.h"

int	prc_2(char c)
{
  if (is_nbr(c) == 1)
    {
      attron(COLOR_PAIR(c - 45));
      printw("*");
      attroff(COLOR_PAIR(c - 45));
      return (1);
    }
  return (0);
}

int	print_3(char c)
{
	static int color = 11;

  if (c == '#')
    {
      attron(COLOR_PAIR(color));
      printw("#");
      attroff(COLOR_PAIR(color));
      color = color + 1;
      if (color > 13)
	color = 11;
      return (1);
    }
  if (is_nbr(c) == 1)
    {
      printw("%c", c);
      return (1);
    }
  return (0);
}

int	prc(char c, int color)
{
  if (c == '|')
    {
      attron(COLOR_PAIR(11));
      printw("|");
      attroff(COLOR_PAIR(11));
      return (1);
    }
    if (c == '.')
      {
        attron(COLOR_PAIR(1));
        printw(".");
        attroff(COLOR_PAIR(1));
        return (1);
      }
  if (c == '_')
    {
      attron(COLOR_PAIR(12));
      printw("_");
      attroff(COLOR_PAIR(12));
      return (1);
    }
  if (c == '*')
    return (print_color_tetrimino(color));
  return (0);
}

void	my_put_tab(char **tab, int color, int y)
{
  int	u[2];

  u[0] = 0;
  u[1] = 0;
  erase();
  while (tab[u[1]] != NULL)
    {
      while (tab[u[1]][u[0] - 1] != '\n')
	{
	  if (u[0] < y + 2)
	    {
	      if (prc(tab[u[1]][u[0]], color) == 0 && prc_2(tab[u[1]][u[0]]) == 0)
		printw("%c", tab[u[1]][u[0]]);
	    }
	  else
	    {
	      if (prc(tab[u[1]][u[0]], color) == 0 && print_3(tab[u[1]][u[0]]) == 0)
		printw("%c", tab[u[1]][u[0]]);
	    }
	  u[0] = u[0] + 1;
	}
      u[0] = 0;
      u[1] = u[1] + 1;
    }
  refresh();
}
