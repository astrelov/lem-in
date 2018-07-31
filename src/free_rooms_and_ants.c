/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms_and_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:21:09 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/31 16:21:09 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_rooms(t_room *room)
{
	if (room->next_input_room)
		free_rooms(room->next_input_room);
	ft_memdel((void **)&room->ystr);
	ft_memdel((void **)&room->xstr);
	ft_memdel((void **)&room->room_name);
	if (room->nearby_rooms)
		ft_memdel((void **)&room->nearby_rooms);
	ft_memdel((void **)&room);
}

void	free_ants(t_ant **ants)
{
	int i;

	i = 0;
	while (*ants)
	{
		free(*ants++);
		i++;
	}
	free(ants - i);
}
