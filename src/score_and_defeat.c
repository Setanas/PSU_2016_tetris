/*
** score_and_defeat.c for tetris in /home/guillaume1chanut/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Wed Mar 15 16:31:03 2017 chanut
** Last update Sun Mar 19 17:34:10 2017 chanut
*/

#include <stdlib.h>
#include "my.h"

char		**supp_ligne(char **map, int e, int x_y[3])
{
  int		i;

  i = 1;
  while (e != 0)
    {
      while (i != x_y[0])
	{
	  map[e][i + 1] = map[e - 1][i + 1];
	  i = i + 1;
	}
      i = 1;
      e = e - 1;
    }
  x_y[2] = x_y[2] + x_y[0];
  map = put_score(map, x_y[0], x_y[2]);
  return (map);
}

char	**is_scoring(char **map, int x_y[3])
{
  int	c;
  int	e;
  int	i;

  c = 0;
  i = 0;
  e = -1;
  while (e++ != x_y[1])
    {
      while (i != x_y[0])
	{
	  if (is_nbr(map[e][i + 1]) == 1)
	    c = c + 1;
	  i = i + 1;
	}
      if (c == x_y[0] - 1)
	map = supp_ligne(map, e, x_y);
      c = 0;
      i = 1;
    }
  return (map);
}

int	is_defeat(char **map, int y)
{
  int	i;

  i = 0;
  while (i != y)
    {
      if (is_nbr(map[1][i]) == 1)
	return (1);
      i = i + 1;
    }
  return (0);
}
