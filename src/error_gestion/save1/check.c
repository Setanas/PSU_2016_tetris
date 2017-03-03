/*
** check.c for tetris in /home/TAN_S/PSU_2016_tetris/src/error_gestion/bootstrap
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Feb 27 21:20:15 2017 Sébastien TAN
** Last update Thu Mar  2 16:29:34 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

int	check_first_line(char **line)
{
  int	incre_line;
  int	incre_cols;

  incre_line = 0;
  incre_cols = 0;
  while (line[incre_line] != NULL)
    {
      while (line[incre_line][incre_cols] != '\0')
	{
	  if (line[incre_line][incre_cols] < 48 ||
	      line[incre_line][incre_cols] > 57)
	    return (- 1);
	  incre_cols++;
	}
      incre_cols = 0;
      incre_line++;
    }
  if (incre_line != 3)
    return (- 1);
  if (line[2][0] < 49 || line[2][0] > 55)
    return (- 1);
  return (0);
}

int	check_other_line(char **map, int width, char **first_line)
{
  int	height;
  int	incre;
  int	incre_cols;
  int	nice_width;

  init_value(&incre, &nice_width, &incre_cols);
  height = my_getnbr(first_line[1]);
  while (map[incre] != NULL)
    {
      while (map[incre][incre_cols] != '\0')
	{
	  if (map[incre][incre_cols] != ' ' &&
	      map[incre][incre_cols] != '*')
	    return (- 1);
	  incre_cols++;
	}
      if (incre_cols == width)
	nice_width = 1;
      incre_cols = 0;
      incre++;
    }
  if (incre != height || nice_width != 1)
    return (- 1);
  return (0);
}

int	check_the_tetrimino(char *buf_read)
{
  char	**map;
  char	**first_line;
  int	ret;
  //put_chained_list_here;

  if ((map = my_str_to_wordtab(buf_read, '\n')) == NULL)
    return (84);
  if ((first_line = my_str_to_wordtab(map[0], ' ')) == NULL)
    return (free_wordtab(map));
  ret = check_first_line(first_line);
  if (ret != - 1)
    ret = check_other_line(&map[1], my_getnbr(first_line[0]), first_line);
  free_both_ret_less_1(map, first_line);
  return (0);
}

void	init_value(int *incre, int *nice_width, int *incre_cols)
{
  *incre = 0;
  *nice_width = 0;
  *incre_cols = 0;
}
