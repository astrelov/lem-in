/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:28:00 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/02 13:28:01 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long	num;
	short			isneg;

	isneg = 1;
	num = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			isneg = -1;
	while (*str > 47 && *str < 58)
		num = num * 10 + *str++ - '0';
	if (num > 9223372036854775807 && isneg < 0)
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	return ((int)(num * isneg));
}
