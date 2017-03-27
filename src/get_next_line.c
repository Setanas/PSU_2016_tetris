/*
** get_next_line.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Mar 17 01:12:59 2017 Sébastien TAN
** Last update Fri Mar 17 01:13:05 2017 Sébastien TAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char			*gain_some_line(char *retour)
{
  free (retour);
  return (NULL);
}

char			*reallocation(char *retour, t_static *st, int a, int fd)
{
  int			incre;
  char			*stock;

  incre = 0;
  retour[a] = st->buffer[st->i];
  st->i = 0;
  st->size = read(fd, st->buffer, READ_SIZE);
  if ((stock = malloc(sizeof(char) * (st->size + a + 2))) == NULL)
    return (NULL);
  while (incre < a)
    {
      stock[incre] = retour[incre];
      incre++;
    }
  free(retour);
  stock[incre] = 0;
  return (stock);
}

char			colgate_2_en_1(t_static *st, int *a, int what_to_do)
{
  st->i = st->i + 1;
  if (what_to_do == 1)
    {
      *a = *a + 1;
      return (st->buffer[st->i - 1]);
    }
  return ('\0');
}

int			first_read(char *buffer, char **retour, int *i, int fd)
{
  int			size;

  size = read(fd, buffer, READ_SIZE);
  if ((*retour = malloc(sizeof(char) * size + 1)) == NULL)
    return (-1);
  *i = 0;
  return (size);
}

char			*get_next_line(const int fd)
{
  static t_static	st = {{0}, 0, 0};
  char			*retour;
  int			a;

  a = 0;
  if (st.buffer[0] == 0 || st.i == READ_SIZE)
    st.size = first_read(st.buffer, &retour, &st.i, fd);
  else
    if ((st.size == - 1) ||
	(retour = malloc(sizeof(char) * st.size - st.i + 2)) == NULL)
      return (NULL);
  while (st.buffer[st.i] != '\n')
    {
      retour[a] = colgate_2_en_1(&st, &a, 1);
      if (st.i == st.size && st.buffer[st.i] != '\n')
	if ((retour = reallocation(retour, &st, a, fd)) == NULL)
	  return (NULL);
      (st.size == 0) ? st.buffer[st.i] = '\0' : 0;
      if (st.i >= st.size)
	return (gain_some_line(retour));
    }
  retour[a] = colgate_2_en_1(&st, &a, 3);
  if (st.size <= 0)
    return (gain_some_line(retour));
  return (retour);
}
