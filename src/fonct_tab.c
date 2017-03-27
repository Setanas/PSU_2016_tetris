/*
** fonct_tab.c for Semestre 1 in /home/guillaume1chanut/PSU_2016_tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Tue Feb 21 19:29:33 2017 chanut
** Last update Wed Mar 15 12:48:30 2017 Sébastien TAN
*/

#include "my.h"
#include <stdio.h>

int	level(char *flag, char *key, t_key *key_str)
{
  if ((str_comp(flag, "-l", my_strlen(flag))) == 0)
    {
      if ((check_level(key)) == 84)
	return (84);
      key_str->level = key;
      return (2);
    }
  if ((check_level(&flag[8])) == 84)
    return (84);
  key_str->level = &flag[8];
  return (1);
}

int	left(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->right, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->turn, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->drop, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->quit, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->pause, my_strlen(key))) == 0)
	return (84);
      if ((str_comp(flag, "-kl", my_strlen(flag))) == 0)
	{
	  key_str->left = key;
	  return (2);
	}
    }
  if ((flag[11] == '\0') ||
      (str_comp(&flag[11], key_str->right, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->turn, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->drop, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->quit, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->pause, my_strlen(&flag[11]))) == 0)
    return (84);
  key_str->left = &flag[11];
  return (1);
}

int	rigth(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->left, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->turn, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->drop, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->quit, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->pause, my_strlen(key))) == 0)
	return (84);
      if ((str_comp(flag, "-kr", my_strlen(flag))) == 0)
	{
	  key_str->right = key;
	  return (2);
	}
    }
  if ((flag[12] == '\0') ||
      (str_comp(&flag[12], key_str->left, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->turn, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->drop, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->quit, my_strlen(&flag[12]))) == 0 ||
      (str_comp(&flag[12], key_str->pause, my_strlen(&flag[12]))) == 0)
    return (84);
  key_str->right = &flag[12];
  return (1);
}

int	turn(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->right, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->left, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->drop, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->quit, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->pause, my_strlen(key))) == 0)
	return (84);
      if ((str_comp(flag, "-kt", my_strlen(flag))) == 0)
	{
	  key_str->turn = key;
	  return (2);
	}
    }
  if ((flag[11] == '\0') ||
      (str_comp(&flag[11], key_str->right, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->left, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->drop, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->quit, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->pause, my_strlen(&flag[11]))) == 0)
    return (84);
  key_str->turn = &flag[11];
  return (1);
}

int	drop(char *flag, char *key, t_key *key_str)
{
  if (flag[1] != '-')
    {
      if ((key == NULL) ||
	  (str_comp(key, key_str->right, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->turn, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->left, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->quit, my_strlen(key))) == 0 ||
	  (str_comp(key, key_str->pause, my_strlen(key))) == 0)
	return (84);
      if ((str_comp(flag, "-kd", my_strlen(flag))) == 0)
	{
	  key_str->drop = key;
	  return (2);
	}
    }
  if ((flag[11] == '\0') ||
      (str_comp(&flag[11], key_str->right, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->turn, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->left, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->quit, my_strlen(&flag[11]))) == 0 ||
      (str_comp(&flag[11], key_str->pause, my_strlen(&flag[11]))) == 0)
    return (84);
  key_str->drop = &flag[11];
  return (1);
}
