/*
** gestion_tetrimino.c for tetris in /home/guillaume1chanut/PSU_2016_tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Sat Mar 11 20:35:22 2017 chanut
** Last update Sun Mar 19 17:15:26 2017 Sébastien TAN
*/

#include <time.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "my.h"

char		**put_tetrimino(char **map, t_link *tetriminoo, int x, int y)
{
  int		e;
  int		i;

  e = 0;
  i = 0;
  while (e != tetriminoo->y)
    {
      while (i != tetriminoo->x)
	{
	  if (tetriminoo->tetrimino[e][i] == '*')
	    map[x + e][y + i] = '*';
	  if (tetriminoo->tetrimino[e][i] == ' ')
	    map[x + e][y + i] = ' ';
	  i = i + 1;
	}
      i = 0;
      e = e + 1;
    }
  return (map);
}

int		find_random(int min, int max)
{
  int		result;

  result = 0;
  if ((max - min) > 0)
    result = rand()%(max - min) + min;
  else
    return (0);
  return (result);
}

t_link		*find_tetrimino(t_link *tetriminoo)
{
  int		i;
  int		e;

  i = 0;
  e = find_random(1, 100);
  while (i != e)
    {
      tetriminoo = tetriminoo->next;
      while (tetriminoo->error == -1)
	{
	  tetriminoo = tetriminoo->next;
	}
      i = i + 1;
    }
  return (tetriminoo);
}

int		inside_while_core(t_key *key, char **map, int *x_y,
				  int *coordonee, int color)
{
  static int	i = 0;
  int		k;
  int		quit;

  if (i == 0)
     my_put_tab(map, color, x_y[0]);
  map = is_scoring(map, x_y);
  if ((k = check_pos_on_map(coordonee, map, x_y[1])) == 1)
    return (1);
  if ((quit = which_touch(map, key, coordonee)) != 0 && quit != 2)
    return (quit);
  usleep(200);
  if (i == 2000 / my_getnbr(key->level))
    {
      i = 0;
      map = tetrimino_down(map, coordonee, color);
      my_put_tab(map, color, x_y[0]);
    }
  i = i + 1;
  return (0);
}

char	**core_tetrimino(t_link *tetri, t_key *key, char  **map, int *x_y)
{
  int	k;
  int	*coordonee;

  k = 0;
  tetri = find_tetrimino(tetri);
  if ((coordonee = get_position(tetri, x_y[0])) == NULL)
    return (NULL);
  if ((mode(0)) == 84)
    return (NULL);
   while (k == 0)
    {
      if ((k = inside_while_core(key, map, x_y, coordonee, tetri->color)) == 84)
	return (NULL);
      else if (k == 1 || k == 3)
	return (map);
    }
  if ((mode(1)) == 84)
    return (NULL);
  return (map);
}
