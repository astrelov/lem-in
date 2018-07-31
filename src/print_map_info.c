/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:17:47 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/31 16:20:39 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_rooms(t_room *room)
{
	while (room)
	{
		if (room->bool_start_room)
			ft_putendl("##start");
		if (room->bool_end_room)
			ft_putendl("##end");
		ft_printf("%s %s %s\n", room->room_name, room->xstr, room->ystr);
		room = room->next_input_room;
	}
}

void	print_links(t_room *room)
{
	int		rooms_amount;
	int		i;

	rooms_amount = count_rooms(room);
	while (room)
	{
		i = 0;
		while (i++ < rooms_amount)
			if (room->nearby_rooms && room->nearby_rooms[i])
				ft_printf("%s-%s\n", room->room_name,
						room->nearby_rooms[i]->room_name);
		room = room->next_input_room;
	}
	ft_putendl("");
}
