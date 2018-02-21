/*
** check_for_fall.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris/6
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Wed Mar  1 13:37:02 2017 Maxime BLANCHARD
** Last update Fri Mar  3 15:39:10 2017 Maxime BLANCHARD
*/

#include "my.h"

int	check_for_fall(char **board, t_llist tetrimino, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < count_line(tetrimino->piece))
    {
      while (tetrimino->piece[i][j] != '\0')
	{
	  if (tetrimino->piece[i][j] == '*' && board[y + i][x + j] != ' ')
	    return (1);
	  else
	    j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (0);
}
