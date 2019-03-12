/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** include for client
*/

#pragma once

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <sys/signalfd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

extern const int n_linemate;
extern const int n_deraumere;
extern const int n_sibur;
extern const int n_mendiane;
extern const int n_phiras;
extern const int n_thystame;
extern const int n_food;
extern const int n_ritual;

extern const int r_listener;
extern const int r_caller;
extern const int r_present;

extern bool exit_error;

typedef struct	s_client
{
	int sfd;
	int efd;
	int id;
	int r_act;
	char role;
	char state;
	char level;
	char *team;
	struct epoll_event *events;
}		client_t;

typedef struct	s_list_res
{
	char *cmd;
	char *res;
	struct s_list_res *next;
}		list_res_t;

typedef struct s_message
{
	char tile;
	char action;
	int id;
	char level;
	char nb_needed;
}		message_t;

typedef struct	s_commands_res
{
	char *name;
	list_res_t *(*fct_commands)(client_t *self, list_res_t *head);
}		commands_res_t;

typedef	void (*level_t)(client_t *, char **);

extern const level_t level_tab[];

/* functions from check_error file */

int check_error(int, char **);

/* functions from client file */

bool client_initialization(char *, char *, char *);

/* functions from responses file */

bool get_responses_buffer(client_t *, list_res_t **, int);

/* functions from connect file */

int create_socket(void);
int client_binding(char *, char *, int);
bool connect_to_server(char *, char *, client_t *);

/* functions from epoll file */

bool add_fd_on_events(int, int);
bool del_fd_on_events(client_t *, int);
struct epoll_event *init_epoll(int, int *);

/* functions from list file */

list_res_t *initiate_list_res(char *);
bool add_list_cmd(list_res_t *, char *);
bool check_list_res(list_res_t *, char *);
bool add_list_res(list_res_t *, char *);
list_res_t *del_list_res(list_res_t *);
list_res_t *destroy_list_res(list_res_t *);
list_res_t *add_list_cmd_on_head(list_res_t *);
bool add_list_res_on_end(list_res_t *, char *);
bool add_list_msg(list_res_t *, char *);

/* functions for commands IA */

list_res_t *ia(client_t *, list_res_t *);
list_res_t *team_initial_res(client_t *, list_res_t *);
list_res_t *team_num_res(client_t *, list_res_t *);
list_res_t *team_map_res(client_t *, list_res_t *);
list_res_t *inventory_res(client_t *, list_res_t *);
list_res_t *take_object_res(client_t *, list_res_t *);
list_res_t *set_object_res(client_t *, list_res_t *);
list_res_t *look_res(client_t *, list_res_t *);
list_res_t *handle_ok_res(client_t *, list_res_t *);
list_res_t *ritual_res_end(client_t *, list_res_t *);
list_res_t *ritual_res_active(client_t *, list_res_t *);
list_res_t *handle_message(client_t *, list_res_t *);
list_res_t *broadcast_res(client_t *, list_res_t *);

/* functions from file inventory_res */

void update_needs_life(client_t *self, char **parsed);
void need_for_lvl_one(client_t *, char **);
void need_for_lvl_two(client_t *, char **);
void need_for_lvl_three(client_t *, char **);
void need_for_lvl_four(client_t *, char **);
void need_for_lvl_five(client_t *, char **);
void need_for_lvl_six(client_t *, char **);
void need_for_lvl_seven(client_t *, char **);

/* functions from file take_res */

list_res_t *take_object(client_t *self, list_res_t *head, char *object);

/* functions from file look_res */

bool new_command_or_not(list_res_t *, list_res_t *);
int check_multiple_obj(client_t *self, char *object);
list_res_t *need_mineral(client_t *self, list_res_t *head, char *object,
			int tile);
list_res_t *take_everything(client_t *self, list_res_t *head, char *tile);

/* functions from file action_move */

list_res_t *move_command(client_t *, list_res_t *, int);
list_res_t *move_randomly(client_t *self, list_res_t *head);
list_res_t *change_direction(client_t *self, list_res_t *head);

/* functions from request file */

list_res_t *request_cmd(int, list_res_t *, char *);
list_res_t *request_std(int, list_res_t *, char *, char *);
list_res_t *request_broadcast_call(client_t *, list_res_t *);
list_res_t *request_broadcast(client_t *, list_res_t *, int);

/* functions from ritual related files */

list_res_t *enter_ritual_state(client_t *, list_res_t *);
list_res_t *start_ritual(client_t *, list_res_t *);
list_res_t *sound_reception(client_t *, list_res_t *, int);
int players_needed_by_ritual(int);
message_t *parse_message(char *, char *);

/* functions from forking file */

list_res_t *connect_nbr_res(client_t *self, list_res_t *head);

/* functions from miscallenous files */

char *gnl(const int);
int my_strncmp(char *, char *, int);
int my_strcmp(char *, char *);
int get_quantity(char *);
char **stw(char *, char);
char **stw_look(char *, char);
int count_word(char *, char);
list_res_t *get_last_elem(list_res_t *);
int create_random_id();
void free_tab(char **);
