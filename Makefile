##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

NAME_SERVER	=	zappy_server

NAME_CLIENT	=	zappy_ai

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
	make -C server/
	mv server/$(NAME_SERVER) ./

$(NAME_CLIENT):
	make -C dir_client/
	mv dir_client/$(NAME_CLIENT) ./

$(NAME_GRAPHIC):
	make -C server/

clean:
	make clean -C dir_client/
	make clean -C server/

fclean:
	make fclean -C dir_client/
	make fclean -C server/
	rm $(NAME_SERVER)
	rm $(NAME_CLIENT)

re: fclean all
