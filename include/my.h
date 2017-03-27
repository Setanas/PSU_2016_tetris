/*
** my.h for PSU_2016_tetris in /home/TAN_S/PSU_2016_tetris/include
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 19:01:08 2017 chanut
** Last update Sun Mar 19 17:34:27 2017 chanut
*/

# ifndef	READ_SIZE
#  define	READ_SIZE 10
# endif /* !READ_SIZE */

#ifndef s_fct
# define s_glob

typedef struct s_key
{
  char			*level;
  char			*left;
  char			*right;
  char			*turn;
  char			*drop;
  char			*quit;
  char			*pause;
  char			*map_size;
  char			*hide_next;
  char			*debug;
}			t_key;

typedef struct		s_fct
{
  int			(*function)(char *flag, char *key, t_key *key_strt);
  char			*arg;
}			t_fct;

#endif /* !s_glob */

#ifndef MY_H_
# define MY_H_

#include <dirent.h>
#include <sys/stat.h>

/*
** my_put.c
*/
void			my_putchar(char);
void			my_putstr(char *);
void			my_putnbr(int);
int			my_strlen(char *);
/*
** my_str_to_wordtab
*/

typedef struct		s_incre
{
int			i;
int			l;
int			c;
}			t_incre;

char			**my_str_to_wordtab(char *, char);
int			nbr_word(char *, char);
int			nb_cl(char *, char);
int			while_wordtab(char **, char *, char, t_incre *);

/*
** my_getnbr
*/
int			my_getnbr(char *);
int			un(int, char *, char *);
int			deux(int, int, char *, char *);
int			trois(int , char *);

/*
** error_gestion.c
*/
struct dirent		**put_in_direct(DIR *);
int			my_put_errno();
int			size_of_read();
struct dirent		**put_in_direct_2(DIR *, int);
struct dirent		**closedir_and_return(DIR *);

typedef struct		s_link
{
char			*name;
int			error;
char			**tetrimino;
int			x;
int			y;
int			color;
int			pos;
struct s_link		*next;
}			t_link;

/*
** check
*/
int			check_first_line(char **);
int			check_the_tetrimino(char *, t_link *);
int			nice_width_or_not(char *, int *, int, int);
int			check_other_line(char **, int , char **);
void			init_value(int *, int *, int *);

/*
**call_the_error.c
*/
t_link			*call_open_and_check(struct dirent **, int, t_link *);
int			open_and_check(char *, t_link **, int);
int			open_and_check_2(t_link *, struct stat, int);
int			check_name(char *);
int			put_in_link(t_link **);

/*
**free_func.c
*/
char			*free_one_line(char *str);
int			free_wordtab(char **);
int			free_both_ret_less_1(char **, char **);
int			free_link(t_link *);
int			free_scandir(struct dirent **, int);

/*
** fill_linked_list
*/
int			put_name_and_error(t_link *, char *, int);
int			fill_maillon(char **, char **, t_link *, int);
int			fill_map(char **, t_link *, int);
int			my_strlen_map(char *);

/*
** main.c
*/
int			man(char *);
int			start_game(char **, t_link *, t_key, int);
int			fill_key_2(int, char **, t_fct *, t_key *);
int			find_key(int , char **, t_key *);

/*
** start_game.c
*/
int			fill_key(t_key *, char **);

/*
** debug.c
*/
int			debugg(t_key, t_link *);
void			part_one(t_key);
void			part_one_two(t_key);
void			part_two(t_link *);
void			disp_tetrimino(t_link *);

/* error.c */
int			error(int, char **);

/*
** fonc_tab.c
*/
int			level(char *, char *, t_key *);
int			left(char *, char *, t_key *);
int			rigth(char *, char *, t_key *);
int			turn(char *, char *, t_key *);
int			drop(char *, char *, t_key *);

/*
** fonct_tab_2
*/
int			quit(char *, char *, t_key *);
int			pausee(char *, char *, t_key *);
int			map_size(char *, char *, t_key *);
int			hide_next(char *, char *, t_key *);
int			debug(char *, char *, t_key *);

/*
** fonct_tab_3
*/
int			check_level(char *key);
int			map_size_next(t_key *key_str, char *flag);

/*
** tools.c
*/
int			mode(int canon);
int			my_putstr_key(char *str);
int			find_term(char *str, char *compared);
int			str_comp(char *, char *, int);
int			size_of_link(t_link *);

/*
** tools_2.c
*/
int			my_memset(char *, int);
int			put_your_score(int);
int			my_printw_key(char *, char *);
int			too_big_tetr(t_link *, t_key *);

/*
** tools_3.c
*/
void			init_use(int *);
int			norme_move_turn(char *size_1, int *i);
int			init_every_color();
int			print_color_tetrimino(int color);
int			is_nbr(int nb);
/*
** get_next_line.c
*/
typedef struct          s_static
{
  char          	buffer[READ_SIZE];
  int           	i;
  int           	size;
}                       t_static;
char			*get_next_line(const int);

/*
** map.c
*/
int			core();
char			**core_tetrimino(t_link *, t_key *, char **, int *);
char			**tetrimino_down(char **, int *, int);
void			check_size(int, int);
int			check_pos_on_map(int *, char **, int);
int			check_nb_tetromino(t_link *);
int			*get_position(t_link *, int);
int			is(int, int, int *);
void			my_put_tab(char **, int, int);

/*
** key_func.c
*/
typedef struct		s_touch
{
  char			**(*touch)(char **, int *, t_key *key);
  char			*key;
}			t_touch;

/*
** which_touch.c
*/
int			which_touch(char **, t_key *key, int *);
void			init_keytouch(t_touch *, t_key *);

/*
** Score et défaites
*/
int			is_defeat(char **map, int y);
char			**is_scoring(char **map, int x_y[3]);
char			**put_score(char **map, int x, int score);

/*
**
*/
char			**place_uid(char **map, int x, int y, t_key *key);
int			my_strlen(char *str);

/*
** mov_tetri.c
*/
void			check_size(int, int);
int			is(int, int, int *);
char			**move_left(char **, int *, t_key *key);
char			**move_right(char **, int *, t_key *key);
char			**move_turn(char **, int *, t_key *key);

/*
** move_tetri_2.c
*/
char			**move_drop(char **, int *, t_key *key);
char			**move_quit(char **, int *, t_key *key);
char			**move_pause(char **, int *, t_key *key);
int			check_move_left(char **map, int *coordonees);
int			check_move_right(char **map, int *coordonees);
int			switch_position(int *coordonees, int y);
void			get_biggest(int *coordonees, int y, int x_y_max[2]);
void			print_tetrimino(t_key *key);
#endif /* MY_H_ */

# ifndef		READ_SIZE
#  define		READ_SIZE 10
# endif /* !READ_SIZE */
