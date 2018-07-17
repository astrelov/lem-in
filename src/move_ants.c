/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:34:57 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:02:44 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	move_ant(t_room *moves, t_ant *ant)
{
	ant->curr_room->ants_in_room -= 1;
	while (moves->next)
		moves = moves->next;
	printf("L%d-%s ", ant->ant_number, moves->room_name);
	ant->curr_room = moves;
	ant->curr_room->ants_in_room += 1;
	if (ant->curr_room->bool_end_room)
		ant->finished = 1;
}

int 	already_in_moves(t_room *moves, t_room *node_to_find)
{
//	moves = moves->next;
	while (moves)
	{
		if (moves == node_to_find)
			return 1;
		moves = moves->next;
	}
	return 0;
}

int 	find_route(t_room *moves, t_room *path_node, t_room *ant_node, int recur_depth)
{
	t_room	*last_move;
	t_room	**nearby_nodes = path_node->nearby_rooms;
	int 	ind;

	if (!recur_depth)
		return 0;
	ind = -1;
	while (nearby_nodes[++ind])
	{
		last_move = moves;
		while (last_move->next)
			last_move = last_move->next;
		if (nearby_nodes[ind] == ant_node && (last_move->bool_end_room || last_move->ants_in_room == 0))
			return 1;
		if (already_in_moves(moves, nearby_nodes[ind]))
			continue;
		if (nearby_nodes[ind] != ant_node)
		{
			lst_push(nearby_nodes[ind], moves);
			if (find_route(moves, nearby_nodes[ind], ant_node, recur_depth - 1))
				return 1;
			lst_pop(moves);
		}
	}
	return 0;
}

void	move_ants(t_room *end_room, t_ant **ants, int ants_amount, int rooms_amount)
{
//	puts("MOVE_ANTS");
	int 		ant;
	int 		found;
	int 		recur_depth;

	while (end_room->ants_in_room < ants_amount)
	{
		ant = -1;
//		printf("ANTS AT END NODE: %d\n", end_room->ants_in_room);
		while (++ant < ants_amount)
		{
			if (ants[ant]->finished)
				continue;
//			printf("MOVE_ANTS WHILE: ant#%d\n", ant + 1);
			found = 0;
			recur_depth = 1;
			end_room->next = NULL;
			while (!found && recur_depth < rooms_amount)
				found = find_route(end_room, end_room, ants[ant]->curr_room, recur_depth++);
			if (found)
				move_ant(end_room, ants[ant]);
		}
		puts("");
	}
}
