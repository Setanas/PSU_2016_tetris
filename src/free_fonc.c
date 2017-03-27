/*
** free_fonc.c for free in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 28 11:02:47 2017 Sébastien TAN
** Last update Tue Mar 14 13:30:28 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

char		*free_one_line(char *str)
{
  free(str);
  return (NULL);
}

int		free_scandir(struct dirent **direct, int nbr_dir)
{
  int		incre;

  incre = 0;
  while (incre < nbr_dir)
    {
      free(direct[incre]);
      incre++;
    }
  free(direct);
  return (0);
}

int		free_link(t_link *link)
{
  t_link	*stock;

  stock = NULL;
  while (link->pos != 0)
    link = link->next;
  link = link->next;
  while (link->pos != 0)
    {
      stock = link;
      free(link->name);
      if (link->error == 0)
	free_wordtab(link->tetrimino);
      link = link->next;
      free(stock);
    }
  free(link->name);
  if (link->error == 0)
    free_wordtab(link->tetrimino);
  free(link);
  return (0);
}

int		free_wordtab(char **word)
{
  int		incre;

  incre = 0;
  while (word[incre] != NULL)
    {
      free(word[incre]);
      incre++;
    }
  free(word[incre]);
  free(word);
  return (84);
}

int		free_both_ret_less_1(char **map, char **line)
{
  int		incre;

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
