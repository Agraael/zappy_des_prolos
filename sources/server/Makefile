##
## EPITECH PROJECT, 2018
## server
## File description:
## makefile
##

CC		= gcc

CFLAGS	+= -W -Wall -Wextra -Werror -Wfatal-errors -lm -g3


CFLAGS		= -I ../../includes/server/

NAME		= ../../zappy_server

SRCS            =	main.c		\
			check_flags.c	\
			handle_infos.c	\
			str_to_wordtab.c	\
			utils.c		\
			check_args.c	\
			server.c	\
			help.c		\
			loop_server.c	\
			functions/fct_server_look_direction.c \
			functions/fct_server_teamname.c	\
			functions/fct_server_forward.c	\
			functions/fct_server_quit.c	\
			functions/fct_server_right.c	\
			functions/fct_server_left.c	\
			functions/fct_server_look.c	\
			functions/fct_server_inventory.c	\
			functions/fct_server_broadcast.c	\
			functions/fct_server_connectnbr.c	\
			functions/fct_server_fork.c	\
			functions/fct_server_eject.c	\
			functions/fct_server_take.c	\
			functions/fct_server_setobject.c	\
			functions/fct_server_incantation.c	\
			map_generation/generator.c          \
			gest_timer.c                        \

OBJS            = $(SRCS:.c=.o)

all :		$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

