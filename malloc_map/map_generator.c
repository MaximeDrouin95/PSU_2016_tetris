/*
** map_generator.c for tetris in /home/alkoleek/TEST_AREA/zip
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 02:24:57 2017 Maxime DROUIN
** Last update Tue Feb 28 02:24:57 2017 Maxime DROUIN
*/

#include <stdlib.h>
#include "my.h"

char	**board_generator(int line, int col)
{
  char	**board;
  int	i;
  int	j;

  i = 0;
  if ((board = malloc_map(line, col)) == NULL)
    return (NULL);
  while (i < line)
    {
      j = 0;
      while (j < col)
	{
	  board[i][j] = ' ';
	  j = j + 1;
	}
      board[i][j] = 0;
      i = i + 1;
    }
  board[i] = 0;
  return (board);
}

char	**color_board_gen(int line, int col)
{
  char	**board;
  int	i;
  int	j;

  i = 0;
  if ((board = malloc_map(line, col)) == NULL)
    return (NULL);
  while (i < line)
    {
      j = 0;
      while (j < col)
	{
	  board[i][j] = '1';
	  j = j + 1;
	}
      board[i][j] = 0;
      i = i + 1;
    }
  board[i] = 0;
  return (board);
}

char	*tab_header(int col)
{
  int	i;
  char	*str;

  if ((str = malloc(sizeof(char) * (col + 3))) == NULL)
    return (NULL);
  str[0] = '+';
  i = 1;
  while (i < col + 1)
    {
      str[i] = '=';
      i = i + 1;
    }
  str[i] = '+';
  str[i + 1] = 0;
  return (str);
}

char	*tab_corpse(int col)
{
  int	i;
  char	*str;

  if ((str = malloc(sizeof(char) * (col + 3))) == NULL)
    return (NULL);
  str[0] = '|';
  i = 1;
  while (i < col + 1)
    {
      str[i] = ' ';
      i = i + 1;
    }
  str[i] = '|';
  str[i + 1] = 0;
  return (str);
}

char	**map_generator(int line, int col)
{
  char	**map;
  int	i;

  i = 1;
  map = malloc_map(line + 2, col + 2);
  map[0] = tab_header(col);
  while (i < line + 1)
    {
      map[i] = tab_corpse(col);
      i = i + 1;
    }
  map[i] = tab_header(col);
  map[i + 1] = NULL;
  return (map);
}
