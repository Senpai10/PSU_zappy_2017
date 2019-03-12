/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server
*/

#ifndef SERVER_H_
	#define SERVER_H_

extern const int SUCCESS_RET;
extern const int ERR_RET;
extern const int ERR;
extern const int ALLOC_EVENTS;
extern const int MAX_EVENTS;
extern const int FIRST;
extern const int SND;

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <time.h>
#include <netdb.h>
#include <sys/time.h>
#include "option.h"

typedef struct			s_character
{
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
	int			do_i_need_food;
	int			level;
	char			*team;
	int			fd;
	int			id;
	int			x;
	int			y;
	int			angle;
	struct s_character	*next;
}				t_character;

typedef struct		s_tile
{
	int		linemate;
	int		deraumere;
	int		sibur;
	int		mendiane;
	int		phiras;
	int		thystame;
	int		food;
	int		egg;
	int		elevation_ready;
	t_character 	*first;
	struct s_tile	*right;
	struct s_tile	*left;
	struct s_tile	*up;
	struct s_tile	*down;
}			t_tile;

typedef struct			server_s
{
	int			server_fd;
	int			epoll_fd;
	int			event_count;
	struct	team_s		*teams;
	struct	graph_clt_s	*g_clt;
	struct	args_s		*args;
	struct	s_tile		*root;
}				server_t;

typedef	void(*fptr)(t_character *, t_tile *tile, server_t *);

typedef struct	s_cmd
{
	int	initialize;
	long	time_begin;
	long	time_cmd;
	fptr	i;
	struct s_cmd	*next;
}		cmd_t;

typedef struct		client_s
{
	int		client_fd;
	FILE		*stream;
	struct	s_cmd	*cmd;
	struct client_s	*next;
}			client_t;

typedef struct	graph_clt_s
{
	int	fd;
	FILE	*stream;
}		graph_clt_t;

args_t		*error_managment(int ac, char **av);
int		get_args(int ac, char **av, args_t *args);
server_t	*init_client_info(args_t *option);
int		get_client_fd(const int port, args_t *args);
int		create_epoll_instance(const int server_fd);
int		handle_epoll_event(struct epoll_event *events, server_t *serv);
int		get_epoll_event(struct epoll_event *event, const int serv_fd);
int		handle_new_connection(server_t *serv);
int		receve_msg(int client_fd, server_t *serv);
int		server_loop(server_t *info);
char		*get_line(FILE *stream);
char		**str_to_wordtab(char *str);
void		remooving_char(t_tile *root, int x, int y);
int		graph_cmd(char **cmd, server_t *server, int new_fd
			, FILE *stream);
int		ai_cmd(char **cmd, server_t *serv, int new_fd);
int		send_map_content(server_t *serv);
t_tile		**init_map(int x, int y);
t_tile  	**init_ptr_ud(t_tile  **map, int x, int y);
t_tile  	**init_ptr_lr(t_tile  **map, int x, int y);
void		chaining_char(t_tile *tile, t_character *last);
void		init_char_map(t_character *charac, t_tile *root);
void		init_character(t_character *charac, char *team, int fd
				, server_t *serv);
void		print_usage(void);
int		add_cmd_to_list(server_t *serv, fptr ptr, int client_fd);
client_t	*get_client(team_t *team, int client_fd);
int	add_client_in_list(team_t *team, int client_fd, char *team_name);
void		look_right(t_character *charac, t_tile *tile);
void		look_left(t_character *charac, t_tile *tile);
void		look_down(t_character *charac, t_tile *tile);
void		side_vision_left(t_character *charac, t_tile *tile);
void		describe_tile(t_character *charac, t_tile *tile);
void		sd_vision_d(t_character *charac, t_tile *tile);
fptr		get_the_right_fnct(char *str);
t_tile		*find_player(int fd, t_tile *root, server_t *serv);
t_character	*find_player_c(int fd, t_tile *root, server_t *serv);
int		list_len(client_t *clt);
int		find_in_team(server_t *serv);

#endif
