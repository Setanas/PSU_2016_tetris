/*
** error.c for Semestre 1 in /home/guillaume1chanut/Semestre 1/Sys Unix/tetris
**
** Made by chanut
** Login   <guillaume1chanut@epitech.net>
**
** Started on  Mon Feb 20 15:05:52 2017 chanut
** Last update Mon Mar 13 18:04:26 2017 chanut
*/

int	error(int argc, char **argv)
{
  (void) argv;
  if (argc < 2)
    return (-1);
  if (argc > 22)
    return (84);
  return (0);
}
