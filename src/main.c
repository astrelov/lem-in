/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:25:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/08/04 13:45:44 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
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
	ft_printf("%d\n", ants_amount);
	print_rooms(room);
	print_links(room);
	move_ants(end_room, ants, ants_amount, rooms_amount);
	free_rooms(room);
	free_ants(ants);
	return (0);
}
