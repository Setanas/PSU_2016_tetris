/*
** start_game.c for tetris in /home/TAN_S/PSU_2016_tetris/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Sat Mar 11 20:24:47 2017 Sébastien TAN
** Last update Fri Mar 17 23:02:24 2017 Sébastien TAN
*/

#include <unistd.h>
#include <ncurses.h>
#include <term.h>
#include <stdlib.h>
#include "my.h"

int		flag_compare(char *flag, char *argv)
{
  int		i;

  i = 0;
  if ((str_comp(flag, argv, my_strlen(flag))) == 0)
    return (0);
  if (flag[1] != '-')
    return (1);
  while (flag[i] != '=')
    {
      if (flag[i] != argv[i])
	return (1);
      i++;
    }
  return (0);
}

int		find_key_2(int argc, char **argv, t_fct tab_p[18], t_key *key)
{
  int		i;
  int		e;

  i = 0;
  e = 1;
  while (e < argc)
    {
      while (i < 19 &&
	     ((flag_compare(tab_p[i].arg, argv[e])) != 0))
	i++;
      if (i > 18)
	return (84);
      if ((i = tab_p[i].function(argv[e], argv[e + 1], key)) == 84)
	return (84);
      e = e + i;
      i = 0;
    }
  return (0);
}

int		find_key(int argc, char **argv, t_key *key)
{
  int		retour;

  t_fct		tab_p[19] = 	{{&level, "--level="},
				{&level, "-l"},
				{&left, "-kl"},
				{&left, "--key-left="},
				{&rigth, "-kr"},
				{&rigth, "--key-right="},
				{&turn, "-kt"},
				{&turn, "--key-turn="},
				{&drop, "-kd"},
				{&drop, "--key-drop="},
				{&quit, "-kq"},
				{&quit, "--key-quit="},
				{&pausee, "-kp"},
				{&pausee, "--key-pause="},
				{&map_size, "--map-size="},
				{&hide_next, "-w"},
				{&hide_next, "--without-next="},
				{&debug, "-d"},
				{&debug, "--debug"}};
  retour = find_key_2(argc, argv, tab_p, key);
  return (retour);
}

int		fill_key(t_key *key, char **env)
{
  int		i;
  int		error;

  i = 0;
  while ((find_term(env[i], "TERM=") != 0) && (env[i] != NULL))
    i++;
  if (env[i] == NULL)
    return (84);
  if ((setupterm(&env[i][5], 1, &error)) == ERR)
    return (84);
  key->level = "1";
  if ((key->right = tigetstr("kcuf1")) == NULL)
    return (84);
  if ((key->left = tigetstr("kcub1")) == NULL)
    return (84);
  if ((key->turn = tigetstr("kcuu1")) == NULL)
    return (84);
  if ((key->drop = tigetstr("kcud1")) == NULL)
    return (84);
  key->quit = "q";
  key->pause = " ";
  key->map_size = "20*10";
  key->hide_next = "Yes";
  key->debug = "0";
  return (0);
}

int		start_game(char **argv, t_link *link, t_key key, int argc)
{
  if ((find_key(argc, argv, &key)) == 84)
    {
      if ((chdir("..")) == 84)
	return (84);
      man(argv[0]);
      return (84);
    }
  else if (key.debug[0] == '1')
    {
      if ((debugg(key, link)) == 84)
	return (84);
    }
  else
    {
      if ((core(link, &key)) == 84)
	return (84);
    }
  return (0);
}
