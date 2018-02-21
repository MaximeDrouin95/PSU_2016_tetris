/*
** arg_err.c for tetris in /home/alkoleek/TEST_AREA/tetris_debug
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar 10 02:15:55 2017 Maxime DROUIN
** Last update Fri Mar 10 02:15:55 2017 Maxime DROUIN
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	too_muchargs()
{
  my_putstr("Error: Too much arguments\n");
  exit(84);
}

void	invalid_row()
{
  my_putstr("Error: invalid row\n");
  exit(84);
}

void	invalid_col()
{
  my_putstr("Error: invalid column\n");
  exit(84);
}
