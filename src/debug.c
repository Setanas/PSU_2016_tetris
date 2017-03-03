/*
** debug.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Thu Mar 02 16:49:47 2017 chanut
** Last update Thu Mar 02 19:10:52 2017 chanut
*/

#include "my.h"

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
  my_putstr("*** DEBUG MODE ***");
  my_putchar('\n');
  my_putstr("Key Left  : ");
  my_putstr(key.left);
  my_putchar('\n');
  my_putstr("Key Right  : ");
  my_putstr(key.right);
  my_putchar('\n');
  my_putstr("Key Turn  : ");
  my_putstr(key.top);
  my_putchar('\n');
  my_putstr("Key Drop  : ");
  my_putstr(key.drop);
  my_putchar('\n');
  my_putstr("Key Quit  : ");
  my_putstr(key.quit);
  my_putchar('\n');
  my_putstr("Key Pause  : ");
  my_putstr(key.pause);
  my_putchar('\n');
  my_putstr("Next  : ");
  my_putstr(key.hide_next);
  my_putchar('\n');
  part_one_two(key);
}

void	debugg(t_key key)
{
  part_one(key);
}
