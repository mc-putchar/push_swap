/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:09:47 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 21:48:51 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_roll.h"

int	roll_rotate(t_roll **roll)
{
	if (!roll || !*roll)
		return (1);
	*roll = (*roll)->next;
	return (0);
}

int	roll_rev_rotate(t_roll **roll)
{
	if (!roll || !*roll)
		return (1);
	*roll = (*roll)->prev;
	return (0);
}

int	roll_swap(t_roll **roll)
{
	t_roll	*first;
	t_roll	*second;

	if (!roll || !*roll || !(*roll)->next)
		return (1);
	first = *roll;
	second = (*roll)->next;
	if (first->prev == second)
	{
		*roll = second;
		return (0);
	}
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;
	*roll = second;
	return (0);
}
