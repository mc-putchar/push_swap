/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:09:47 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/13 18:51:13 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_roll.h"

int	roll_rotate(t_roll **roll)
{
	if (!roll || !*roll)
		return (EXIT_FAILURE);
	*roll = (*roll)->next;
	return (EXIT_SUCCESS);
}

int	roll_rev_rotate(t_roll **roll)
{
	if (!roll || !*roll)
		return (EXIT_FAILURE);
	*roll = (*roll)->prev;
	return (EXIT_SUCCESS);
}

int	roll_swap(t_roll **roll)
{
	t_roll	*first;
	t_roll	*second;

	if (!roll || !*roll || !(*roll)->next)
		return (EXIT_FAILURE);
	first = *roll;
	second = (*roll)->next;
	if (first->prev == second)
	{
		*roll = second;
		return (EXIT_SUCCESS);
	}
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;
	*roll = second;
	return (EXIT_SUCCESS);
}

int	roll_push(t_roll **roll, t_roll *slice)
{
	if (!slice)
		return (EXIT_FAILURE);
	if (!roll)
		roll = malloc(sizeof(t_roll *));
	if (!roll)
		return (EXIT_FAILURE);
	if (!*roll)
	{
		slice->prev = slice;
		slice->next = slice;
		*roll = slice;
		return (EXIT_SUCCESS);
	}
	slice->next = *roll;
	slice->prev = (*roll)->prev;
	(*roll)->prev->next = slice;
	(*roll)->prev = slice;
	*roll = slice;
	return (EXIT_SUCCESS);
}

t_roll	*roll_pop(t_roll **roll)
{
	t_roll	*slice;

	if (!roll || !*roll)
		return (NULL);
	slice = *roll;
	if (slice->next == slice)
	{
		*roll = NULL;
		return (slice);
	}
	slice->prev->next = slice->next;
	slice->next->prev = slice->prev;
	*roll = slice->next;
	return (slice);
}
