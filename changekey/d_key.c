/*
** main.c for main in /home/alkoleek/TEST_AREA/pwet
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar  3 01:06:00 2017 Maxime DROUIN
** Last update Fri Mar  3 01:06:00 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <termios.h>
#include <ncurses.h>
#include "my.h"

static char *g_key_str[7] = {"Key Left :  ",
			     "Key Right :  ",
			     "Key Turn :  ",
			     "Key Drop :  ",
			     "Key Quit :  ",
			     "Key Pause :  ",
			     0};

int	init_dterm(int state)
{
  static struct termios old;
  struct termios	new;

  if (state == 0)
    {
      if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
	return (1);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 1;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);
    }
  else
    if (ioctl(0, TCSETS, &old) == -1)
      return (1);
  return (0);
}

void	put_game_size()
{
  my_putstr("\nSize :  ");
  my_putnbr(g_tetris.row);
  my_putchar('*');
  my_putnbr(g_tetris.col);
  my_putchar('\n');
}

t_llist	debug_print_mode(t_llist list)
{
  int	i;
  char	buffer[255];

  i = 0;
  my_putstr("*** DEBUG MODE ***\n");
  while (g_key_str[i] != 0 && g_tetris.key_tab[i] != 0)
    {
      my_putstr(g_key_str[i]);
      print_key(g_tetris.key_tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  if (g_tetris.without_next)
    my_putstr("Next :  No\nLevel :  ");
  else
    my_putstr("Next :  Yes\nLevel :  ");
  my_putnbr(g_tetris.level);
  put_game_size();
  list = load_in_llist(list, 1);
  init_dterm(0);
  my_putstr("Press any key to start Tetris\n");
  read(0, buffer, 254);
  init_dterm(1);
  return (list);
}
