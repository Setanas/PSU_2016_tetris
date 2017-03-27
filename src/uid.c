/*
** uid.c for tetris in /home/guillaume1chanut/PSU_2016_tetris/src
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Thu Mar 16 18:07:01 2017 chanut
** Last update Sun Mar 19 16:47:46 2017 chanut
*/

#include <curses.h>
#include "my.h"

void	print_tetrimino(t_key *key)
{
  printw("*** Commandes ***\n");
  printw("Key Left  : ");
  printw(key->left);
  printw("\n");
  printw("Key Right  : ");
  printw(key->right);
  printw("\n");
  printw("Key Turn  : ");
  printw(key->turn);
  printw("\n");
  printw("Key Drop  : ");
  printw(key->drop);
  printw("\n");
  printw("Key Quit  : ");
  printw(key->quit);
  printw("\n");
  printw("Key Pause  : ");
  printw(key->pause);
  printw("\n");
}

int	nb_div(int nb)
{
  int	div;

  div = 1;
  while (nb > 9)
    {
      nb=nb/10;
      div = div *10;
    }
  return (div);
}

char	**put_score(char **map, int x, int score)
{
  int	diiv;
  int	i;

  i = 0;
  diiv = nb_div(score);
  while (diiv != 0)
    {
      map[1][x + 13 + i] = (score / diiv + 48);
      score = score % diiv;
      diiv = diiv / 10;
      i = i + 1;
    }
  return (map);
}

char	**put_uid(char **map, int use[2], int x, t_key *key)
{
  char	*sc;
  char	*lvl;
  int	u;
  int	j;

  u = -1;
  j = -1;
  lvl = "Level : ";
  sc = "Score : ";
  if (use[0] == 1 && use[1] == x + 5)
    {
      while (u++ != 7)
	map[use[0]][use[1] + u] = sc[u];
      u = - 1;
    }
  else if (use[0] == 2 && use[1] == x + 5)
    {
      while (u++ != 7)
	map[use[0]][use[1] + u] = lvl[u];
      while (j++ != my_strlen(key->level) - 1)
	  map[use[0]][use[1] + u++] = key->level[j];
      u = - 1;
    }
  return (map);
}

char	**place_uid(char **map, int x, int y, t_key *key)
{
  int	use[2];

  use[0] = 0;
  use[1] = 0;
  while (use[0] != y + 1)
    {
      while (use[1]++ != x + 23)
	{
	  map = put_uid(map, use, x, key);
	}
      use[1] = 0;
      use[0] = use[0] + 1;
    }
  return (map);
}
