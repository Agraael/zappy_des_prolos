##
## EPITECH PROJECT, 2018
## client
## File description:
## makefile
##

CC              =  g++

CPPFLAGS        +=	-W -Wall -Wextra
CXXFLAGS        +=	-std=c++14 -I ../../includes/client/

NAME            =       ../../zappy_ai

SRCS            =       main.cpp	\

OBJS            =       $(SRCS:.cpp=.o)

all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re