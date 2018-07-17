/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:06:39 by null              #+#    #+#             */
/*   Updated: 2018/07/17 23:26:23 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	handle_line(int line_type, char *line, t_room **first_room, int *ants_amount)
{
	if (line_type == ANTS_AMOUNT && !g_got_ants_amount && !g_next_room_type)
	{
		g_got_ants_amount = 1;
		*ants_amount = ft_atoi(line);
	}
	else if (line_type == COMMENT && !g_next_room_type)
		;
	else if (line_type == NEW_ROOM && !g_got_rooms_link && g_got_ants_amount)
		add_room(first_room, line, *ants_amount);
	else if (line_type == ROOMS_LINK && !g_next_room_type)
	{
		g_got_rooms_link = 1;
		add_rooms_link(*first_room, line);
	}
	else if (line_type == START || line_type == END)
		g_next_room_type = line_type;
	else
		error();
}

void	init_rooms(int *ants_amount, t_room **first_room)
{
	char			*line;
	int 			line_type;

	g_got_ants_amount = 0;
	g_got_rooms_link = 0;
	g_next_room_type = 0;
	while (ft_gnl(0, &line))
	{
		line_type = check_input_line(line);
		handle_line(line_type, line, first_room, ants_amount);
		free(line);
	}
	free(line);
}
