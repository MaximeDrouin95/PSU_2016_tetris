/*
** load_map.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:39:49 2017 Maxime DROUIN
** Last update Mon Feb 13 22:05:54 2017 Maxime DROUIN
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	**tab_dup(char **tab)
{
  int	i;
  char	**dup;

  i = 0;
  while (tab[i] != 0)
    i = i + 1;
  if ((dup = malloc(sizeof(char *) * i + 1)) == NULL)
    return (NULL);
  dup[i] = NULL;
  i = 0;
  while (tab[i] != 0)
    {
      dup[i] = my_strdup(tab[i]);
      i = i + 1;
    }
  return (dup);
}

char	**load_map(char *filepath, int tab_size)
{
  char	**map;
  char	*s;
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (NULL);
  if (tab_size < 1)
    return (NULL);
  if ((map = malloc(sizeof(char *) * tab_size + 1)) == NULL)
    return (NULL);
  while (s = get_next_line(fd))
    {
      map[i] = s;
      i = i + 1;
    }
  map[i] = NULL;
  close(fd);
  return (map);
}

char	**load_map_fd(const int fd, int tab_size)
{
  char	**map;
  char	*s;
  int	i;

  i = 0;
  if (fd == -1)
    return (NULL);
  if (tab_size < 1)
    return (NULL);
  if ((map = malloc(sizeof(char *) * tab_size + 1)) == NULL)
    return (NULL);
  while (s = get_next_line(fd))
    {
      map[i] = s;
      i = i + 1;
    }
  map[i] = NULL;
  return (map);
}
