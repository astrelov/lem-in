/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:31:02 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:04:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static t_room	*find_room(t_room *room, char *name)
{
	while (room && ft_strcmp(room->room_name, name))
		room = room->next;
	return room; // can be NULL if not found
}

static void	paste_link(t_room *dst_node, t_room *tolink, int nodes_amount)
{
	t_room	**nearby_rooms;

//	printf("PASTE_LINK: node1: %p, node2: %p\n", dst_node, tolink);
	if (!dst_node->nearby_rooms)
	{
//		printf("MALLOCING NEARBY NODES: name: |%s|, bytes: %zu\n", dst_node->room_name, (nodes_amount + 1) * sizeof(t_room *));
		dst_node->nearby_rooms = (t_room **)ft_memalloc((nodes_amount + 1) * sizeof(t_room *));
	}
	nearby_rooms = dst_node->nearby_rooms;
	while (*nearby_rooms && *nearby_rooms != tolink)
		nearby_rooms += 1;
	*nearby_rooms = tolink;
}

int 	count_rooms(t_room *room)
{
	int 		rooms_amount;

	rooms_amount = 1;
	while (room->next)
	{
		rooms_amount += 1;
		room = room->next;
	}
	return rooms_amount;
}

void 	add_rooms_link(t_room *first_room, char *line)
{
	t_room	*room1;
	t_room	*room2;
	int 	nodes_amount;
	char 	*node_name1 = get_room_name(line, 0, '-');
	char 	*node_name2 = get_room_name(line, 1, '-');

	nodes_amount = count_rooms(first_room);
	room1 = find_room(first_room, node_name1);
	room2 = find_room(first_room, node_name2);
//	printf("%p, %p, %p\n", *first_room, room1, room2);
	if (!room1 || !room2)
		error();
//	printf("ADD_ROOMS_LINK: room1: %p, room2: %p\n", room1, room2);
	paste_link(room1, room2, nodes_amount);
	paste_link(room2, room1, nodes_amount);
}
