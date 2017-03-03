/*
** my.h for my.h in /home/TAN_S/fonction pratique
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Nov 11 12:11:05 2016 Sébastien TAN
** Last update Fri Mar 03 13:34:28 2017 Sébastien TAN
*/

#ifndef MY_H_
# define MY_H_

#include <dirent.h>
#include <sys/stat.h>

void			my_putchar(char c);
void			my_putnbr(int nb);
void			my_putstr(char *str);
int			my_strlen(char *str);
    /*my_str_to_wordtab*/

typedef struct	s_incre
{
  int		i;
  int		l;
  int		c;
}		t_incre;
char			**my_str_to_wordtab(char *str, char sep);
int			nbr_word(char *str, char sep);
int			nbr_cols(char *str, char sep);
int			while_wordtab(char **word, char *str, char sep, t_incre *incre);

      /*my_getnbr*/
int			my_getnbr(char *str);
int			un(int l, char *str, char *nb);
int			deux(int j, int l, char *str, char *nb);
int			trois(int o, char *nb);

/* error_gestion.c */
struct dirent	**put_in_direct(DIR *directory);
int		my_put_errno();
int		size_of_read();
struct dirent	**put_in_direct_2(DIR *directory, int size);
struct dirent	**closedir_and_return(DIR *directory);

typedef struct	s_link
{
  char		*name;
  int		error;
  char		**tetrimino;
  int		x;
  int		y;
  int		color;
  int		pos;
  struct s_link	*next;
}		t_link;

int		open_and_check(char *name, t_link **link, int pos);
char	*new_name(char *name, char *add);

int	check_first_line(char **line);
int	check_the_tetrimino(char *buf_read, t_link *maillon);
void	init_value(int *incre, int *nice_width, int *incre_cols);
int	free_wordtab(char **word);
int	free_both_ret_less_1(char **map, char **line);
int	check_name(char *name);
t_link	*call_open_and_check(struct dirent **direct, int nbr_dir, t_link *link);
int		link_malloc(struct dirent **direct, int nbr_dir, t_link **link);
int	put_name_and_error(t_link *maillon, char *name, int error);
int	fill_maillon(char **map, char **first_line, t_link *maillon, int error);
int	fill_map(char **map, t_link *maillon, int size);
int	open_and_check_2(t_link *maillon, struct stat buf_stat, int fd);
#endif /* !MY_H_ */
