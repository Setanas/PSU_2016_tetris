/*
** call_the_error.c for error_gestion in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 21 15:02:54 2017 Sébastien TAN
** Last update Wed Mar 01 20:12:54 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "my.h"

int		main()
{
  struct dirent	**direct;
  DIR		*directory;
  int		incre;

  if ((directory = opendir("./tetriminos/")) == NULL)
    return (my_put_errno());
  if ((direct = put_in_direct(directory)) == NULL)
    return (my_put_errno());
  incre = 0;
  while (direct[incre] != NULL)
    {
      my_putstr(direct[incre]->d_name);
      my_putstr("           ");
      my_putnbr(open_and_check(direct[incre]->d_name));
      my_putchar('\n');
      incre++;
    }
  free(direct);
  closedir(directory);
  return (0);
}

int		open_and_check(char *name)
{
  int		fd;
  int		ret;
  char		*buf_read;
  struct stat	buf_stat;

  if ((name = new_name(name, "./tetriminos/")) == NULL)
    return (84);
  if ((stat(name, &buf_stat)) == - 1)
    return (my_put_errno());
  if ((fd = open(name, O_RDONLY)) == - 1)
    return (my_put_errno());
  if ((buf_read = malloc(sizeof(char) * buf_stat.st_size + 1)) == NULL)
    return (84);
  if ((read(fd, buf_read, buf_stat.st_size)) == -1)
    return (my_put_errno());
  buf_read[buf_stat.st_size - 1] = '\0';
  ret = check_the_tetrimino(buf_read);
  free(buf_read);
  close(fd);
  return (ret);
}

char		*new_name(char *name, char *add)
{
  char		*new;
  int		incre_new;
  int		incre;
  int		size;

  size = my_strlen(name) + my_strlen(add);
  if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  incre = 0;
  incre_new = 0;
  while (add[incre_new] != '\0')
    {
      new[incre_new] = add[incre_new];
      incre_new++;
    }
  while (name[incre] != '\0')
    {
      new[incre_new] = name[incre];
      incre_new++;
      incre++;
    }
  new[incre_new] = '\0';
  return (new);
}
