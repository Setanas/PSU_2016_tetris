/*
** fonct_tab_2.c for Semestre 1 in /home/guillaume1chanut/PSU_2016_tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Thu Mar 02 19:19:21 2017 chanut
** Last update Fri Mar 17 01:29:10 2017 Sébastien TAN
*/

#include "my.h"
#include <stdio.h>

int	quit(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->right, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->turn, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->drop, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->left, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->pause, my_strlen(key))) == 0)
	return (84);
  if ((str_comp(flag, "-kq", my_strlen(flag))) == 0)
	{
	  key_str->quit = key;
	  return (2);
	}
    }
    if ((flag[11] == '\0') ||
        (str_comp(&flag[11], key_str->right, my_strlen(&flag[11]))) == 0 ||
        (str_comp(&flag[11], key_str->turn, my_strlen(&flag[11]))) == 0 ||
        (str_comp(&flag[11], key_str->drop, my_strlen(&flag[11]))) == 0 ||
        (str_comp(&flag[11], key_str->left, my_strlen(&flag[11]))) == 0 ||
        (str_comp(&flag[11], key_str->pause, my_strlen(&flag[11]))) == 0)
      return (84);
  key_str->quit = &flag[11];
  return (1);
}

int	pausee(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->right, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->turn, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->drop, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->quit, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->left, my_strlen(key))) == 0)
	return (84);
      if ((str_comp(flag, "-kp", my_strlen(flag))) == 0)
	{
	  key_str->pause = key;
	  return (2);
	}
    }
  if ((flag[12] == '\0') ||
      (str_comp(&flag[12], key_str->right, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->turn, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->drop, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->quit, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->left, my_strlen(&flag[12]))) == 0)
    return (84);
  key_str->pause = &flag[12];
  return (1);
}

int	map_size(char *flag,
		__attribute__((unused)) char *key, t_key *key_str)
{
  int	incre;
  int	coma;

  incre = 11;
  coma = 0;
  if (flag[incre] == '\0')
    return (84);
  while (flag[incre] != '\0')
    {
      if (flag[incre] < 48 && flag[incre] > 57 && flag[incre] != ',')
	return (84);
      if (flag[incre] == ',')
	coma++;
      incre++;
    }
  if (coma != 1)
    return (84);
  if ((map_size_next(key_str, &flag[11])) == 84)
    return (84);
  return (1);
}

int	hide_next(__attribute__((unused)) char *flag,
		  __attribute__((unused)) char *key, t_key *key_str)
{
  key_str->hide_next = "No";
  return (1);
}

int	debug(__attribute__((unused)) char *flag,
	      __attribute__((unused)) char *key, t_key *key_str)
{
  key_str->debug = "1";
  return (1);
}
