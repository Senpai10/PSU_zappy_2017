##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

SRC_CLIENT	=	client/check_error.c			\
			client/responses.c			\
			client/client.c				\
			client/connect.c 			\
			client/epoll.c				\
			client/list.c				\
			client/list2.c				\
			client/ia.c				\
			client/commands/actions_moves.c		\
			client/commands/actions_req.c		\
			client/commands/actions_ritual.c	\
			client/commands/misc_ritual.c		\
			client/commands/misc_message.c		\
			client/commands/res_broadcast.c		\
			client/commands/res_initial_cmd.c	\
			client/commands/res_inventory.c		\
			client/commands/res_inventory2.c	\
			client/commands/res_inventory3.c	\
			client/commands/res_look2.c		\
			client/commands/res_look.c		\
			client/commands/res_message.c		\
			client/commands/res_ritual.c		\
			client/commands/res_take_object.c	\
			client/commands/res_unique.c		\
			client/commands/res_connect_nbr.c	\
			client/misc/stw.c			\
			client/misc/stw_look.c			\
			client/misc/free.c			\
			client/misc/strcmp_custom.c		\
			client/misc/count_word.c		\
			client/misc/get_quantity.c		\
			client/misc/create_id.c

SRC_CLIENT_MAIN	=	client/main.c

SRC_TEST	=	tests/client/test_check_error.c		\
			tests/client/test_strcmp_custom.c	\
			tests/client/test_count_word.c		\
			tests/client/test_get_quantity.c	\
			tests/client/test_create_id.c		\
			tests/client/test_stw_look.c		\
			tests/client/test_stw.c			\
			tests/client/test_list.c		\
			tests/client/test_list2.c		\
			tests/client/test_actions_moves.c	\
			tests/client/test_res_inventory.c	\
			tests/client/test_res_message.c

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)		\
			$(SRC_CLIENT_MAIN:.c=.o)

CFLAGS		+=	-Wall -Wextra -W -Iinclude -g3

TESTFLAGS	+=	--coverage -lcriterion -lgcov

RM		=	rm -f

CC		=	gcc

NAME		=	zappy_ai

NAME_TEST	=	units

all:		$(NAME)

$(NAME):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME)

tests_run:      $(SRC_TEST)
		$(CC) $(SRC_TEST) $(SRC_CLIENT) $(CFLAGS) -o $(NAME_TEST) $(TESTFLAGS)
		./units
		gcov *.gcno


clean:
		$(RM) $(OBJ_CLIENT)
		$(RM) *.gcda
		$(RM) *.gcno
		$(RM) *.gcov

fclean:		clean
		$(RM) $(NAME) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re


