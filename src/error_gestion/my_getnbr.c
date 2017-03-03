/*
** my_getnbr.c for tetris in /home/TAN_S/PSU_2016_tetris/src/error_gestion/bootstrap
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Feb 27 22:47:17 2017 Sébastien TAN
** Last update Mon Feb 27 22:47:43 2017 Sébastien TAN
*/

#include "my.h"

int	un(int l, char *str, char *nb);
int	deux(int j, int l, char *str, char *nb);
int	trois(int o, char *nb);

int	un(int l, char *str, char *nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str[0] <= 58 && str[0] >= 48)
    {
      while (str[i] <= 57 && str[i] >= 48)
	{
	  nb[l] = str[i];
	  l = l + 1;
	  i = i + 1;
	}
    }
  else
    {
      l = deux(j, l, str, nb);
    }
  return (l);
}

int	deux(int j, int l, char *str, char *nb)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (str[i] >= 57 || str[i] <= 48)
    {
      if (str[i] == 45)
	j = j + 1;
      i = i + 1;
      k = i;
      while (str[k] <= 57 && str[k] >= 48)
	{
	  if (j % 2 != 0)
	    {
	      nb[l] = 45;
	      l = l + 1;
	      j = j + 1;
	    }
	  nb[l] = str[k];
	  k = k + 1;
	  l = l + 1;
	}
    }
  return (l);
}

int	trois(int o, char *nb)
{
  int	j;
  int	res;

  j = 0;
  res = 0;
  while (nb[j] != '\0' && j < 10)
    {
      if (nb[j] == 45)
	{
	  j = j + 1;
	}
      res = res * o + (nb[j] - 48);
      j = j + 1;
    }
  if (nb[0] == 45)
    {
      res = -res;
    }
  return (res);
}

int	my_getnbr(char *str)
{
  int	m;
  int	l;
  int	o;
  int	n;
  char	nb[26];

  m = my_strlen(str);
  l = 0;
  if (m >= 26)
    {
      nb[0] = 48;
    }
  else
    {
      l = un(l, str, nb);
    }
  nb[l] = '\0';
  o = 10;
  n = trois(o, nb);
  return (n);
}
