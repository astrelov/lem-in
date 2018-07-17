/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:25:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 21:47:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	print_rooms(t_room *room)
{
	while (room)
	{
		if (room->bool_start_room)
			ft_putendl("##start");
		if (room->bool_end_room)
			ft_putendl("##end");
		printf("%s %s %s\n", room->room_name, room->xstr, room->ystr);
		room = room->next_input_room;
	}
}

void	print_links(t_room *room)
{
	int 	rooms_amount;
	int 	i;

	rooms_amount = count_rooms(room);
	while (room)
	{
		i = 0;
		while (i++ < rooms_amount)
			if  (room->nearby_rooms && room->nearby_rooms[i])
				printf("%s-%s\n", room->room_name, room->nearby_rooms[i]->room_name);
		room = room->next_input_room;
	}
	ft_putendl("");
}

int					main()
{
	int				ants_amount;
	int				rooms_amount;
	t_ant			**ants;
	t_room			*room;
	t_room			*end_room;

	room = NULL;
	init_rooms(&ants_amount, &room);
	check_start_end_rooms(room);
	end_room = room;
	while (end_room && !end_room->bool_end_room)
		end_room = end_room->next_input_room;
	if (!check_start_end_path(end_room, end_room))
		error();
	rooms_amount = count_rooms(room);
	ants = init_ants(room);
	printf("%d\n", ants_amount);
	print_rooms(room);
	print_links(room);
	move_ants(end_room, ants, ants_amount, rooms_amount);
	return (0);
}
