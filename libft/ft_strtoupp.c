/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:34:07 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/20 15:34:29 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtoupp(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		*str = (char)ft_toupper(*str);
		str++;
	}
}
