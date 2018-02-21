/*
** debug_printer.c for tetris in /home/alkoleek/TEST_AREA/load_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 20:53:09 2017 Maxime DROUIN
** Last update Tue Feb 28 20:53:09 2017 Maxime DROUIN
*/

#include <stdlib.h>
#include "my.h"

void	put_name(char *str)
{
  int	i;

  i = 0;
  my_putstr("Name ");
  while (str[i] != '.')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  my_putstr(" :  ");
}

void	my_put_args(char **args)
{
  my_putstr("Size ");
  my_putstr(args[0]);
  my_putchar('*');
  my_putstr(args[1]);
  my_putstr(" :  Color ");
  my_putstr(args[2]);
  my_putstr(" :\n");
}

void	print_filenb(char **filename)
{
  my_putstr("Tetriminos :  ");
  if (filename == NULL)
    my_putchar('0');
  else
    my_putnbr(count_line(filename));
  my_putchar('\n');
}

void	print_key(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 27 || str[i] == 224)
	my_putstr("^E");
      else if (str[i] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}
