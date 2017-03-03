/*
** my.h for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris/PSU_2016_tetris/include
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 19:01:08 2017 chanut
** Last update Thu Mar 02 19:25:42 2017 chanut
*/

#ifndef s_fct
# define s_glob

typedef struct s_key
{
  char	*level;
  char	*left;
  char	*right;
  char	*top;
  char	*drop;
  char	*quit;
  char	*pause;
  char	*map_size;
  char	*hide_next;
  char	*debug;
}		t_key;

typedef struct s_fct
{
  t_key	(*function) (char *key, t_key key_strt);
  char	*arg;
}		t_fct;

#endif /* !s_glob */

#ifndef MY_H_
# define MY_H_

char	*get_next_line(const int fd);
void	my_putchar(char c);
void	my_putstr(char *str);
int	error(int argc, char **argv);
int	my_strlen(char *str);
t_key	level(char *key, t_key key_str);
t_key	left(char *key, t_key key_str);
t_key	rigth(char *key, t_key key_str);
t_key	top(char *key, t_key key_str);
t_key	drop(char *key, t_key key_str);
t_key	quit(char *key, t_key key_str);
t_key	pausee(char *key, t_key key_str);
t_key	map_size(char *key, t_key key_str);
int	str_comp(char *data, char *str, int size);
t_key	hide_next(char *key, t_key key_str);
t_key	debug(char *key, t_key key_str);
void	debugg(t_key key);

#endif /* MY_H_ */

# ifndef	READ_SIZE
#  define	READ_SIZE 10
# endif /* !READ_SIZE */
