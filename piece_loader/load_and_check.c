/*
** load_and_check.c for tetris in /home/alkoleek/TEST_AREA/load_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 15:11:40 2017 Maxime DROUIN
** Last update Fri Mar  3 15:37:52 2017 Maxime BLANCHARD
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char	**copy_tetrimino(char **piece, char **file, char **args, int j)
{
  int	i;

  i = 1;
  while (i <= my_getnbr(args[1]))
    {
      if (file[i] == NULL || check_line(file[i], args) != 0)
	return (NULL);
      j = 0;
      if ((piece[i - 1] = malloc(sizeof(char) *
				 (my_getnbr(args[0]) + 1))) == NULL)
	return (NULL);
      while (j < my_getnbr(args[0]))
	{
	  if (file[i][j] == '*' || file[i][j] == ' ')
	    piece[i - 1][j] = file[i][j];
	  else
	    piece[i - 1][j] = ' ';
	  j = j + 1;
	}
      piece[i - 1][j] = 0;
      i = i + 1;
    }
  piece[i - 1] = NULL;
  return (piece);
}

char	**parse_piece(char **file, char **args)
{
  char	**piece;
  int	i;

  i = 0;
  if ((piece = malloc(sizeof(char *) * my_getnbr(args[1]) + 1)) == NULL)
    return (NULL);
  if ((piece = copy_tetrimino(piece, file, args, i)) == NULL)
    return (NULL);
  if (count_tetrimino_col(piece) != my_getnbr(args[0]))
    return (NULL);
  while (piece[i] != 0)
    {
      piece[i][my_getnbr(args[0])] = 0;
      i = i + 1;
    }
  return (piece);
}

t_llist	load_piece_d(t_llist list, char *filename)
{
  char	**file;
  char	**piece;
  char	**args;
  char	**piece_color;

  my_putstr("Tetriminos :  ");
  put_name(filename);
  if ((file = load_map(filename, get_lines(filename))) == NULL)
    return (print_error(list));
  if (check_args((args = parse_args(file[0], ' '))) == 0)
    return (print_error(list));
  if ((piece = parse_piece(file, args)) == NULL)
    return (print_error(list));
  if ((list = add_first(list, piece, args)) == NULL)
    return (print_error(list));
  my_put_args(args);
  my_showtab(piece);
  return (list);
}

t_llist	load_piece(t_llist list, char *filename)
{
  char	**file;
  char	**piece;
  char	**piece_color;
  char	**args;

  if ((file = load_map(filename, get_lines(filename))) == NULL)
    return (list);
  if (check_args((args = parse_args(file[0], ' '))) == 0)
    return (list);
  if ((piece = parse_piece(file, args)) == NULL)
    return (list);
  if ((list = add_first(list, piece, args)) == NULL)
    return (list);
  return (list);
}

t_llist	load_in_llist(t_llist list, int debug)
{
  char	**filename;
  int	i;

  i = 0;
  filename = get_files("tetriminos");
  if (debug == 1)
    print_filenb(filename);
  if (filename == NULL)
    return (NULL);
  while (filename[i] != 0)
    {
      if (debug == 1)
	list = load_piece_d(list, filename[i]);
      else
	list = load_piece(list, filename[i]);
      i = i + 1;
    }
  if (list == NULL)
    {
      my_putstr("Error: No tetriminos\n");
      exit(84);
    }
  return (list);
}
