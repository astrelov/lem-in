/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:55:43 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:40:04 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../../libft.h"

int		parse_width(char **format, va_list va, t_pf *arg)
{
	int		w;
	int		found;

	found = 0;
	while (1)
	{
		if (ft_isdigit(**format))
		{
			found = 1;
			arg->width = parse_atoi(format);
		}
		else if (**format == '*')
		{
			found = 1;
			if ((w = va_arg(va, int)) < 0)
			{
				arg->flags |= FLAG_MINUS;
				arg->width = (unsigned int)-w;
			}
			else
				arg->width = (unsigned int)w;
			(*format)++;
		}
		else
			break ;
	}
	return (found);
}
