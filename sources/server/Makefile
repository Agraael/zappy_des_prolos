##
## EPITECH PROJECT, 2018
## server
## File description:
## makefile
##

CC		= gcc

CPPFLAGS	+= -W -Wall -Wextra -Werror -Wfatal-errors
CFLAGS		= -I ../../includes/server/

NAME		= ../../zappy_server

SRCS            =	main.c		\
			check_args.c	\
			check_flags.c	\
			handle_infos.c	\
			help.c		\
			utils.c

OBJS            = $(SRCS:.c=.o)

all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

