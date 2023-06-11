/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:45:09 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 17:08:58 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	*spin_to_max(t_roll *roll, int max)
{
	t_roll	*ptr;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = 0;
	cost->rcost = 0;
	ptr = roll;
	while (ptr->value != max)
	{
		ptr = ptr->prev;
		cost->cost++;
	}
	ptr = roll;
	while (ptr->value != max)
	{
		ptr = ptr->next;
		cost->rcost++;
	}
	return (cost);
}

t_cost	*spin_to_min(t_roll *roll, int min)
{
	t_roll	*ptr;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = 0;
	cost->rcost = 0;
	ptr = roll;
	while (ptr->value != min)
	{
		ptr = ptr->next;
		cost->cost++;
	}
	ptr = roll;
	while (ptr->value != min)
	{
		ptr = ptr->prev;
		cost->rcost++;
	}
	return (cost);
}

t_cost	*spin_to_lower(t_roll *roll, int val)
{
	t_roll	*ptr;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = 0;
	cost->rcost = 0;
	ptr = roll;
	while (ptr->value > val || ptr->prev->value < val)
	{
		ptr = ptr->prev;
		cost->cost++;
	}
	ptr = roll;
	while (ptr->value > val || ptr->prev->value < val)
	{
		ptr = ptr->next;
		cost->rcost++;
	}
	return (cost);
}

t_cost	*spin_to_higher(t_roll *roll, int val)
{
	t_roll	*ptr;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = 0;
	cost->rcost = 0;
	ptr = roll;
	while (ptr->value < val || ptr->prev->value > val)
	{
		ptr = ptr->next;
		cost->cost++;
	}
	ptr = roll;
	while (ptr->value < val || ptr->prev->value > val)
	{
		ptr = ptr->prev;
		cost->rcost++;
	}
	return (cost);
}

t_cost	*spin_to_value(t_roll *roll, int val)
{
	t_roll	*ptr;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = 0;
	cost->rcost = 0;
	ptr = roll;
	while (ptr->value != val)
	{
		ptr = ptr->prev;
		cost->cost++;
	}
	ptr = roll;
	while (ptr->value != val)
	{
		ptr = ptr->next;
		cost->rcost++;
	}
	return (cost);
}
