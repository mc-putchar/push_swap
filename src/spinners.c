/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:45:09 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 12:07:46 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	spin_to_max(t_roll *roll, int max)
{
	int		cost;
	int		rcost;
	t_roll	*ptr;

	cost = 0;
	rcost = 0;
	ptr = roll;
	while (ptr->value != max)
	{
		ptr = ptr->next;
		cost++;
	}
	ptr = roll;
	while (ptr->value != max)
	{
		ptr = ptr->prev;
		rcost++;
	}
	if (cost < rcost)
		return (cost);
	return (rcost * -1);
}

int	spin_to_min(t_roll *roll, int min)
{
	int		cost;
	int		rcost;
	t_roll	*ptr;

	cost = 0;
	rcost = 0;
	ptr = roll;
	while (ptr->value != min)
	{
		ptr = ptr->next;
		cost++;
	}
	ptr = roll;
	while (ptr->value != min)
	{
		ptr = ptr->prev;
		rcost++;
	}
	if (cost < rcost)
		return (cost);
	return (rcost * -1);
}

int	spin_to_lower(t_roll *roll, int val)
{
	int		cost;
	int		rcost;
	t_roll	*ptr;

	cost = 0;
	rcost = 0;
	ptr = roll;
	while (ptr->value > val || ptr->prev->value < val)
	{
		ptr = ptr->next;
		++cost;
	}
	ptr = roll;
	while (ptr->value > val || ptr->prev->value < val)
	{
		ptr = ptr->prev;
		++rcost;
	}
	if (cost < rcost)
		return (cost);
	return (rcost * -1);
}

int	spin_to_higher(t_roll *roll, int val)
{
	int		cost;
	int		rcost;
	t_roll	*ptr;

	cost = 0;
	rcost = 0;
	ptr = roll;
	while (ptr->value < val || ptr->prev->value > val)
	{
		ptr = ptr->next;
		++cost;
	}
	ptr = roll;
	while (ptr->value < val || ptr->prev->value > val)
	{
		ptr = ptr->prev;
		++rcost;
	}
	if (cost < rcost)
		return (cost);
	return (rcost * -1);
}

int	spin_to_value(t_roll *roll, int val)
{
	int		cost;
	int		rcost;
	t_roll	*ptr;

	cost = 0;
	rcost = 0;
	ptr = roll;
	while (ptr->value != val)
	{
		ptr = ptr->next;
		++cost;
	}
	ptr = roll;
	while (ptr->value != val)
	{
		ptr = ptr->prev;
		++rcost;
	}
	if (cost < rcost)
		return (cost);
	return (rcost * -1);
}
