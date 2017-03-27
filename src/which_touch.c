/*
** which_touch.c for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Mar 16 19:25:58 2017 Sébastien TAN
** Last update Sun Mar 19 23:04:57 2017 Sébastien TAN
*/

#include <ncurses.h>
#include <unistd.h>
#include "my.h"

int		which_touch(char **map, t_key *key, int *coordonee)
{
  char		touch[10];
  t_touch	keytouch[6];
  int		i;

  i = 0;
  init_keytouch(keytouch, key);
  my_memset(touch, 10);
  if ((read(0, touch, 10)) == -1)
    return (84);
  while (i < 6 &&
	 (str_comp(touch, keytouch[i].key, my_strlen(touch))) != 0)
    i++;
  if (i < 5)
    {
      if ((keytouch[i].touch(map, coordonee, key)) == NULL)
	return (3);
    }
  return (0);
}

void		init_keytouch(t_touch *keytouch, t_key *key)
{
  keytouch[0].touch = &move_left;
  keytouch[0].key = key->left;
  keytouch[1].touch = &move_right;
  keytouch[1].key = key->right;
  keytouch[2].touch = &move_drop;
  keytouch[2].key = key->drop;
  keytouch[3].touch = &move_quit;
  keytouch[3].key = key->quit;
  keytouch[4].touch = &move_pause;
  keytouch[4].key = key->pause;
}
