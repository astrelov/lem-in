/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:29:41 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/24 21:45:33 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	lst_push(t_room *el, t_room *lst)
{
	while(lst->next_move)
		lst = lst->next_move;
	lst->next_move = el;
	el->next_move = NULL;
}

void	lst_pop(t_room *lst)
{
	if (!lst->next_move)
		return ;
	while (lst->next_move->next_move)
		lst = lst->next_move;
	lst->next_move = NULL;
}
