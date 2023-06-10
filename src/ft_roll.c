/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:26:45 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 16:10:37 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_roll.h"

t_roll	*roll_new(int value)
{
	t_roll	*new;

	new = malloc(sizeof(t_roll));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

int	roll_push(t_roll **roll, t_roll *slice)
{
	if (!slice)
		return (1);
	if (!roll)
		roll = malloc(sizeof(t_roll *));
	if (!roll)
		return (1);
	if (!*roll)
	{
		slice->prev = slice;
		slice->next = slice;
		*roll = slice;
		return (0);
	}
	slice->next = *roll;
	slice->prev = (*roll)->prev;
	(*roll)->prev->next = slice;
	(*roll)->prev = slice;
	*roll = slice;
	return (0);
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

void	destroy_roll(t_roll **roll)
{
	t_roll	*tmp;

	if (!roll)
		return ;
	while (*roll)
	{
		tmp = roll_pop(roll);
		free(tmp);
	}
}
