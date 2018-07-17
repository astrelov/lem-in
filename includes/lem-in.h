/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:28:47 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:14:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
# include "../libft/libft.h"

# define FALSE				0
# define TRUE				1

# define INVALID			0
# define START				1
# define END				2
# define COMMENT			3
# define NEW_ROOM			4
# define ROOMS_LINK			5
# define ANTS_AMOUNT		6

int 						g_got_ants_amount;
int 						g_got_rooms_link;
int 						g_next_room_type;

typedef struct				s_room
{
	char 					*room_name;
	char 					*xstr;
	char 					*ystr;
	int						ants_in_room;
	int						bool_start_room;
	int						bool_end_room;
	struct s_room			**nearby_rooms;
	struct s_room			*next;
}							t_room;

typedef struct 				s_ant
{
	int						ant_number;
	int 					finished;
	t_room 					*curr_room;
}							t_ant;

void						init_rooms(int *ants_amount, t_room **first_room);
t_ant						**init_ants(t_room *room);
int 						check_input_line(char *line);
void						add_room(t_room **first_room, char *line, int ants_amount);
void 						add_rooms_link(t_room *first_room, char *line);
void						move_ants(t_room *end_room, t_ant **ants, int ants_amount, int rooms_amount);
int 						count_rooms(t_room *room);
void						lst_push(t_room *el, t_room *lst);
void						lst_pop(t_room *lst);

void						free_string_arr(char **str);
char						*get_room_name(char *line, int pos, char split_by);
void						error();

void		print_list(t_room *room);
void		print_ants(t_ant **ants);
void		print_room(t_room *list);


#endif
