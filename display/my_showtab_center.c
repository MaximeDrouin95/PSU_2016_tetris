/*
** my_showtab_center.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Mon Feb 27 12:17:00 2017 Maxime BLANCHARD
** Last update Wed Mar 15 11:02:14 2017 Maxime BLANCHARD
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void    my_showboard(char **board, char **board_color)
{
  int   i;
  int	j;

  i = 0;
  while (board[i] != NULL)
    {
      move((LINES - (g_tetris.row + 2)) / 2 + i,
	   (COLS - (g_tetris.col + 4)) / 2 - g_tetris.col + 4);
      j = 0;
      while (board[i][j] != 0)
	{
	  if (board[i][j] != ' ')
	    {
	      addch(' ' | A_REVERSE | COLOR_PAIR(board_color[i][j] - 48));
	      addch(' ' | A_REVERSE | COLOR_PAIR(board_color[i][j] - 48));
	    }
	  else
	    {
	      addch(' ');
	      addch(' ');
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

void    my_showlogo(char **tab, char **tab_color, int x, int y)
{
  int   i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      move(y + i, x);
      j = 0;
      while (tab[i][j] != 0)
	{
	  if (tab[i][j] != ' ')
	    {
	      addch(' ' | A_REVERSE | COLOR_PAIR(tab_color[i][j] - 48));
	      addch(' ' | A_REVERSE | COLOR_PAIR(tab_color[i][j] - 48));
	    }
	  else
	    {
	      addch(' ');
	      addch(' ');
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

void    my_shownext(char **tab, int color, int x, int y)
{
  int   i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      move(y + i, x);
      j = 0;
      while (tab[i][j] != 0)
	{
	  if (tab[i][j] != ' ')
	    {
	      addch(' ' | A_REVERSE | COLOR_PAIR(color - 48));
	      addch(' ' | A_REVERSE | COLOR_PAIR(color - 48));
	    }
	  else
	    {
	      addch(' ');
	      addch(' ');
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

void    my_showxy(char **tab, int color, int x, int y)
{
  int   i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      move(y + i, x);
      j = 0;
      while (tab[i][j] != 0)
	{
	  if (tab[i][j] != ' ' && tab[i][j] != ':' &&
	      (tab[i][j] < 'A' || tab[i][j] > 'Z')
	      && (tab[i][j] < '0' || tab[i][j] > '9'))
	    addch(' ' | A_REVERSE | COLOR_PAIR(color));
	  else
	    addch(tab[i][j] | COLOR_PAIR(color));
	  j = j + 1;
	}
      i = i + 1;
    }
}
