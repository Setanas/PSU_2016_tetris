/*
** main.c for tetris in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Feb 20 21:21:59 2017 Sébastien TAN
** Last update Wed Mar 01 20:12:33 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include "my.h"

struct dirent		**put_in_direct(DIR *directory)
{
  struct dirent 	**direct;
  int			size;

  errno = 0;
  if ((size = size_of_read()) == - 1)
    return (NULL);
  readdir(directory);
  if (errno != 0)
    return (closedir_and_return(directory));
  readdir(directory);
  if (errno != 0)
    return (closedir_and_return(directory));
  if ((direct = put_in_direct_2(directory, size)) == NULL)
    return (NULL);
  return (direct);
}

struct dirent		**put_in_direct_2(DIR *directory, int size)
{
  struct dirent		**direct;
  int			incre;

  incre = 0;
  direct = NULL;
  if ((direct = malloc(sizeof(*direct) * size)) == NULL)
  return (NULL);
  while (incre < size - 1)
    {
      direct[incre] = readdir(directory);
      incre++;
      if (errno != 0)
	return (closedir_and_return(directory));
    }
  direct[incre] = NULL;
  return (direct);
}

struct dirent		**closedir_and_return(DIR *directory)
{
  closedir(directory);
  return (NULL);
}

int			size_of_read()
{
  DIR			*directory;
  int			size;

  errno = 0;
  size = 0;
  if ((directory = opendir("./tetriminos/")) == NULL)
    return (- 1);
  while (readdir(directory) != NULL)
    size++;
  if (errno != 0)
    {
      closedir(directory);
      return (- 1);
    }
  closedir(directory);
  return (size - 1);
}
