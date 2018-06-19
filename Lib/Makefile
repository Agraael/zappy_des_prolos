##
## EPITECH PROJECT, 2018
## server
## File description:
## makefile
##

CC		= g++

LIBFLAGS    += -I/usr/include/irrlicht/ -L/usr/X11R6/lib -L../../lib/Linux -lIrrlicht -lGL -lGLU -lXxf86vm -lXext -lX11

NAME		= grph

SRCS            =	main.cpp		\
			        IrrlichtLib.cpp \
			        LettersController.cpp \
			        GameInterface.cpp \
				MyEventReciver.cpp \

OBJS            = $(SRCS:.c=.o)

all :		$(OBJS)
		    $(CC) $(LIBFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

