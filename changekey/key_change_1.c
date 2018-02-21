/*
** key_change_1.c for tetris in /home/alkoleek/TEST_AREA/tetris_debug
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar 10 02:04:50 2017 Maxime DROUIN
** Last update Fri Mar 10 02:04:50 2017 Maxime DROUIN
*/

#include <stdlib.h>
#include "my.h"

void	key_left_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[0] = my_strdup(str);
  i = i + 1;
}

void	key_right_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[1] = my_strdup(str);
  i = i + 1;
}

void	key_turn_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[2] = my_strdup(str);
  i = i + 1;
}

void	key_drop_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[3] = my_strdup(str);
  i = i + 1;
}

void	key_quit_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[4] = my_strdup(str);
  i = i + 1;
}
