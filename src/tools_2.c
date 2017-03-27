/*
** tools_2.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Mar 15 19:31:58 2017 Sébastien TAN
** Last update Fri Mar 17 23:13:36 2017 Sébastien TAN
*/

#include <ncurses.h>
#include <unistd.h>
#include "my.h"

void	get_biggest(int *coordonees, int y, int result[2])
{
  int	i;

  result[0] = 0;
  result[1] = 0;
  result[2] = 0;
  i = 1;
  while (coordonees[i] != -1)
    {
      if (coordonees[i] - coordonees[1] > result[0])
	result[0] = coordonees[i] - coordonees[1];
      if (coordonees[i + 1]  - (y / 2 - 1) > result[1])
	result[1] = coordonees[i + 1] - (y / 2 - 1);
      i = i + 2;
    }
   result[0] = result[0] + 1;
}

int	too_big_tetr(t_link *link, t_key *key)
{
  char	**map;
  int	incre;
  int	size;
  int	x_y[2];

  incre = 1;
  size = size_of_link(link);
  link = link->next;
  if ((map = my_str_to_wordtab(key->map_size, '*')) == NULL)
    return (84);
  x_y[1] = my_getnbr(map[0]);
  x_y[0] = my_getnbr(map[1]);
  while (incre < size)
    {
      if (link->error == 0 && (x_y[0] <= link->x || x_y[1] <= link->y ||
	  x_y[1] <= link->x || x_y[0] <= link->y))
	{
	  link->error = -1;
	  free_wordtab(link->tetrimino);
	}
      link = link->next;
      incre++;
    }
  free_wordtab(map);
  return (0);
}

int	my_printw_key(char *str, char *what_he_do)
{
  printw("Press : ");
  if (my_strlen(str) == 1 && str[0] == ' ')
    {
      printw("(space) %s\n", what_he_do);
      return (0);
    }
  else
    printw("%s %s\n", str, what_he_do);
  return (0);
}

int	my_memset(char *str, int size)
{
  int	incre;

  incre = 0;
  while (incre < size)
    {
      str[incre] = '\0';
      incre++;
    }
  return (0);
}

int	put_your_score(int nbr)
{
  write(1, "Your score is : ", 16);
  my_putnbr(nbr);
  my_putchar('\n');
  return (0);
}
