/*
** do_fall.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Tue Feb 28 15:40:25 2017 Maxime BLANCHARD
** Last update Sat Mar 11 16:40:59 2017 Maxime BLANCHARD
*/

#include <stdlib.h>
#include "my.h"

int	do_fall(t_board *obj, t_llist list)
{
  static t_llist	tetrimino = NULL;

  if (tetrimino == NULL && (tetrimino = list) != NULL)
    {
      if (check_for_fall(obj->board, tetrimino, obj->x, obj->y) == 0)
	tabception(obj, tetrimino, obj->x, obj->y);
      else
	return (1);
    }
  else
    {
      obj->y = obj->y + 1;
      tabremover(obj, tetrimino, obj->x, obj->prev_y);
      if (check_for_fall(obj->board, tetrimino, obj->x, obj->y) == 0)
	tabception(obj, tetrimino, obj->x, obj->y);
      else
	{
	  tabception(obj, tetrimino, obj->x, obj->prev_y);
	  tetrimino = NULL;
	  obj->prev_y = 1;
	  return (2);
	}
      obj->prev_y = obj->y;
    }
  return (0);
}

int	do_move(t_board *obj, t_llist list)
{
  if (obj->x == obj->prev_x)
    return (0);
  tabremover(obj, list, obj->prev_x, obj->y);
  if (check_for_fall(obj->board, list, obj->x, obj->y) == 0)
    tabception(obj, list, obj->x, obj->y);
  else
    {
      tabception(obj, list, obj->prev_x, obj->y);
      obj->x = obj->prev_x;
      return (1);
    }
  obj->prev_x = obj->x;
  return (0);
}

int	do_drop(t_board *obj, t_llist list)
{
  while (1)
    {
      tabremover(obj, list, obj->x, obj->prev_y);
      if (check_for_fall(obj->board, list, obj->x, obj->y) == 0)
	{
	  tabception(obj, list, obj->x, obj->y);
	  obj->prev_y = obj->y;
	  obj->y = obj->y + 1;
	}
      else
	{
	  tabception(obj, list, obj->x, obj->prev_y);
	  obj->y = obj->y - 1;
	  return (2);
	}
    }
  return (0);
}

char	**rotator(char **r_piece, int l, t_llist list)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (i < count_line(list->piece))
    {
      while (j < count_max_col(list->piece))
	{
	  if (list->piece[i][j] == 0)
	    r_piece[k][l] = ' ';
	  else
	    r_piece[k][l] = list->piece[i][j];
	  j = j + 1;
	  k = k + 1;
	}
      i = i + 1;
      j = 0;
      k = 0;
      l = l - 1;
    }
  return (r_piece);
}

int     do_rotate(t_board *obj, t_llist list)
{
  char  **piece;
  char  **r_piece;
  int	l;

  l = count_line(list->piece) - 1;
  if ((r_piece = board_generator(count_max_col(list->piece),
				 count_line(list->piece))) == NULL)
    return (-1);
  r_piece = rotator(r_piece, l , list);
  piece = list->piece;
  tabremover(obj, list, obj->x, obj->y);
  list->piece = r_piece;
  if (check_for_fall(obj->board, list, obj->x, obj->y) == 0)
    tabception(obj, list, obj->x, obj->y);
  else
    {
      list->piece = piece;
      tabception(obj, list, obj->x, obj->y);
    }
  return (0);
}
