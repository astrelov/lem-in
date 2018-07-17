/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:10:14 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:14:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant	**init_ants(t_room *room)
{
	int		ant_nbr;
	t_ant	**ants;

	while (!room->bool_start_room)
		room = room->next;
	ants = (t_ant **)ft_memalloc(sizeof(t_ant *) * (room->ants_in_room + 1));
	ant_nbr = 0;
	while (++ant_nbr <= room->ants_in_room)
	{
		ants[ant_nbr - 1] = (t_ant *)ft_memalloc(sizeof(t_ant));
		ants[ant_nbr - 1]->ant_number = ant_nbr;
		ants[ant_nbr - 1]->curr_room = room;
	}
	return ants;
}
