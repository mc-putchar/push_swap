/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:26:45 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/13 22:12:31 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_roll.h"

int	roll_size(t_roll *roll)
{
	int		i;
	t_roll	*start;

	if (!roll)
		return (0);
	i = 1;
	start = roll->next;
	while (start != roll)
	{
		++i;
		start = start->next;
	}
	return (i);
}

t_roll	*roll_new(int value)
{
	t_roll	*new;

	new = malloc(sizeof(t_roll));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
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

int	get_roll_at(t_roll *roll, int index)
{
	int		i;

	if (!roll)
		return (0);
	i = 0;
	while (i++ < index)
		roll = roll->next;
	return (roll->value);
}

t_roll	**roll_copy(t_roll *roll)
{
	t_roll	**copy;
	t_roll	*start;

	if (!roll)
		return (NULL);
	copy = malloc(sizeof(t_roll *) * roll_size(roll));
	if (!copy)
		return (NULL);
	start = roll->prev;
	while (start != roll)
	{
		if (roll_push(copy, roll_new(start->value)))
			return (destroy_roll(copy), NULL);
		start = start->prev;
	}
	if (roll_push(copy, roll_new(start->value)))
		return (destroy_roll(copy), NULL);
	return (copy);
}
