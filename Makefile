##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## zappy
##

all :
		make -C ./sources/server/
		make -C ./sources/client/

zappy_server :	make -C ./sources/server/

zappy_ai :
		make -C ./sources/client/

clean :
		make clean -C ./sources/server/
		make clean -C ./sources/client/

fclean :
		make fclean -C ./sources/server/
		make fclean -C ./sources/client/

re :    fclean all

.PHONY :        all zappy_server zappy_ai clean fclean re
