/*
** fonct_tab_3.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Mar 14 12:41:10 2017 Sébastien TAN
** Last update Fri Mar 17 01:28:33 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

int	check_level(char *key)
{
  int	i;

  i = 0;
  if (key == NULL || key[0] == '\0')
    return (84);
  while (key[i] != '\0')
    {
      if (key[i] < 48 || key[i] > 57)
	return (84);
      i++;
    }
  return (0);
}

int	map_size_next(t_key *key_s, char *flag)
{
  int	incre;

  if ((key_s->map_size = malloc(sizeof(char) * my_strlen(flag) + 1)) == NULL)
    return (84);
  incre = 0;
  while (flag[incre] != '\0')
    {
      if (flag[incre] == ',')
	key_s->map_size[incre] = '*';
      else
	key_s->map_size[incre] = flag[incre];
      incre++;
    }
  key_s->map_size[incre] = '\0';
  return (0);
}
