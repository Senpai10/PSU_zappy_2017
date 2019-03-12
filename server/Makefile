##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

SRC_SERVER	=	server/server.c				\
			server/init_client_info.c		\
			server/server_loop.c			\
			server/handle_epoll_event.c		\
			server/add_client_in_list.c		\
			ai_cmd/ai_cmd.c				\
			ai_cmd/add_cmd.c			\
			ai_cmd/find_client.c			\
			ai_cmd/time_handling.c			\
			parse_cmd/read_line.c			\
			parse_cmd/receve_msg.c			\
			parse_cmd/graph_cmd.c			\
			parse_cmd/moving_command.c		\
			parse_cmd/turn_command.c		\
			parse_cmd/describe_tile.c		\
			parse_cmd/looking.c			\
			parse_cmd/side_vision.c			\
			utils/prints.c				\
			utils/list_len.c			\
			utils/str_to_wordtab.c			\
			connection/get_client_fd.c		\
			connection/handle_new_connection.c	\
			connection/create_epoll.c		\
			handle_options/error_managment.c	\
			handle_options/get_arguments.c		\
			handle_options/check_option.c		\
			handle_options/n_option.c		\
			handle_options/options.c		\
			handle_options/add_new_team.c		\
			graphic_cmd/send_map_content.c		\
			map_navigate.c \
			chaining_char.c \
			init_ressources.c \
			init_struc.c \
			loot_stone.c \
			loot_stonev2.c \


OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

NAME_SERVER	=	zappy_server

CFLAGS		+= -W -Wall -Wextra -I ./includes/

all: 		$(NAME_SERVER)

$(NAME_SERVER): 	$(OBJ_SERVER)
	gcc $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

clean:
	rm -f $(OBJ_SERVER) *.g*

fclean: clean
	rm -f $(NAME_SERVER) vgcore.*

re: fclean all