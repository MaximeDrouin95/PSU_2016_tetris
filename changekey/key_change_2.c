/*
** key_change_2.c for tetris in /home/alkoleek/TEST_AREA/tetris_debug
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar 10 02:05:39 2017 Maxime DROUIN
** Last update Fri Mar 10 02:05:39 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	level_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  if (my_str_isnum(str))
    g_tetris.level = my_getnbr(str);
  else
    {
      my_putstr("Error: level must be num\n");
      exit(84);
    }
  if (g_tetris.level == 0 || g_tetris.level > 10 || g_tetris.level < 0)
    {
      my_putstr("Error: invalid level\n");
      exit(84);
    }
  i = i + 1;
}

void	map_size_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.row = my_getnbr(str);
  if (g_tetris.row == 0)
    invalid_row();
  while (*str != ',' && *str != 0)
    str = str + 1;
  if (*str == 0)
    {
      my_putstr("Error: Bad map format\n");
      exit(84);
    }
  str = str + 1;
  g_tetris.col = my_getnbr(str);
  if (g_tetris.col == 0)
    invalid_col();
  i = i + 1;
}

void	key_pause_c(char *str)
{
  static int i = 0;

  if (i > 0)
    too_muchargs();
  g_tetris.key_tab[5] = my_strdup(str);
  i = i + 1;
}
