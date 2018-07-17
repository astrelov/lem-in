/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:34:31 by null              #+#    #+#             */
/*   Updated: 2018/07/17 19:56:54 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	error()
{
	ft_errmsg("ERROR\n");
	exit(0);
}

int 	count_rooms(t_room *room)
{
	int 		rooms_amount;

	rooms_amount = 0;
	while (room)
	{
		rooms_amount++;
		room = room->next_input_room;
	}
	return (rooms_amount);
}

char	*get_split_str_part(char *line, int pos, char split_by)
{
	char 	*name;
	char 	**split;

	split = ft_strsplit(line, split_by);
	name = ft_strdup(split[pos]);
	free_string_arr(split);
	return (name);
}

int 		count_splits(char **split)
{
	int 	amount;

	amount = 0;
	while (*split++)
		amount++;
	return (amount);
}

void	free_string_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_strdel(&str[i++]);
	free(str);
}
