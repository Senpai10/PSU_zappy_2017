##
## EPITECH PROJECT, 2018
## Project Name
## File description:
## server Makefile
##

SRC	=	src/main.cpp				\
		src/GameMenu.cpp			\
		src/MenuControllers.cpp			\
		src/ConnectServer.cpp			\
		src/Trantorian.cpp			\
		src/MainGame.cpp			\
		src/Tile.cpp				\

SRCTOTEST	=	src/GameMenu.cpp	\
			src/MenuControllers.cpp	\
			src/ConnectServer.cpp	\
			src/Tile.cpp		\

TESTSRC	=	tests/TestGameMenu.cpp		\
		tests/TestConnectServer.cpp	\
		tests/TestTile.cpp		\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	graphical_client

CPPFLAGS	+=	-std=c++11 -I include/ -g3 -W -Wall -Wextra -Werror -lsfml-window -lsfml-graphics -lsfml-system -lsfml-network -lsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) -std=c++11 $(OBJ) $(CPPFLAGS)

tests_run:	$(TESTSRC)
	g++ $(CPPFLAGS) $(TESTSRC) $(SRCTOTEST) -o unit_tests -coverage -lcriterion -lgcov
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:. ./unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all