##
## EPITECH PROJECT, 2018
## client
## File description:
## makefile
##

CC              =  g++

CPPFLAGS        +=	-W -Wall -Wextra
CXXFLAGS        +=	-std=c++17 -I ../../includes/client/ -I ServerCommunication/ -I Parsing/ -I AI/

NAME            =       ../../zappy_ai

SRCS            =       main.cpp					\
			ServerCommunication/CommunicateToServer.cpp	\
			ServerCommunication/Client.cpp			\
			Parsing/ParseArgs.cpp \
			AI/IGraph.cpp \
            AI/ZappyGraph.cpp \
            AI/PathFinder2D.cpp \
            AI/ZappyAi.cpp \
            AI/DecisionTree.cpp \
            ../Lib/IrrlichtLib.cpp \
            ../Lib/LettersController.cpp \
            ../Lib/GameInterface.cpp \
            ../Lib/LibEventManager.cpp \
            ../Lib/Inventary.cpp \
            ../Lib/GameMap.cpp \
            ../Lib/Player.cpp \

OBJS            =       $(SRCS:.cpp=.o)

all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re