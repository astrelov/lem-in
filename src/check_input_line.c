/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:53:08 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/20 15:43:07 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_ant_amount(const char *line)
{
	int		nbr;
	char	*nbr_str;
	int		equal;

	equal = FALSE;
	nbr = ft_atoi(line);
	if (nbr >= 0)
	{
		nbr_str = ft_itoa(nbr);
		equal = ft_strequ(nbr_str, line);
		ft_strdel(&nbr_str);
	}
	return (equal);
}

static int	check_for_coord(char *line)
{
	int		nbr;
	char	*nbrstr;
	int		equal;

	nbr = ft_atoi(line);
	nbrstr = ft_itoa(nbr);
	equal = ft_strequ(nbrstr, line);
	ft_strdel(&nbrstr);
	return (equal);
}

static int	check_new_node(const char *line)
{
	char	**split;
	int		isx;
	int		isy;

	isx = FALSE;
	isy = FALSE;
	split = ft_strsplit(line, ' ');
	if (count_splits(split) == 3)
	{
		isx = check_for_coord(split[1]);
		isy = check_for_coord(split[2]);
	}
	free_string_arr(split);
	return (isx && isy);
}

static int	check_nodes_link(const char *line)
{
	char	**split;
	int		splits_amount;

	split = ft_strsplit(line, '-');
	splits_amount = count_splits(split);
	free_string_arr(split);
	return (splits_amount == 2);
}

int			check_input_line(char *line)
{
	if (*line == 'L' || *line == '-' || *line == ' ')
		return (INVALID);
	if (ft_strequ(line, "##start"))
		return (START);
	if (ft_strequ(line, "##end"))
		return (END);
	if (*line == '#')
		return (COMMENT);
	if (check_ant_amount(line))
		return (ANTS_AMOUNT);
	if (check_new_node(line))
		return (NEW_ROOM);
	if (check_nodes_link(line))
		return (ROOMS_LINK);
	return (INVALID);
}
