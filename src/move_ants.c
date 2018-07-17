/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:34:57 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 21:44:25 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	move_ant(t_room *moves, t_ant *ant)
{
	ant->curr_room->ants_in_room -= 1;
	while (moves->next_move)
		moves = moves->next_move;
	printf("L%d-%s ", ant->ant_number, moves->room_name);
	ant->curr_room = moves;
	ant->curr_room->ants_in_room += 1;
	if (ant->curr_room->bool_end_room)
		ant->finished = 1;
}

int 	already_in_moves(t_room *moves, t_room *room_to_find)
{
	while (moves)
	{
		if (moves == room_to_find)
			return (TRUE);
		moves = moves->next_move;
	}
	return (FALSE);
}

int 	find_route(t_room *moves, t_room *path_room,
							t_room *ant_node, int search_depth)
{
	int 	i;

	if (!search_depth)
		return (FALSE);
	i = -1;
	while (path_room->nearby_rooms && path_room->nearby_rooms[++i])
	{
		if (already_in_moves(moves, path_room->nearby_rooms[i]))
			continue;
		if (path_room->nearby_rooms[i] == ant_node &&
						(path_room->bool_end_room || !path_room->ants_in_room))
			return (TRUE);
		if (path_room->nearby_rooms[i] != ant_node)
		{
			lst_push(path_room->nearby_rooms[i], moves);
			if (find_route(moves, path_room->nearby_rooms[i],
								ant_node, search_depth - 1))
				return (TRUE);
			lst_pop(moves);
		}
	}
	return (FALSE);
}

void	move_ants(t_room *end_room, t_ant **ants, int ants_amount,
							int rooms_amount)
{
	int 		ant_ind;
	int 		found;
	int 		search_depth;

	ant_ind = -1;
	while (++ant_ind < ants_amount)
	{
		if (ants[ant_ind]->finished)
			continue;
		found = FALSE;
		search_depth = 1;
		end_room->next_move = NULL;
		while (!found && search_depth < rooms_amount)
			found = find_route(end_room, end_room, ants[ant_ind]->curr_room,
															search_depth++);
		if (found)
			move_ant(end_room, ants[ant_ind]);
	}
	puts("");
	if (end_room->ants_in_room < ants_amount)
		move_ants(end_room, ants, ants_amount, rooms_amount);
}
