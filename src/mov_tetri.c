/*
** mov_tetri.c for Semestre 1 in /home/guillaume1chanut/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Mar 13 19:49:41 2017 chanut
** Last update Sat Mar 18 22:59:25 2017 Sébastien TAN
*/

#include <ncurses.h>
#include "my.h"

void	check_size(int size, int collum)
{
  int	y;
  int	x;

  getmaxyx(stdscr, y, x);
  while (y < size || x < collum)
    {
      erase();
      mvprintw(y / 2, (x - 34) / 2, "Please increase your terminal size");
      getmaxyx(stdscr, y, x);
      refresh();
    }
}

int	is(int x, int y, int *coordonees)
{
  int	i;

  i = 1;
  while (coordonees[i] != -1)
    {
      if (coordonees[i] == x && coordonees[i + 1] == y)
	return (1);
      i = i + 2;
    }
  return (0);
}

char	**move_left(char **map, int *coordonees,
		    __attribute__ ((unused)) t_key *key)
{
  int	u;

  u = 1;
  if (check_move_left(map, coordonees) == 0)
    {
      while (coordonees[u] != -1)
	{
	  if (coordonees[u + 1] > 0)
	    map[coordonees[u]][coordonees[u + 1]] = ' ';
	  map[coordonees[u]][coordonees[u + 1] - 1] = '*';
	  coordonees[u + 1] = coordonees[u + 1] - 1;
	  u = u + 2;
	}
      }
  return (map);
}

char	**move_right(char **map, int *coordonees,
		     __attribute__ ((unused)) t_key *key)
{
  int	u;

  u = 1;
  if (check_move_right(map, coordonees) == 0)
    {
      while (coordonees[u] != -1)
	{
	  if (coordonees[u + 1] > 0)
	    map[coordonees[u]][coordonees[u + 1]] = ' ';
	  map[coordonees[u]][coordonees[u + 1] + 1] = '*';
	  coordonees[u + 1] = coordonees[u + 1] + 1;
	  u = u + 2;
	}
    }
  return (map);
}

char	**move_turn(char **map, int *coordonees,
		    __attribute__ ((unused)) t_key * key)
{
  int	i;
  int	y;
  char	**size;

  if ((size = my_str_to_wordtab(key->map_size, '*')) == NULL)
    return (NULL);
  y = norme_move_turn(size[1], &i);
  if (check_move_left(map, coordonees) == 0 &&
      check_move_right(map, coordonees) == 0)
    {
      while (coordonees[i] != -1)
	{
	  map[coordonees[i]][coordonees[i + 1]] = ' ';
	  i = i + 2;
	}
      if (switch_position(coordonees, y) == 84)
	return (NULL);
      i = 1;
      while (coordonees[i] != -1)
	{
	  map[coordonees[i]][coordonees[i + 1]] = '*';
	  i = i + 2;
	}
    }
  return (map);
}
