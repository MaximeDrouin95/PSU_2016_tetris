/*
** is_line_full.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris/7
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Thu Mar  2 12:55:32 2017 Maxime BLANCHARD
** Last update Mon Mar 13 14:03:34 2017 Maxime BLANCHARD
*/

#include "my.h"

int	is_line_full(t_board obj)
{
  int	i;
  int	j;

  i = count_line(obj.board) - 2;
  j = count_max_col(obj.board) - 2;
  while (j > 0)
    {
      if (obj.board[i][j] != ' ')
	j = j - 1;
      else
	{
	  i = i - 1;
	  j = count_max_col(obj.board) - 1;
	}
      if (i == 0)
	return (0);
    }
  return (i);
}

int	remove_line(t_board *obj)
{
  int	i;
  int	j;

  if ((i = is_line_full((*obj))) == 0)
    return (0);
  j = 1;
  while (i > 1)
    {
      obj->board[i] = my_strdup(obj->board[i - 1]);
      obj->board_color[i] = my_strdup(obj->board_color[i - 1]);
      i = i - 1;
    }
  j = j - 1;
  while (j > 0)
    {
      obj->board[1][j] = ' ';
      obj->board_color[1][j] = '0';
      j = j - 1;
    }
  return (1);
}
