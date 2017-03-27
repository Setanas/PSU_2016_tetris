/*
** debug.c for tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Thu Mar 02 16:49:47 2017 chanut
** Last update Fri Mar 17 23:03:09 2017 Sébastien TAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	disp_tetrimino(t_link *link)
{
  int	incre;

  incre = 0;
  my_putstr(link->name);
  my_putstr(" : ");
  if (link->error == -1)
    my_putstr("Error\n");
  else
    {
      my_putstr("Size ");
      my_putnbr(link->x);
      my_putchar('*');
      my_putnbr(link->y);
      my_putstr(" : Color ");
      my_putnbr(link->color);
      my_putstr(" :\n");
      while (link->tetrimino[incre] != NULL)
	{
	  my_putstr(link->tetrimino[incre++]);
	  my_putchar('\n');
	}
    }
}

void	part_two(t_link *link)
{
  int	size;
  int	incre;

  incre = 1;
  size = size_of_link(link);
  my_putstr("Tetriminos : ");
  my_putnbr(size);
  my_putchar('\n');
  link = link->next;
  while (incre < size)
    {
      my_putstr("Tetriminos : Name ");
      disp_tetrimino(link);
      link = link->next;
      incre++;
    }
    my_putstr("Tetriminos : Name ");
    disp_tetrimino(link);
}

void	part_one_two(t_key key)
{
  my_putstr("Level  : ");
  my_putstr(key.level);
  my_putchar('\n');
  my_putstr("Size  : ");
  my_putstr(key.map_size);
  my_putchar('\n');
}

void	part_one(t_key key)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_putstr("Key Left  : ");
  my_putstr_key(key.left);
  my_putchar('\n');
  my_putstr("Key Right  : ");
  my_putstr_key(key.right);
  my_putchar('\n');
  my_putstr("Key Turn  : ");
  my_putstr_key(key.turn);
  my_putchar('\n');
  my_putstr("Key Drop  : ");
  my_putstr_key(key.drop);
  my_putchar('\n');
  my_putstr("Key Quit  : ");
  my_putstr_key(key.quit);
  my_putchar('\n');
  my_putstr("Key Pause  : ");
  my_putstr_key(key.pause);
  my_putchar('\n');
  my_putstr("Next  : ");
  my_putstr_key(key.hide_next);
  my_putchar('\n');
  part_one_two(key);
}

int	debugg(t_key key, t_link *link)
{
  char	buffer;
  int	reading;

  part_one(key);
  part_two(link);
  my_putstr("Press any key to start Tetris\n");
  if ((mode(0)) == 84)
    return (84);
  reading = 0;
  while (reading == 0)
    {
      reading = 0;
      if ((reading = read(1, &buffer, 1)) == -1)
	return (84);
    }
  if ((mode(1)) == 84)
    return (84);
  if (core(link, &key) == 84)
    return (84);
  return (0);
}
