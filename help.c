/*
** help.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:39:35 2017 Maxime DROUIN
** Last update Fri Mar  3 16:48:03 2017 Maxime BLANCHARD
*/

#include <stdlib.h>
#include "my.h"

void    help(char **argv)
{
  my_putstr("Usage:\t");
  my_putstr(argv[0]);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("  -kl --key-left={K}\tMove the tetrimino LEFT using the K ");
  my_putstr("key (def: left arrow)\n");
  my_putstr("  -kr --key-right={K}\tMove the tetrimino RIGHT using the K ");
  my_putstr("key (def: right arrow)\n");
  my_putstr("  -kt --key-turn={K}\tTURN the tetrimino clockwise 90d using ");
  my_putstr("the K key (def: top arrow)\n");
  my_putstr("  -kd --key-drop={K}\tDROP the tetrimino using the K key ");
  my_putstr("(def: down arrow)\n");
  my_putstr("  -kq --key-quit={K}\tQUIT the game using the K key (def: 'q' ");
  my_putstr("key)\n");
  my_putstr("  -kp --key-pause={K}\tPAUSE/RESTART the game using the K key ");
  my_putstr("(def: space bar)\n");
  my_putstr("  --map-size={row,col}\tSet the numbers of rows and columns of ");
  my_putstr("the map (def: 20,10)\n");
  my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("  -d --debug\t\tDebug mode (def: false)\n");
  exit(84);
}
