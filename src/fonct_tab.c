/*
** fonct_tab.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Tue Feb 21 19:29:33 2017 chanut
** Last update Thu Mar 02 19:12:12 2017 chanut
*/

#include "my.h"
#include <stdio.h>

t_key	level(char *key, t_key key_str)
{
  key_str.level = key;
  return (key_str);
}

t_key	left(char *key, t_key key_str)
{
  key_str.left = key;
  return (key_str);
}

t_key	rigth(char *key, t_key key_str)
{
  key_str.right = key;
  return (key_str);
}

t_key	top(char *key, t_key key_str)
{
  key_str.top = key;
  return (key_str);
}

t_key	drop(char *key, t_key key_str)
{
  key_str.drop = key;
  return (key_str);
}
