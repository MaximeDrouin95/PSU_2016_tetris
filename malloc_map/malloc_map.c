/*
** malloc_map.c for matchstick in /home/alkoleek/CPE_2016_matchstick
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 21 19:04:41 2017 Maxime DROUIN
** Last update Tue Feb 21 19:04:41 2017 Maxime DROUIN
*/

#include <stdlib.h>

char	**malloc_map(int line, int col)
{
  char	**map;
  int	count;

  count = 0;
  if ((map = malloc(sizeof(char *) * line + 1)) == NULL)
    return (NULL);
  while (count < line)
    {
      if ((map[count] = malloc(sizeof(char) * col + 1)) == NULL)
	return (NULL);
      count = count + 1;
    }
  return (map);
}
