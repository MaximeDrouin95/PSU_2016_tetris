/*
** quit_game.c for tetris in /home/alkoleek/PSU_2016_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Mar 14 14:19:06 2017 Maxime DROUIN
** Last update Tue Mar 14 14:19:06 2017 Maxime DROUIN
*/

#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

int	quit_game(int i)
{
  set_read(1);
  endwin();
  exit(i);
}

int	wait_player()
{
  char	buffer[255];
  int	i;

  move((LINES / 2), (COLS / 2) - ((39 + my_strlen(g_tetris.key_tab[4])) / 2));
  attron(A_BOLD);
  printw("Press %s to quit or any key to restart...", g_tetris.key_tab[4]);
  attroff(A_BOLD);
  refresh();
  move(0, 0);
  init_dterm(0);
  i = read(0, buffer, 254);
  buffer[i] = 0;
  init_dterm(1);
  if (my_strcmp(buffer, g_tetris.key_tab[4]) == 0)
    quit_game(0);
}

int	reset_game(t_board *obj, t_llist actual)
{
  wait_player();
  free(obj->board);
  free(obj->board_color);
  obj->board = map_generator(g_tetris.row, g_tetris.col);
  obj->board_color = color_board_gen(g_tetris.row + 2, g_tetris.col + 2);
  if (g_tetris.points > g_tetris.high_score)
    g_tetris.high_score = g_tetris.points;
  g_tetris.level = 1;
  obj->x = ((count_max_col(obj->board) - count_max_col(actual->piece)) / 2);
  obj->y = 1;
  obj->prev_x = obj->x;
  obj->prev_y = obj->y;
  g_tetris.points = 0;
  g_tetris.score_line = 0;
  g_tetris.pause_time = 0;
  g_tetris.timer = -time(NULL);
}

void    print_pause(void)
{
  move((LINES / 2), (COLS / 2) - (9 / 2));
  attron(A_BOLD);
  printw("|| Pause");
  attroff(A_BOLD);
  refresh();
  move(0, 0);
}

int	pause_game()
{
  char	buffer[255];
  int	time_ret;
  int	i;

  time_ret = -time(NULL);
  print_pause();
  while (my_strcmp(buffer, g_tetris.key_tab[5]) != 0)
    {
      i = read(0, buffer, 254);
      buffer[i] = 0;
      if (my_strcmp(buffer, g_tetris.key_tab[4]) == 0)
	quit_game(0);
    }
  g_tetris.pause_time = g_tetris.pause_time + time_ret + time(NULL);
  return (0);
}
