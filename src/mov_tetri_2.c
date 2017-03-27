/*
** mov_tetri_2.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Mar 16 22:07:58 2017 Sébastien TAN
** Last update Sun Mar 19 17:22:59 2017 Sébastien TAN
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int	check_move_left(char **map, int *coordonees)
{
  int	u;

  u = 1;
  while (coordonees[u] != -1)
    {
      if (map[coordonees[u]][coordonees[u + 1] - 1] == '|')
	return (1);
      if (is_nbr(map[coordonees[u]][coordonees[u + 1] - 1]) == 1 &&
	  is(coordonees[u], coordonees[u + 1] - 1, coordonees) == 0)
	return (1);
      u = u + 2;
    }
  return (0);
}

int	check_move_right(char **map, int *coordonees)
{
  int	u;

  u = 1;
  while (coordonees[u] != -1)
    {
      if (coordonees[u + 1] == -1)
	return (0);
      if (map[coordonees[u]][coordonees[u + 1] + 1] == '|')
	return (1);
      if (is_nbr(map[coordonees[u]][coordonees[u + 1] + 1]) == 1 &&
	  is(coordonees[u], coordonees[u + 1] + 1, coordonees) == 0)
	return (1);
      u = u + 2;
    }
  return (0);
}

char	**move_drop(char **map, int *coordonee,
		    __attribute__ ((unused)) t_key *key)
{
  int	color;
  char	**size;
  int	x;

  if ((size = my_str_to_wordtab(key->map_size, '*')) == NULL)
    return (NULL);
  x = my_getnbr(size[0]);
  color = map[coordonee[1]][coordonee[2]] - 48;
  while (check_pos_on_map(coordonee, map, x) == 0)
    {
      map = tetrimino_down(map, coordonee, color);
    }
  free_wordtab(size);
  return (map);
}

char	**move_quit(__attribute__ ((unused)) char **map,
		    __attribute__ ((unused)) int *coordonee,
		    __attribute__ ((unused)) t_key *key)
{
  return (NULL);
}

char	**move_pause(__attribute__ ((unused)) char **map,
		     __attribute__ ((unused)) int *coordonee,
		     t_key *key)
{
  char	*quit;
  int	size;

  size = my_strlen(key->pause) + 1;
  if ((quit = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  my_memset(quit, size);
  printw("Pause\n");
  print_tetrimino(key);
  my_printw_key(key->pause, "to continue");
  my_printw_key(key->quit, "to quit the game");
  refresh();
  while ((str_comp(quit, key->pause, my_strlen(quit))) != 0)
    {
      my_memset(quit, size);
      if ((read(0, quit, size)) == -1)
	return (NULL);
      if ((str_comp(quit, key->quit, my_strlen(quit))) == 0)
	return (NULL);
    }
  return (map);
}
