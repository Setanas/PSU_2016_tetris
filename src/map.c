/*
** map.c for Semestre 1 in /home/guillaume1chanut/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Tue Mar 07 12:27:13 2017 chanut
** Last update Sun Mar 19 17:34:44 2017 chanut
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ncurses.h>
#include "my.h"

char	**fill_map_2(char **map, int x, int y, t_key *key)
{
  int	e;
  int	i;

  i = 0;
  e = 0;
  while (i != y + 1)
    {
      while (e++ != x + 23)
      {
	if ((e == x + 3 && i < 12) || (e == x + 23 && i < 12))
	    map[i][e] = '#';
	else if ((e > x + 2 && i == 0) || (e > x + 2 && i == 5))
	    map[i][e] = '#';
	else if ((e > x + 2 && i == 11))
	    map[i][e] = '#';
      }
      e = 0;
      i = i + 1;
    }
  map = place_uid(map, x, y, key);
  return (map);
}

char	**fill_mapp(char **map, int x, int y, t_key *key)
{
  int	e;
  int	i;

  i = 0;
  e = -1;
  while (i != y + 1)
    {
      while (e++ != x + 23)
	{
	  if (i == y && e < x + 3)
	    map[i][e] = '_';
	  else if (e == 0 || e == 1 || e == x + 1 || e == x + 2)
	    map[i][e] = '|';
	  else if (e < x + 3)
	    map[i][e] = ' ';
	  else
	    map[i][e] = ' ';
	}
      map[i][e] = '\n';
      e = -1;
      i = i + 1;
    }
  map[i] = '\0';
  map = fill_map_2(map, x, y, key);
  return (map);
}

char	**intitia_map(int x, int y, t_key *key)
{
  int	i;
  char	**map;

  i = 0;
  if ((map = malloc(sizeof(char *) * (y + 2))) == NULL)
    return (NULL);
  while (i != y + 1)
    {
      if ((map[i] = malloc(sizeof(char) * (x + 25))) == NULL)
	  return (NULL);
      i = i + 1;
    }
  map = fill_mapp(map, x, y, key);
  return (map);
}

char	**init_screen(int x, int y, t_key *key)
{
  char	**map;

  if ((map = intitia_map(x, y, key)) == NULL)
    return (NULL);
  initscr();
  if ((curs_set(0) == ERR || keypad(stdscr, TRUE) == ERR))
    return (NULL);
  start_color();
  if ((init_every_color()) == 84)
    return (NULL);
  return (map);
}

int	core(t_link *link, t_key *key)
{
  int	x_y[3];
  char	**size;
  char	**map;

  if ((size = my_str_to_wordtab(key->map_size, '*')) == NULL)
    return (84);
  x_y[1] = my_getnbr(size[0]);
  x_y[0] = my_getnbr(size[1]);
  x_y[2] = 0;
  if ((map = init_screen(x_y[0], x_y[1], key)) == NULL)
    return (84);
  map = put_score(map, x_y[0], x_y[2]);
  while (1)
    {
      check_size(x_y[0], x_y[1]);
      if ((map = core_tetrimino(link, key, map, x_y)) == NULL)
	return (84);
      if (is_defeat(map, x_y[1]) == 1)
	{
	  endwin();
	  put_your_score(x_y[2]);
	  return (0);
	}
    }
  return (0);
}
