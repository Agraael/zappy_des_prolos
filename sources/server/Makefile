##
## EPITECH PROJECT, 2018
## server
## File description:
## makefile
##

CC              = gcc

CPPFLAGS        += -W -Wall -Wextra
CPPFLAGS        += -std=c++14

NAME            = .././zappy_server

SRCS            = main.cpp		\

OBJS            = $(SRCS:.cpp=.o)



all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

