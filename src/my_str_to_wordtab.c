/*
** my_str_to_wdtab.c for tetris in /home/TAN_S/str_wd
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 28 19:19:48 2017 Sébastien TAN
** Last update Thu Mar 16 15:18:05 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

char		**my_str_to_wordtab(char *str, char sep)
{
  char		**wd;
  t_incre	ic;

  ic.c = 0;
  ic.l = 0;
  ic.i = 0;
  if ((wd = malloc(sizeof(char *) * nbr_word(str, sep))) == NULL)
    return (NULL);
  if ((wd[ic.l] = malloc(sizeof(char) * nb_cl(str, sep))) == NULL)
    return (NULL);
  while (str[ic.i] != '\0')
    {
      if ((while_wordtab(wd, str, sep, &ic)) == 84)
	return (NULL);
    }
  wd[ic.l] = NULL;
  return (wd);
}

int		while_wordtab(char **wd, char *str, char sep, t_incre *ic)
{
  int		max;

  max = nbr_word(str, sep);
  if ((str[ic->i] == sep && str[ic->i + 1] != sep))
    {
      if (str[ic->i + 1] == '\0' && str[ic->i] != sep)
	wd[ic->l][ic->c++] = str[ic->i];
      wd[ic->l++][ic->c] = '\0';
      if (ic->l != max - 1)
	  if ((wd[ic->l] = malloc(sizeof(char) * nb_cl(&str[ic->i], sep))) == NULL)
	    return (84);
      ic->i++;
      ic->c = 0;
    }
  if (str[ic->i] != sep && str[ic->i] != '\0')
    {
      wd[ic->l][ic->c] = str[ic->i];
      ic->c++;
      if (str[ic->i + 1] == '\0')
	wd[ic->l++][ic->c] = '\0';
    }
  if (str[ic->i] != '\0')
    ic->i++;
  return (0);
}

int		nbr_word(char *str, char sep)
{
  int		ic;
  int		line;

  ic = 0;
  line = 2;
  while (str[ic] != '\0')
    {
      if (str[ic] == sep && str[ic + 1] != sep && str[ic + 1] != '\0')
	line++;
      ic++;
    }
  return (line);
}

int		nb_cl(char *str, char sep)
{
  int		ic;
  int		cols;

  ic = 0;
  cols = 1;
  while (str[ic] == sep)
    ic++;
  while (str[ic] != sep && str[ic] != '\0')
    {
      ic++;
      cols++;
    }
  return (cols);
}
