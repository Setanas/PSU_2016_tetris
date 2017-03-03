/*
** my_str_to_wordtab.c for str in /home/TAN_S/str_word
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Feb 27 19:17:02 2017 Sébastien TAN
** Last update Tue Feb 28 00:54:21 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

void	init_value(int *incre_line, int *incre_cols, int *incre)
{
  *incre = 0;
  *incre_cols = 0;
  *incre_line = 0;
}

int	nbr_of_line(char *str, char sep)
{
  int	incre;
  int	line;

  incre = 0;
  line = 0;
  while (str[incre] != '\0')
    {
      if (str[incre] == sep && str[incre + 1] != sep)
	line++;
      incre++;
    }
  line = line + 2;
  return (line);
}

int	nbr_of_cols(char *str, char sep)
{
  int	incre;

  incre = 0;
  while (str[incre] != sep && str[incre] != '\0')
    incre++;
  incre = incre + 1;
  return (incre);
}

char	**malloc_char_star(char *str, char sep)
{
  char	**word;
  int	line;
  int	size_cols;
  int	incre;

  incre = 0;
  line = nbr_of_line(str, sep);
  size_cols = 0;
  if ((word = malloc(sizeof(char *) * (line))) == NULL)
    return (NULL);
  line = 0;
  while (str[incre] != '\0')
    {
      size_cols = nbr_of_cols(&str[incre], sep);
      if ((word[line] = malloc(sizeof(char) * (size_cols))) == NULL)
	return (NULL);
      incre = incre + size_cols - 1;
      while (str[incre] == sep)
	incre++;
      line++;
    }
  word[line] = NULL;
  return (word);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**word;
  int	incre_line;
  int	incre_cols;
  int	incre;

  init_value(&incre_line, &incre_cols, &incre);
  if ((word = malloc_char_star(str, sep)) == NULL)
    return (NULL);
  while (str[incre] != '\0')
    {
      word[incre_line][incre_cols] = str[incre];
      if (str[incre] == sep)
	{
	  word[incre_line][incre_cols++] = '\0';
	  if (word[incre_line + 1] != NULL)
	    incre_line++;
	  incre_cols = - 1;
	  while (str[incre] == sep && str[incre + 1] == sep)
	    incre++;
	}
	incre++;
      incre_cols++;
    }
  word[incre_line][incre_cols + 1] = '\0';
  return (word);
}
