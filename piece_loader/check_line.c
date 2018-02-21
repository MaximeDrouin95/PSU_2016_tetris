/*
** check_line.c for tetris in /home/alkoleek/PSU_2016_tetris/piece_loader
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Sun Mar 19 10:48:34 2017 Maxime DROUIN
** Last update Sun Mar 19 10:48:34 2017 Maxime DROUIN
*/

#include <stdlib.h>
#include "my.h"

int	check_line(char *str, char **args)
{
  int	i;
  int	count;

  i = my_strlen(str) - 1;
  count = 0;
  while (str[i] == ' ' && i >= 0)
    i = i - 1;
  while (i >= 0)
    {
      if (str[i] == ' ' || str[i] == '*')
	count = count + 1;
      else
	return (-1);
      i = i - 1;
    }
  if (count > my_getnbr(args[0]))
    return (-1);
  return (0);
}
