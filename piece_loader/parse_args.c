/*
** parse_args.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Sat Feb 18 11:34:51 2017 Maxime DROUIN
** Last update Sat Feb 18 11:34:51 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int     count_args(char *str, char separator)
{
  int   count;
  int   args;

  args = 1;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] == separator)
	{
	  if (str[count + 1] != separator || str[count + 1] != '\0')
	    args = args + 1;
	}
      count = count + 1;
    }
  return (args);
}

char	**def_w_size(char **tab, char *str, char separator)
{
  int	count_c;
  int	count_w;
  int	count;

  count = 0;
  count_c = 0;
  count_w = 0;
  while (str[count] != '\0')
    {
      if (str[count] != separator)
	{
	  count_c = count_c + 1;
	  if (str[count + 1] == separator || str[count + 1] == '\0')
	    {
	      tab[count_w] = malloc(sizeof(char) * (count_c + 1));
	      count_w = count_w + 1;
	      count_c = 0;
	    }
	}
      count = count + 1;
    }
  return (tab);
}

char	**fill_tab(char **tab, char *str, char separator)
{
  int	count;
  int	count_w;
  int	count_c;

  count = 0;
  count_c = 0;
  count_w = 0;
  while (str[count] != '\0')
    {
      if (str[count] != separator)
	{
	  tab[count_w][count_c] = str[count];
	  count_c = count_c + 1;
	  if (str[count + 1] == separator || str[count + 1] == '\0')
	    {
	      tab[count_w][count_c] = '\0';
	      count_w = count_w + 1;
	      count_c = 0;
	    }
	}
      count = count + 1;
    }
  return (tab);
}

char	**parse_args(char *str, char separator)
{
  char	**args;

  if ((args = malloc(sizeof(char *) * count_args(str, separator))) == NULL)
    return (NULL);
  args = def_w_size(args, str, separator);
  args = fill_tab(args, str, separator);
  if (args[0] == NULL)
    return (NULL);
  return (args);
}
