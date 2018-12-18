##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -I../include -lncurses -lcriterion --coverage

NAME	=	test

SRCS	=	test.c			\
		../src/init.c		\
		../src/check_args.c	\
		../src/run.c		\
		../src/store_obj_location.c\
		../src/store_box_location.c\
		../src/set_player.c	\
		../src/reset.c		\
		../src/print_usage.c	\
		../src/check_map.c	\
		../src/count_obj.c	\
		../src/move.c		\
		../src/move2.c		\
		../src/move_box.c	\
		../src/draw_storage.c	\
		../src/is_win.c		\
		../src/is_lose.c	\


OBJS	=	$(SRCS:.c=.o)

#LIBS	=	-lncurses -lcriterion --coverage

MY_LIBS	=	-L../lib/my -lmy

CFLAGS	=	-Wall -Wextra

all:	libs $(NAME)

libs:
	$(MAKE) -C ../lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(MY_LIBS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run: $(MAKE) -C ../tests/

.PHONY: all clean fclean re tests_run
