/*
** main.c for main. in /home/TAN_S/PSU_2016_tetris/src/error_gestion/scandir
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Mar  2 15:46:24 2017 Sébastien TAN
** Last update Thu Mar 02 16:26:42 2017 Sébastien TAN
*/

#include <dirent.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  struct dirent **name_list;
  int	nbr_dir;
  int	incre;

  if (ac != 2)
    return (84);
  nbr_dir = scandir(av[1], &name_list, NULL, alphasort);
  incre = 0;
  while (incre < nbr_dir)
    {
      printf("%s\n", name_list[incre]->d_name);
      free(name_list[incre]);
      incre++;
    }
  free(name_list);
  return (0);
}
