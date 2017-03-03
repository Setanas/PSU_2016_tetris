/*
** open_and_check_2.c for tetris in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Mar 02 21:15:19 2017 Sébastien TAN
** Last update Thu Mar 02 22:16:51 2017 Sébastien TAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	open_and_check_2(t_link *maillon, struct stat buf_stat, int fd)
{
  char	*buf_read;

  if ((buf_read = malloc(sizeof(char) * buf_stat.st_size + 1)) == NULL)
    return (84);
  if ((read(fd, buf_read, buf_stat.st_size)) == -1)
    return (my_put_errno());
  buf_read[buf_stat.st_size - 1] = '\0';
  if ((check_the_tetrimino(buf_read, maillon)) == 84)
    return (84);
  free(buf_read);
  return (0);
}
