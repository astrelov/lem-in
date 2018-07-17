/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:25:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:12:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	error()
{
	ft_errmsg("ERROR\n");
	exit(0);
}

void	print_rooms(t_room *room)
{
	while (room) {
		printf("room: |%s| %s %s\n", room->room_name, room->xstr, room->ystr);
		room = room->next;
	}
}

void	print_links(t_room *room)
{
	int 	rooms_amount;

	rooms_amount = count_rooms(room);
	while (room)
	{
		for (int i = 0; i < rooms_amount; i++) {
			if  (room->nearby_rooms[i])
				printf("link: |%s| - |%s|\n", room->room_name, room->nearby_rooms[i]->room_name);
		}
		room = room->next;
	}
	ft_putendl("");
}

int					main()
{
	int				ants_amount;
	int				nodes_amount;
	t_ant			**ants;
	t_room			*rooms;

	rooms = NULL;
	init_rooms(&ants_amount, &rooms);
	printf("ants %d\n", ants_amount);
//	print_list(rooms);
	print_rooms(rooms);
	print_links(rooms);
	ants = init_ants(rooms);

//	print_ants(ants); print_list(rooms);

	nodes_amount = count_rooms(rooms);
//	printf("nodes_amount = %d\n", nodes_amount);
	while (!rooms->bool_end_room)
		rooms = rooms->next;
	move_ants(rooms, ants, ants_amount, nodes_amount);
}
