/*
** main.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 15:05:56 2017 chanut
** Last update Fri Mar 17 23:06:32 2017 Sébastien TAN
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "my.h"

int		man(char *binary)
{
  int		fd;
  char		*buffer;

  if ((fd = open("./src/man", O_RDONLY)) == -1)
    return (84);
  my_putstr("Usage:\t");
  my_putstr(binary);
  my_putstr("[options]\n");
  while ((buffer = get_next_line(fd)) != NULL)
    {
      my_putstr(buffer);
      my_putchar('\n');
      free(buffer);
    }
  free(buffer);
  close (fd);
  return (0);
}

int		help_or_not(char **argv, int argc)
{
  int		i;

  i = 1;
  while (i < argc)
    {
      if (str_comp(argv[i], "-h", my_strlen(argv[i])) == 0 ||
		str_comp(argv[i], "--help", my_strlen(argv[i])) == 0)
	{
	  if ((man(argv[0])) == 84)
	    return (84);
	  return (1);
	}
      i++;
    }
  return (0);
}

int		before_start_game(char **argv, char **env, int argc)
{
  t_key		key;
  t_link	*link;

  link = NULL;
  if ((put_in_link(&link) == 84) || (fill_key(&key, env) == 84) ||
      (too_big_tetr(link, &key)) == 84)
    return (84);
  if (argc == 1)
    {
      if (core(link, &key) == 84)
	{
	  free_link(link);
	  return (84);
	}
    }
  else
    if ((start_game(argv, link, key, argc)) == 84)
	{
	  free_link(link);
	  return (84);
	}
  free_link(link);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  int		help;

  srand(time(NULL));
  if (error(argc, argv) == 84)
   return (84);
  if (error(argc, argv) == -1)
    {
      if ((before_start_game(argv, env, argc)) == 84)
	return (84);
      return (0);
    }
  help = help_or_not(argv, argc);
  if (help == 84)
    return (84);
  if (help == 1)
    return (0);
  if ((before_start_game(argv, env, argc)) == 84)
    return (84);
   return (0);
}
