/*
** main.c for Tetris in /home/Rubiks/PSU/PSU_2016_tetris
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Mon Feb 27 12:02:15 2017 Maxime BLANCHARD
** Last update Tue Mar 14 19:02:38 2017 Maxime BLANCHARD
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <getopt.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "my.h"

t_game g_tetris = {.row = 20,
		   .col = 10,
		   .debug = 0,
		   .without_next = 0,
		   .level = 1,
		   .high_score = 0,
		   .score_line = 0,
		   .pause_time = 0,
		   .points = 0};

int	set_read(int state)
{
  static struct termios old;
  struct termios	new;

  if (state == 0)
    {
      if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
	return (1);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);
    }
  else
    if (ioctl(0, TCSETS, &old) == -1)
      return (1);
  return (0);
}

static struct option g_long_options[] =
  {
    {"debug",   no_argument,       &g_tetris.debug, 1},
    {"d",   no_argument,       &g_tetris.debug, 1},
    {"w",   no_argument,       &g_tetris.without_next, 1},
    {"without-next",   no_argument,       &g_tetris.without_next, 1},
    {"help",  no_argument, 0, 'h'} ,
    {"l",  required_argument, 0, 7},
    {"level",  required_argument, 0, 7},
    {"kl",  required_argument, 0, 1},
    {"key-left",  required_argument, 0, 1},
    {"kr",  required_argument, 0, 2},
    {"key-right",  required_argument, 0, 2},
    {"kt",  required_argument, 0, 3},
    {"key-turn",  required_argument, 0, 3},
    {"kd",  required_argument, 0, 4},
    {"key-drop",  required_argument, 0, 4},
    {"kq",  required_argument, 0, 5},
    {"key-quit",  required_argument, 0, 5},
    {"key-pause",  required_argument, 0, 6},
    {"kp",  required_argument, 0, 6},
    {"map-size",  required_argument, 0, 8},
    {0, 0, 0, 0}
  };

void	(*key_list_c[8])(char *) = {key_left_c,
				    key_right_c,
				    key_turn_c,
				    key_drop_c,
				    key_quit_c,
				    key_pause_c,
				    level_c,
				    map_size_c};

t_llist	arg_load(int argc, char **argv, t_llist list)
{
  int	c;
  int	option_index;

  c = 0;
  option_index = 0;
  while (c != -1)
    {
      c = getopt_long_only (argc, argv, "", g_long_options, &option_index);
      if (c >= 1 && c <= 8)
	key_list_c[c - 1](optarg);
      if (c == 'h')
	help(argv);
      if (c == '?')
	exit(84);
    }
  if (optind < argc)
    {
      my_putstr("Error: unrecognized argument(s)\n");
      exit(84);
    }
  if (g_tetris.debug)
    list = debug_print_mode(list);
  else
    list = load_in_llist(list, 0);
  return (list);
}

void    init_curses()
{
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_CYAN, COLOR_BLACK);
  curs_set(0);
  noecho();
}

int		main(int argc, char **argv)
{
  t_board	obj;
  t_llist	list;

  obj.logo = load_map("logo", 5);
  obj.logo_color = load_map("logo_color", 5);
  obj.tab_next = load_map("next", 8);
  obj.tab_score = load_map("score", 7);
  list = NULL;
  g_tetris.key_tab = default_key();
  if ((list = arg_load(argc, argv, list)) == NULL)
    return (84);
  obj.board = map_generator(g_tetris.row, g_tetris.col);
  obj.board_color = color_board_gen(g_tetris.row + 2, g_tetris.col + 2);
  init_curses();
  set_read(0);
  my_putstr(tigetstr("smkx"));
  exec_tetris(&obj, list);
  set_read(1);
  endwin();
  return (0);
}
