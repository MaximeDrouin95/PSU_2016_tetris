/*
** files_operator.c for tetris in /home/alkoleek/TEST_AREA/load_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 20:57:17 2017 Maxime DROUIN
** Last update Tue Feb 28 20:57:17 2017 Maxime DROUIN
*/

#include <curses.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

int	count_tetrimino_col(char **tetrimino)
{
  int	i;
  int	j;
  int	max;

  max = 0;
  i = 0;
  while (tetrimino[i] != 0)
    {
      j = my_strlen(tetrimino[i]) - 1;
      while (tetrimino[i][j] == ' ' && j >= 0)
	j = j - 1;
      if (j > max)
	max = j;
      i = i + 1;
    }
  return (max + 1);
}

int	count_files(char *path)
{
  DIR	*directory;
  struct dirent *file;
  int	i;

  i = 0;
  if ((directory = opendir(path)) == NULL)
    return (0);
  while (file = readdir(directory))
    if (file_select(file->d_name) == 1)
      i = i + 1;
  closedir(directory);
  return (i);
}

char	**get_files(char *path)
{
  DIR	*tetriminos;
  struct dirent *file;
  char	**files;
  int	i;

  i = 0;
  if (count_files(path) == 0)
    return (NULL);
  if ((files = malloc(sizeof(char *) * count_files(path) + 1)) == NULL)
    return (NULL);
  if ((tetriminos = opendir(path)) == NULL)
    return (NULL);
  chdir(path);
  while (file = readdir(tetriminos))
    {
      if (file_select(file->d_name) == 1)
	{
	  files[i] = file->d_name;
	  i = i + 1;
	}
    }
  files[i] = NULL;
  return (my_sort_wordtab(files));
}

int	file_select(char *d_name)
{
  int	i;

  i = 0;
  while (d_name[i] != '.')
    {
      if (d_name[i] == '\0')
	return (0);
      d_name = d_name + 1;
    }
  if (my_strcmp(".tetrimino", d_name) == 0)
    return (1);
  else
    return (0);
}

int	check_args(char **args)
{
  if (args[0] == NULL || args[1] == NULL || args[2] == NULL)
    return (0);
  if (my_getnbr(args[0]) < 1 || my_getnbr(args[0]) > g_tetris.col - 1)
    return (0);
  if (my_getnbr(args[1]) < 1 || my_getnbr(args[1]) > g_tetris.row - 1)
    return (0);
  if (my_getnbr(args[2]) < 1 || my_getnbr(args[2]) > 7)
    return (0);
}
