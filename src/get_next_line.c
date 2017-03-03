/*
** get_next_line.c for CPE_2017_getnextline in /home/rault_g/travail/CPE/CPE_2017_getnextline/src
**
** Made by Guillaume RAULT
** Login   <rault_g@epitech.net>
**
** Started on  Mon Jan 02 16:26:52 2017 Guillaume RAULT
** Last update Sun Feb 19 14:54:53 2017 Guillaume RAULT
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		*my_realloc(char *array, int i)
{
  char		*str2;
  int		t;

  t = 0;
  str2 = malloc(sizeof(char) * i + 1);
  if (str2 == NULL)
    return (NULL);
  while (array[t] != '\0')
    {
      str2[t] = array[t];
      t++;
    }
  free (array);
  return (str2);
}

char	*reduce_size(char *str, int i, int *pointeur)
{
  str[i] = '\0';
  str = my_realloc(str, i + READ_SIZE);
  *pointeur = 0;
  return (str);
}

char	*norme(char *str, int i, int *a)
{
  str[i] = '\0';
  *a = *a - 1;
  return (str);
}

char		*get_next_line(const int fd)
{
  static int	pointeur = 0;
  static char	buffer[READ_SIZE];
  static int	a = 0;
  char		*str;
  int		i;

  i = 0;
  if ((str = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (a == 0 && (a = read(fd, buffer, READ_SIZE)))
      pointeur = 0;
  if (a == -1 || a == 0)
    {
      a = 0;
      return (NULL);
    }
  while (buffer[pointeur] != '\n' && buffer[pointeur] != '\0')
    {
      str[i++] = buffer[pointeur++];
      if (--a == 0 && (a = read(fd, buffer, READ_SIZE)))
	str = reduce_size(str, i, &pointeur);
    }
  str = norme(str, i, &a);
  pointeur++;
  return (str);
}
