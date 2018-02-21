/*
** llist_dup.c for tetris in /home/alkoleek/PSU_2016_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Sat Mar 11 15:33:56 2017 Maxime DROUIN
** Last update Sat Mar 11 15:33:56 2017 Maxime DROUIN
*/

#include <stdlib.h>
#include "my.h"

t_llist		llist_dup(t_llist list)
{
  t_llist	dup;

  if (list == NULL)
    return (NULL);
  if ((dup = malloc(sizeof(t_element))) == NULL)
    return (NULL);
  dup->piece = tab_dup(list->piece);
  dup->size.height = list->size.height;
  dup->size.width = list->size.width;
  dup->color = list->color;
  dup->nxt = NULL;
  return (dup);
}
