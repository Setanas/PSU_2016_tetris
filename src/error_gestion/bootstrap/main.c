/*
** main.c for error_gestion in /home/TAN_S/PSU_2016_tetris/src/error_gestion/bootstrap
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 21 15:05:41 2017 Sébastien TAN
** Last update Tue Feb 28 11:04:00 2017 Sébastien TAN
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		main(int ac, char **av)
{
  int		fd;
  char		*buf_read;
  struct stat	buf_stat;

  if (ac != 2)
    return (84);
  if ((stat(av[1], &buf_stat)) == - 1)
    return (my_put_errno());
  if ((fd = open(av[1], O_RDONLY)) == - 1)
    return (my_put_errno());
  buf_read = malloc(sizeof(char) * buf_stat.st_size + 1);
  read(fd, buf_read, buf_stat.st_size);
  buf_read[buf_stat.st_size] = '\0';
  free(buf_read);
  close(fd);
  return (0);
}

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
