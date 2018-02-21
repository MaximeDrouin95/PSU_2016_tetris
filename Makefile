##
## Makefile for Makefile in /home/alkoleek/CPool_Day10/lib/my
## 
## Made by Maxime DROUIN
## Login   <alkoleek@epitech.net>
## 
## Started on  Mon Oct 17 13:29:20 2016 Maxime DROUIN
## Last update Sun Dec  4 19:53:00 2016 Maxime DROUIN
##

CC	= gcc -I ./include/

LDFLAGS	= -L./lib -lgnl -lmy -lncurses

RM	= rm -f

NAME	= tetris


SRCS_1	=	malloc_map/get_size.c		\
		malloc_map/load_map.c		\
		malloc_map/malloc_map.c		\
		malloc_map/map_generator.c	\

SRCS_2 =	changekey/arg_err.c		\
		changekey/default_key.c		\
		changekey/d_key.c		\
		changekey/key_change_1.c	\
		changekey/key_change_2.c	\

SRCS_3 =	piece_loader/debug_printer.c	\
		piece_loader/files_operator.c	\
	   	piece_loader/llist_operation.c	\
		piece_loader/load_and_check.c	\
	        piece_loader/parse_args.c	\
		piece_loader/llist_dup.c	\
		piece_loader/check_line.c	\

SRCS_4 =	game/check_for_fall.c		\
		game/do_fall.c			\
		game/exec_tetris.c		\
		game/is_line_full.c		\
		game/tabception.c		\
		game/quit_game.c		\

SRCS_5 =	display/display.c		\
		display/my_showtab_center.c	\

SRCS	= 	help.c				\
	 	main.c				\

OBJS	= $(SRCS:.c=.o)

OBJS_1	= $(SRCS_1:.c=.o)

OBJS_2	= $(SRCS_2:.c=.o)

OBJS_3	= $(SRCS_3:.c=.o)

OBJS_4	= $(SRCS_4:.c=.o)

OBJS_5	= $(SRCS_5:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_1) $(OBJS_2) $(OBJS_3)  $(OBJS_4)  $(OBJS_5)
	$(CC) $(OBJS) $(OBJS_1) $(OBJS_2) $(OBJS_3)  $(OBJS_4)  $(OBJS_5) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)  $(OBJS_1) $(OBJS_2) $(OBJS_3) $(OBJS_4) $(OBJS_5)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
