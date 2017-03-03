/*
** fill_linked_list.c for tetris in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Mar 02 21:22:38 2017 Sébastien TAN
** Last update Fri Mar 03 10:45:30 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

int	put_name_and_error(t_link *maillon, char *name, int error)
{
  int	size;
  int	incre;

  size = my_strlen(name) - 10;
  incre = 0;
  if ((maillon->name = malloc(sizeof(char) * size + 1)) == NULL)
    return (84);
  while (incre < size)
    {
      maillon->name[incre] = name[incre];
      incre++;
    }
  maillon->name[incre] = '\0';
  if (error == 0)
    maillon->error = 1;
  return (0);
}

int	fill_maillon(char **map, char **first_line, t_link *maillon, int error)
{
  int	size;

  size = 0;
  if (error == - 1)
    {
      maillon->error = - 1;
      return (- 1);
    }
  maillon->error = 0;
  maillon->x = my_getnbr(first_line[0]);
  maillon->y = my_getnbr(first_line[1]);
  maillon->color = my_getnbr(first_line[2]);
  while (map[size] != NULL)
    size++;
  if ((fill_map(map, maillon, size)) == 84)
    return (84);
  return (0);
}

int	fill_map(char **map, t_link *maillon, int size)
{
  int	ic;
  int	incre_cols;
  int	size_cols;

  ic = 0;
  incre_cols = 0;
  if ((maillon->tetrimino = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (84);
  while (ic < size)
    {
      size_cols = my_strlen(map[ic]);
      if ((maillon->tetrimino[ic] = malloc(sizeof(char) * size_cols + 1)) == NULL)
	return (84);
      while (map[ic][incre_cols] != '\0')
	{
	  maillon->tetrimino[ic][incre_cols] = map[ic][incre_cols];
	  incre_cols++;
	}
      maillon->tetrimino[ic][incre_cols] = '\0';
      ic++;
      incre_cols = 0;
    }
  maillon->tetrimino[ic] = NULL;
  return (0);
}
