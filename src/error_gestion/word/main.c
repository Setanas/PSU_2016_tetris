/*
** main.c for main.c in /home/TAN_S/PSU_2016_tetris/src/error_gestion/word
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Wed Mar  1 13:28:00 2017 Sébastien TAN
** Last update Thu Mar  2 17:54:25 2017 Sébastien TAN
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

int	main(int ac, char **av)
{
  char	**word;
  char	string[10];
  int	fd;

  if (ac != 2)
    return (84);
  int	incre;
  fd = open(av[1], O_RDONLY);
  int size;
  size = read(fd, string, 10);
  string[size] = '\0';
  incre = 0;
    word = my_str_to_wordtab(string, '\n');
  while (word[incre] != NULL)
    {
      my_putstr(word[incre]);
      my_putchar('\n');
      incre++;
    }
}
