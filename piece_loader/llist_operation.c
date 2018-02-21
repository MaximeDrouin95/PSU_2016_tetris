/*
** llist_operation.c for tetris in /home/alkoleek/TEST_AREA/load_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 14:57:13 2017 Maxime DROUIN
** Last update Thu Mar  9 17:30:17 2017 Maxime BLANCHARD
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"

t_llist	print_error(t_llist list)
{
  my_putstr("Error\n");
  return (list);
}

t_llist	pick_new(t_llist list, int max)
{
  static int    i = 0;
  int	count;
  int	rand_nb;

  count = 1;
  if (i == 0)
    {
      srand(time(NULL));
      i = 1;
    }
  rand_nb = rand() % (max + 1);
  while (count < rand_nb && list != NULL)
    {
      list = list->nxt;
      count = count + 1;
    }
  if (list == NULL)
    return (NULL);
  else
    return (list);
}

t_llist   add_first(t_llist list, char **piece, char **args)
{
  t_llist new_list;

  if ((new_list = malloc(sizeof(t_element))) == NULL)
    return (NULL);
  new_list->piece = piece;
  new_list->size.height = count_line(piece);
  new_list->size.width = count_max_col(piece);
  new_list->color = args[2][0];
  new_list->nxt = list;
  return (new_list);
}

t_llist   del_last(t_llist list)
{
  t_llist tmp;
  t_llist ptmp;

  tmp = list;
  ptmp = list;
  if (list == NULL)
    return (NULL);
  if (list->nxt == NULL)
    return (NULL);
  while (tmp->nxt != NULL)
    {
      ptmp = tmp;
      tmp = tmp->nxt;
    }
  ptmp->nxt = NULL;
  free(tmp);
  return (list);
}

int	count_inlist(t_llist list)
{
  if (list == NULL)
    return (0);
  return (count_inlist(list->nxt)+1);
}
