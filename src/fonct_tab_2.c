/*
** fonct_tab_2.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Thu Mar 02 19:19:21 2017 chanut
** Last update Thu Mar 02 19:28:05 2017 chanut
*/

#include "my.h"
#include <stdio.h>

t_key	quit(char *key, t_key key_str)
{
  key_str.quit = key;
  return (key_str);
}

t_key	pausee(char *key, t_key key_str)
{
  key_str.pause = key;
  return (key_str);
}

t_key	map_size(char *key, t_key key_str)
{
  key_str.map_size = key;
  return (key_str);
}

t_key	hide_next(char *key, t_key key_str)
{
  key_str.hide_next = "No";
  return (key_str);
}

t_key	debug(char *key, t_key key_str)
{
  key_str.debug = "1";
  return (key_str);
}
