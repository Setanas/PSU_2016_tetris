/*
** my_put.c for my_put.c in /home/TAN_S/fonction_pratique
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Feb 20 23:04:44 2017 Sébastien TAN
** Last update Mon Mar 13 18:11:09 2017 chanut
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	size;

  size = 0;
  while (str[size] != '\0')
    size++;
  return (size);
}

void	my_putstr(char *str)
{
  int	size;

  size = my_strlen(str);
  write(1, str, size);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nbr)
{
  int	mod;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  if (nbr >= 0)
    {
      if (nbr >= 10)
	{
	  mod = (nbr % 10);
	  nbr = (nbr - mod) / 10;
	  my_putnbr(nbr);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nbr % 10);
    }
}

int	my_put_errno()
{
  my_putstr(strerror(errno));
  my_putchar('\n');
  return (84);
}
