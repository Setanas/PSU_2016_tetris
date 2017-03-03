/*
** my.h for my.h in /home/TAN_S/fonction pratique
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Nov 11 12:11:05 2016 Sébastien TAN
** Last update Mon Feb 27 22:36:09 2017 Sébastien TAN
*/

#ifndef MY_H_
# define MY_H_

#include <dirent.h>

void			my_putchar(char c);
void			my_putnbr(int nb);
void			my_putstr(char *str);
int			my_strlen(char *str);
    /*my_str_to_wordtab*/
void			init_value(int *incre_line, int *incre_cols, int *incre);
int			nbr_of_cols(char *str, char sep);
int			nbr_of_line(char *str, char sep);
char			**malloc_char_star(char *str, char sep);
char			**my_str_to_wordtab(char *str, char sep);

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

int	check_first_line(char **line);
int	check_the_tetrimino(char *buf_read);
int	free_wordtab(char **word);
int	free_both_ret_less_1(char **map, char **line);
#endif /* !MY_H_ */
