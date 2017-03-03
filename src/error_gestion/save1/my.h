/*
** my.h for my.h in /home/TAN_S/fonction pratique
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Nov 11 12:11:05 2016 Sébastien TAN
** Last update Wed Mar 01 13:18:33 2017 Sébastien TAN
*/

#ifndef MY_H_
# define MY_H_

#include <dirent.h>

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

int	open_and_check(char *name);
char	*new_name(char *name, char *add);

int	check_first_line(char **line);
int	check_the_tetrimino(char *buf_read);
void	init_value(int *incre, int *nice_width, int *incre_cols);
int	free_wordtab(char **word);
int	free_both_ret_less_1(char **map, char **line);
#endif /* !MY_H_ */
