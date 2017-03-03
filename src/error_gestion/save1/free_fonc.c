/*
** free_fonc.c for free in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 28 11:02:47 2017 Sébastien TAN
** Last update Tue Feb 28 11:03:49 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

int	free_wordtab(char **word)
{
  int	incre;

  incre = 0;
  while (word[incre] != NULL)
    {
      free(word[incre]);
      incre++;
    }
  free(word);
  return (84);
}

int	free_both_ret_less_1(char **map, char **line)
{
  int	incre;

  incre = 0;
  while (map[incre] != NULL)
    {
      free(map[incre]);
      incre++;
    }
  free(map);
  incre = 0;
  while (line[incre] != NULL)
    {
      free(line[incre]);
      incre++;
    }
  free(line);
  return (- 1);
}
