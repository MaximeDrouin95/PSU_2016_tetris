/*
** exec_tetris.c for tetris in /home/alkoleek/PSU_2016_tetris
**
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar 17 01:13:35 2017 Maxime DROUIN
** Last update Fri Mar 17 01:13:35 2017 Maxime DROUIN
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "my.h"

int	take_new(t_llist list, t_llist *actual, t_llist *next, t_board *obj)
{
  free((*actual)->piece);
  free((*actual));
  (*actual) = (*next);
  (*next) = llist_dup(pick_new(list, count_inlist(list)));
  obj->x = ((count_max_col(obj->board) - count_max_col((*actual)->piece)) / 2);
  obj->y = 1;
  obj->prev_x = obj->x;
  obj->prev_y = obj->y;
}

int	init_new(t_llist list, t_llist *actual, t_llist *next, t_board *obj)
{
  (*actual) = llist_dup(pick_new(list, count_inlist(list)));
  (*next) = llist_dup(pick_new(list, count_inlist(list)));
  obj->x = ((count_max_col(obj->board) - count_max_col((*actual)->piece)) / 2);
  obj->y = 1;
  obj->prev_x = obj->x;
  obj->prev_y = obj->y;
}

void	action_tetris(t_board *obj, t_llist actual, t_llist next)
{
  char	buffer[255];
  int	ticks;
  int	i;

  ticks = 0;
  while (ticks <= ((-g_tetris.level) + 10))
    {
      i = read(0, buffer, 254);
      buffer[i] = 0;
      if (my_strcmp(buffer, g_tetris.key_tab[0]) == 0)
	obj->x = obj->x - 1;
      else if (my_strcmp(buffer, g_tetris.key_tab[1]) == 0)
	obj->x = obj->x + 1;
      else if (my_strcmp(buffer, g_tetris.key_tab[2]) == 0)
	do_rotate(obj, actual);
      else if (my_strcmp(buffer, g_tetris.key_tab[3]) == 0)
	do_drop(obj, actual);
      else if (my_strcmp(buffer, g_tetris.key_tab[4]) == 0)
	quit_game(0);
      else if (my_strcmp(buffer, g_tetris.key_tab[5]) == 0)
	pause_game();
      do_move(obj, actual);
      display(obj, next);
      ticks = ticks + 1;
    }
}

int	level_up(t_board *obj)
{
  static int level_plus = 0;

  while (remove_line(obj) != 0)
    {
      g_tetris.score_line = g_tetris.score_line + 1;
      g_tetris.points = g_tetris.points + 10;
      level_plus = level_plus + 10;
      if (level_plus == 100 && g_tetris.level < 10)
	{
	  g_tetris.level = g_tetris.level + 1;
	  level_plus = 0;
	}
    }
}

int		exec_tetris(t_board *obj, t_llist list)
{
  int		game_over;
  t_llist	actual;
  t_llist	next;

  game_over = 0;
  init_new(list, &actual, &next, obj);
  g_tetris.timer = -time(NULL);
  while (game_over != 1)
    {
      print_resize();
      display(obj, next);
      game_over = do_fall(obj, actual);
      display(obj, next);
      if (game_over == 2)
	{
	  level_up(obj);
	  take_new(list, &actual, &next, obj);
	  if (do_fall(obj, actual) == 1)
	    reset_game(obj, actual);
	  display(obj, next);
	}
      display(obj, next);
      action_tetris(obj, actual, next);
      display(obj, next);
    }
  return (0);
}
