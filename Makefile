##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -Iinclude -lncurses

NAME	=	my_sokoban

SRCS	=	src/main.c			\
		src/run.c			\
		src/check_args.c		\
		src/init.c			\
		src/store_obj_location.c	\
		src/store_box_location.c	\
		src/set_player.c		\
		src/reset.c			\
		src/print_usage.c		\
		src/check_map.c			\
		src/count_obj.c			\
		src/move.c			\
		src/move2.c			\
		src/move_box.c			\
		src/draw_storage.c		\
		src/is_win.c			\
		src/is_lose.c			\
		src/free_everything.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -Llib/my -lmy

all:	libs $(NAME)

libs:
	$(MAKE) -C lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/my/
	$(MAKE) clean -C unit_test/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/my/
	$(MAKE) fclean -C unit_test/

re: fclean all

tests_run:
	$(MAKE) -C unit_test/
	cd unit_test && ./test
	gcovr

.PHONY: all clean fclean re tests_run
