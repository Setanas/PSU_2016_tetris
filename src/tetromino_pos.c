/*
** tetromino_pos.c for tetris in /home/guillaume1chanut/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Sun Mar 12 16:14:25 2017 chanut
** Last update Sun Mar 19 11:50:49 2017 chanut
*/

#include <stdlib.h>
#include "my.h"

int	switch_position(int *coordone, int y)
{
  int	i;
  int	save;
  int	save_2;

  i = 1;
  save = coordone[1];
  while (coordone[i] != -1)
    {
      coordone[i] = coordone[i] - save + 1;
      coordone[i + 1] = coordone[i + 1] - (y / 2);
      i = i + 2;
    }
  i = 1;
  while (coordone[i] != -1)
    {
      save_2 = coordone[i];
      coordone[i] = coordone[i + 1] + save - 1;
      coordone[i + 1] = save_2 + (y / 2) - 1;
      i = i + 2;
    }
  return (0);
}

int	nb(t_link *tetrimino)
{
  int	u;
  int	i;
  int	e;

  i = 0;
  e = 0;
  u = 0;
  while (tetrimino->tetrimino[e] != NULL)
    {
      while (tetrimino->tetrimino[e][i] != '\0')
	{
	  if (tetrimino->tetrimino[e][i] == '*')
	    u = u + 1;
	  i = i + 1;
	}
      i = 0;
      e = e + 1;
    }
  return (u);
}

int	check_pos_on_map(int *c, char **map, int x)
{
  int	i;

  i = 1;
  while (c[i] != -1)
    {
      if (is_nbr(map[c[i] + 1][c[i + 1]]) == 1
	  && is(c[i] + 1, c[i + 1], c) == 0)
	return (1);
      if ((c[i]) >= x - 1)
	{
	  return (1);
	}
      c[0] = c[0] + 1;
      i = i + 2;
    }
  return (0);
}

char	**tetrimino_down(char **map, int *coordonees, int color)
{
  int	u;

  u = 1;
  while (coordonees[u] != -1)
    {
      coordonees[u] = coordonees[u] + 1;
      map[coordonees[u]][coordonees[u + 1]] = color + 48;
      if (is(coordonees[u] - 1, coordonees[u + 1], coordonees) == 0)
	map[coordonees[u] - 1][coordonees[u + 1]] = ' ';
      u = u + 2;
    }
  return (map);
}

int	*get_position(t_link *tetrimino, int y)
{
  int	use[3];
  int	*coordonee;

  init_use(use);
  if ((coordonee = malloc(sizeof(int) * ((nb(tetrimino) * 2) + 2))) == NULL)
      return (NULL);
  while (tetrimino->tetrimino[use[2]] != NULL)
    {
      while (tetrimino->tetrimino[use[2]][use[0]++] != '\0')
      {
	if (tetrimino->tetrimino[use[2]][use[0] - 1] == '*')
	    {
	      coordonee[use[1]] = use[2];
	      if (nb(tetrimino) == y - 1)
		coordonee[use[1] + 1] = use[0] + 1;
	      else
		coordonee[use[1] + 1] = use[0] + (y / 2) + 0;
	      use[1] = use[1] + 2;
	    }
      }
      use[0] = 0;
      use[2] = use[2] + 1;
    }
  coordonee[use[1]] = -1;
  return (coordonee);
}
