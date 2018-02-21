/*
** main.c for tetris in /home/alkoleek/TEST_AREA/DEFAULT_KEY
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Mar  3 16:23:04 2017 Maxime DROUIN
** Last update Fri Mar  3 16:23:04 2017 Maxime DROUIN
*/

#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <termios.h>
#include <ncurses.h>
#include "my.h"

char	**default_key()
{
  char	**key;

  if ((key = malloc(sizeof(char *) * 7)) == NULL)
    return (NULL);
  setupterm(NULL, fileno(stdout), NULL);
  if (((key[0] = tigetstr("kcub1")) == (char *)-1)
      || ((key[1] = tigetstr("kcuf1")) == (char *)-1)
      || ((key[2] = tigetstr("kcuu1")) == (char *)-1)
      || ((key[3] = tigetstr("kcud1")) == (char *)-1)
      || ((key[4] = my_strdup("q")) == NULL)
      || ((key[5] = my_strdup(" ")) == NULL))
    return (NULL);
  key[6] = 0;
  return (key);
}
