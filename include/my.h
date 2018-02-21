/*
** my.h for tetris in /home/alkoleek/TEST_AREA/load_tetris
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb 28 15:00:51 2017 Maxime DROUIN
** Last update Sun Mar 19 14:57:03 2017 Maxime BLANCHARD
*/

#ifndef MY_H_
# define MY_H_

typedef struct		s_game
{
  char	**key_tab;
  int	col;
  int	row;
  int	debug;
  int	without_next;
  int	high_score;
  int	level;
  int	points;
  int	pause_time;
  int	score_line;
  int	timer;
}			t_game;

typedef struct		s_board
{
  char	**board;
  char	**board_color;
  char	**logo;
  char	**logo_color;
  char	**tab_next;
  char	**tab_score;
  int	x;
  int	y;
  int	prev_x;
  int	prev_y;
}			t_board;

typedef struct		s_piece_size
{
  int	height;
  int	width;
}			t_piece_size;

typedef struct		s_element
{
  char	**piece;
  int	color;
  t_piece_size	size;
  struct s_element *nxt;
}			t_element;
typedef t_element* t_llist;

typedef struct		s_location
{
  int	i;
  int	j;
}			t_location;
extern t_game g_tetris;
void    help(char **);
void	key_turn_c(char *);
void	level_c(char *);
void	map_size_c(char *);
void	key_left_c(char *);
void	key_right_c(char *);
void	key_quit_c(char *);
void	key_pause_c(char *);
void	key_drop_c(char *);
t_llist	element_i(t_llist, int);
int	check_for_fall(char **, t_llist, int, int);
void	my_showtab(char **);
void    too_muchargs();
int	tabremover(t_board *, t_llist, int, int);
int     tabception(t_board *, t_llist, int, int);
t_llist	add_first(t_llist, char **, char **);
t_llist debug_print_mode(t_llist);
int	my_strcmp(char *, char *);
int     check_line(char *, char **);
char	**color_board_gen(int, int);
void    my_putchar(char);
int	timer(int);
int	exec_tetris(t_board *, t_llist);
void    print_filenb(char **);
void    my_showtab_center(t_board);
void    my_put_args(char **);
void    put_name(char *);
void    my_showboard(char **, char **);
void    my_showlogo(char **, char **, int, int);
void    my_shownext(char **, int, int, int);
void    my_showxy(char **, int, int, int);
int     my_getnbr(char *);
int     init_dterm(int);
int     set_read(int);
void    print_resize(void);
int     do_fall(t_board *, t_llist);
int     wait_player();
int     pause_game();
char    **board_generator(int, int);
t_llist	llist_dup(t_llist);
int     clear_line(t_board *, int);
void    print_pause(void);
void    invalid_row();
void    invalid_col();
int	remove_line(t_board *);
int	check_args(char **);
void	print_key(char *);
char    **tab_dup(char **);
int     quit_game(int);
int	my_str_isnum(char *);
t_llist pick_new(t_llist, int);
int     display(t_board *, t_llist);
int     reset_game(t_board *, t_llist);
int     my_putnbr(int);
int     do_move(t_board *, t_llist);
int	my_putstr(char *);
int     do_rotate(t_board *, t_llist);
int     do_drop(t_board *, t_llist);
int     rand_llist(t_llist);
int     count_tetrimino_col(char **);
int     my_strlen(char *);
int     get_lines(char *);
int     initTerm (int);
int     get_columns(char *);
int     count_max_col(char **);
int     count_inlist(t_llist);
int     count_line(char **);
int     file_select(char *);
int     my_strcmp(char *, char *);
int     **malloc_imap(int, int);
char    *get_next_line(const int);
char    *my_strdup(char *);
char    **my_sort_wordtab(char **);
char    **mlloc_board(int, int);
char    **default_key();
char    **load_map(char *, int);
char    **get_files(char *);
char    **map_generator(int, int);
char    **malloc_map(int, int);
char    **parse_args(char *, char);
t_llist   print_error(t_llist);
t_llist   load_in_llist(t_llist, int);
char	*get_next_line(const int);
#endif /* !MY_H_ */
