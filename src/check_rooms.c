/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:20:48 by null              #+#    #+#             */
/*   Updated: 2018/07/17 21:34:54 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		check_start_end_path(t_room *end_room, t_room *prev_path_room)
{
	int 	i;

	prev_path_room->next_move = NULL;
	i = -1;
	while (prev_path_room->nearby_rooms && prev_path_room->nearby_rooms[++i])
	{
		if (already_in_moves(end_room, prev_path_room->nearby_rooms[i]))
			continue;
		if (prev_path_room->nearby_rooms[i]->bool_start_room)
			return (TRUE);
		lst_push(prev_path_room->nearby_rooms[i], end_room);
		if (check_start_end_path(end_room, prev_path_room->nearby_rooms[i]))
			return (TRUE);
		lst_pop(end_room);
	}
	return (FALSE);
}

void	check_start_end_rooms(t_room *room)
{
	int		start_found;
	int 	end_found;

	start_found = FALSE;
	end_found = FALSE;
	while (room)
	{
		if (room->bool_start_room)
		{
			if (start_found)
				error();
			start_found = TRUE;
		}
		if (room->bool_end_room)
		{
			if (end_found)
				error();
			end_found = TRUE;
		}
		room = room->next_input_room;
	}
	if (!start_found || !end_found)
		error();
}
