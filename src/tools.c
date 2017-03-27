/*
** tools.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 19:09:05 2017 chanut
** Last update Sun Mar 19 11:37:22 2017 chanut
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "my.h"

int			mode(int canon)
{
  static struct termios	old;
  static struct termios	new;

  if (canon == 0)
    {
      if ((ioctl(0, TCGETS, &old)) == -1)
	return (84);
      if ((ioctl(0, TCGETS, &new)) == -1)
	return (84);
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      if ((ioctl(0, TCSETS, &new)) == -1)
	return (84);
    }
  else if (canon == 1)
    {
      if ((ioctl(0, TCSETS, &old)) == -1)
	return (84);
    }
  return (0);
}

int			my_putstr_key(char *str)
{
  int			incre;

  incre = 0;
  if (my_strlen(str) == 1 && str[0] == ' ')
    {
      write(1, "(space)", 7);
      return (0);
    }
  while (str[incre] != '\0')
    {
      if (str[incre] == 27)
	  write(1, "^E", 2);
      else
	write(1, &str[incre], 1);
      incre++;
    }
  return (0);
}

int			find_term(char *str, char *compared)
{
  int			i;

  i = 0;
  if (str == NULL)
    return (1);
  while (compared[i] != '\0')
    {
      if (compared[i] != str[i])
	return (1);
      i++;
    }
  return (0);
}

int			size_of_link(t_link *link)
{
  int			incre;

  incre = 1;
  while (link->pos != 0)
    link = link->next;
  link = link->next;
  while (link->pos != 0)
    {
      link = link->next;
      incre++;
    }
  return (incre);
}

int			str_comp(char *data, char *str, int size)
{
  int			i;

  i = 0;
  if (data[0] == '\0' && str[0] == '\0')
    return (0);
  if (data[0] == '\0')
    return (1);
  if (my_strlen(data) != my_strlen(str))
    return (1);
  while (i != size)
    {
      if (data[i] != str[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
