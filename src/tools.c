/*
** tools.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 19:09:05 2017 chanut
** Last update Thu Mar 02 19:14:25 2017 chanut
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}

int	str_comp(char *data, char *str, int size)
{
  int	i;

  i = 0;
  while (i != size)
    {
      if (my_strlen(data) != my_strlen(str))
	return (1);
      if (data[i] != str[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
