/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:10:14 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 20:15:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant	**init_ants(t_room *room)
{
	t_ant	**ants;
	int		i;

	while (!room->bool_start_room)
		room = room->next_input_room;
	ants = (t_ant **)ft_memalloc(sizeof(t_ant *) * (room->ants_in_room + 1));
	i = 0;
	while (i < room->ants_in_room)
	{
		ants[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		ants[i]->ant_number = i + 1;
		ants[i]->curr_room = room;
		i++;
	}
	return (ants);
}
