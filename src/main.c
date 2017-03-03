/*
** main.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 15:05:56 2017 chanut
** Last update Thu Mar 02 19:11:11 2017 chanut
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>

t_key	find_key_2(int argc, char **argv, t_fct tab_p[18], t_key key)
{
  int	i;
  int	e;

  i = 0;
  while (i != 18)
    {
      e = 1;
      while (e != argc)
	{
	  if (str_comp(tab_p[i].arg, argv[e], my_strlen(tab_p[i].arg)) == 0)
	    {
	      key = tab_p[i].function(argv[e + 1], key);
	    }
	  e = e + 1;
	}
      i = i + 1;
    }
  return (key);
}

t_key	find_key(int argc, char **argv, t_key key)
{
  t_fct	tab_p[18] = 	{{&level, "-l"},
			{&left, "-kl"},
			{&left, "--key-left="},
			{&rigth, "-kr"},
			{&rigth, "--key-rigth="},
			{&top, "-kt"},
			{&top, "--key-top="},
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
  key = find_key_2(argc, argv, tab_p, key);
  return (key);
}

t_key	fill_key()
{
  t_key	key;

  key.level = "1";
  key.right = "\\e[C";
  key.left = "\\e[D";
  key.top = "\\e[A";
  key.drop = "\\e[B";
  key.quit = "Q";
  key.pause = " ";
  key.map_size = "20*10";
  key.hide_next = "Yes";
  key.debug = "0";

  return (key);
}

void	man()
{
  int	fd;
  char	*buffer;

  fd = open("./src/man", O_RDONLY);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      my_putstr(buffer);
      my_putchar('\n');
    }
}

int	main(int argc, char **argv)
{
  t_key	key;

  if (error(argc, argv) == 84)
   return (84);
  if (str_comp(argv[1], "-h", my_strlen(argv[1])) == 0 ||
      str_comp(argv[1], "--help", my_strlen(argv[1])) == 0)
    man();
  key = fill_key();
  key = find_key(argc, argv, key);
  if (key.debug[0] == '1')
    debugg(key);
  return (0);
}
