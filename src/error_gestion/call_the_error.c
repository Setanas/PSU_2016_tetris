/*
** call_the_error.c for error_gestion in /home/TAN_S/PSU_2016_tetris/src/error_gestion
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Tue Feb 21 15:02:54 2017 Sébastien TAN
** Last update Fri Mar 03 14:05:01 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "my.h"

int		main()
{
  struct dirent	**direct;
  int		nbr_dir;
  t_link	*link;
  t_link	*stock;

  if ((nbr_dir = scandir("./tetriminos", &direct, NULL, alphasort)) == - 1)
    return (my_put_errno());
  if ((chdir("./tetriminos")) == - 1)
    return (my_put_errno());
  // if ((link_malloc(direct, nbr_dir, &link) == 84))
  //   return (84);
  link = NULL;
  if ((link = call_open_and_check(direct, nbr_dir, link)) == NULL)
    return (84);
  int	incre;

  stock = link;
  while (link->next != NULL)
    link = link->next;
  link->next = stock;
  incre = 0;
  link = link->next;
  free_the_link(link);
  return (0);
}

t_link		*call_open_and_check(struct dirent **direct,
				     int nbr_dir, t_link *link)
{
  int		incre;
  int		error_or_not;
  int		pos;

  incre = 0;
  link = NULL;
  pos = 0;
  while (incre < nbr_dir)
    {
      error_or_not = check_name(direct[incre]->d_name);
      if (error_or_not == 84)
	return (NULL);
      if (error_or_not != - 1)
	{
	  if ((open_and_check(direct[incre]->d_name, &link, pos)) == 84)
	    return (NULL);
	  pos++;
	}
      incre++;
    }
  free(direct);
  return (link);
}

int		open_and_check(char *name, t_link **link, int pos)
{
  int		fd;
  struct stat	buf_stat;
  t_link	*maillon;

  if ((maillon = malloc(sizeof(*maillon))) == NULL)
    return (84);
  if ((stat(name, &buf_stat)) == - 1)
    return (my_put_errno());
  if ((put_name_and_error(maillon, name, buf_stat.st_size)) == 84)
    return (84);
  maillon->pos = pos;
  if (buf_stat.st_size == 0)
    return (- 1);
  if ((fd = open(name, O_RDONLY)) == - 1)
    return (my_put_errno());
  if ((open_and_check_2(maillon, buf_stat, fd)) == 84)
    return (84);
  maillon->next = *link;
  *link = maillon;
   close(fd);
  return (0);
}

int		check_name(char *name)
{
  int		size;
  int		size_2;
  char		*checkeur;
  struct stat	buf_stat;

  checkeur = ".tetrimino";
  if ((stat(name, &buf_stat)) == - 1)
    return (my_put_errno());
  if (S_ISREG(buf_stat.st_mode) == 0)
    return (- 1);
  size = my_strlen(checkeur);
  size_2 = my_strlen(name);
  while (size > 0)
    {
      if (checkeur[size] != name[size_2])
	return (- 1);
      size--;
      size_2--;
    }
  return (0);
}

int		link_malloc(struct dirent **direct, int nbr_dir, t_link **link)
{
  int		incre;
  int		nbr_malloc;
  int		error_or_not;
  //t_link	*link;

  incre = 0;
  nbr_malloc = 0;
  while (incre < nbr_dir)
    {
      error_or_not = check_name(direct[incre]->d_name);
      if (error_or_not == 84)
	return (84);
      if (error_or_not != - 1)
	nbr_malloc = nbr_malloc + 1;
      incre++;
    }
  if ((*link = malloc(sizeof(*link) * nbr_malloc)) == NULL)
    return (84);
  return (0);
}
