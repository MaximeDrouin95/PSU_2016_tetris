/*
** display.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Mon Feb 27 13:00:34 2017 Maxime BLANCHARD
** Last update Sun Mar 19 15:52:19 2017 Maxime BLANCHARD
*/

#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	print_resize(void)
{
  while (LINES < (20 + g_tetris.row) ||
	 COLS < (55 + g_tetris.col) + (g_tetris.col * 2))
    {
      clear();
      move((LINES / 2), (COLS / 2) - (28 / 2));
      printw("Enlarge the terminal to play");
      refresh();
      move(0, 0);
      getch();
    }
}

int	put_int(t_board *obj, int x, int y, int number)
{
  int	var;

  var = number;
  clear_line(obj, y);
  if (var == 0)
    {
      obj->tab_score[y][x] = '0';
      return (0);
    }
  while (var != 0)
    {
      obj->tab_score[y][x] = var % 10 + 48;
      var = var / 10;
      x = x - 1;
    }
  return (0);
}

int	clear_line(t_board *obj, int y)
{
  int	x;

  x = 0;
  while (obj->tab_score[y][x] != 0)
    {
      if (obj->tab_score[y][x] >= '0'
	  && obj->tab_score[y][x] <= '9')
	obj->tab_score[y][x] = ' ';
      x = x + 1;
    }
  return (0);
}

int     display(t_board *obj, t_llist next)
{
  clear();
  my_showboard(obj->board, obj->board_color);
  my_showlogo(obj->logo, obj->logo_color, (COLS - 35) / 2 - 17,
	      (LINES - g_tetris.row + 2) / 2 - 8);
  if (g_tetris.without_next == 0)
    {
      my_showxy(obj->tab_next, 1, (COLS - g_tetris.col + 4) /
		2 - g_tetris.col + 4 + 2 * (g_tetris.col),
		(LINES - g_tetris.row + 2) / 2);
      my_shownext(next->piece, next->color,
		  (COLS - g_tetris.col + 4) / 2 - g_tetris.col + 4
		  + 2 * (g_tetris.col) + 8 - ((count_max_col(next->piece) * 2) / 2),
		  (LINES - g_tetris.row + 2) / 2 + 4 - (count_line(next->piece) / 2));
    }
  my_showxy(obj->tab_score, 1, (COLS - g_tetris.col + 4) / 2 - g_tetris.col + 4
	    - 26, (LINES - g_tetris.row + 2) / 2 + g_tetris.row - 7);
  put_int(obj, 20, 1, g_tetris.high_score);
  put_int(obj, 20, 2, g_tetris.points);
  put_int(obj, 20, 4, g_tetris.score_line);
  put_int(obj, 20, 5, g_tetris.level);
  put_int(obj, 20, 6, g_tetris.timer + time(NULL) - g_tetris.pause_time);
  refresh();
  return (0);
}
