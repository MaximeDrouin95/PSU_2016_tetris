/*
** tabception.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Tue Feb 28 17:02:12 2017 Maxime BLANCHARD
** Last update Fri Mar  3 15:36:27 2017 Maxime BLANCHARD
*/

#include "my.h"

int	tabception(t_board *boards, t_llist tetrimino, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < count_line(tetrimino->piece))
  {
    while (tetrimino->piece[i][j] != '\0')
      {
	if ((*boards).board[y + i][x + j] == ' ')
	  {
	    (*boards).board[y + i][x + j] = tetrimino->piece[i][j];
	    (*boards).board_color[y + i][x + j] = tetrimino->color;
	  }
	j = j + 1;
      }
    j = 0;
    i = i + 1;
  }
}

int	tabremover(t_board *boards, t_llist tetrimino, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < count_line(tetrimino->piece))
  {
    while (tetrimino->piece[i][j] != '\0')
      {
	if (tetrimino->piece[i][j] == '*')
	  {
	    (*boards).board[y + i][x + j] = ' ';
	    (*boards).board_color[y + i][x + j] = '1';
	  }
	j = j + 1;
      }
    j = 0;
    i = i + 1;
  }
}
