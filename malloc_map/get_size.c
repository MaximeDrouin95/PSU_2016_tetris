/*
** get_size.c for BSQ in /home/Rubiks/CPE_2016_BSQ
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Mon Dec 12 18:45:04 2016 Maxime BLANCHARD
** Last update Mon Feb 27 13:19:49 2017 Maxime BLANCHARD
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int	count_max_col(char **tab)
{
  int	i;
  int	max;

  max = 0;
  i = 0;
  while (tab[i] != 0)
    {
      if (my_strlen(tab[i]) > max)
	max = my_strlen(tab[i]);
      i = i + 1;
    }
  return (max);
}

int	count_line(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (i);
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

int	get_lines(char *filepath)
{
  int   fd;
  int   i;
  char  buffer[2];

  i = 1;
  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return (0);
  while (read(fd, buffer, 1) > 0)
    {
      if (buffer[0] == '\n')
	i = i + 1;
    }
  close(fd);
  return (i);
}

int	get_columns(char *filepath)
{
  int   fd;
  int   i;
  char  buffer[2];

  i = 0;
  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return (0);
  while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
    i = i + 1;
  close(fd);
  return (i);
}
