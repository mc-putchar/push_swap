/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howmuchisthefish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:03:33 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 18:13:48 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** if val is the new min or max push it on top of current max in b
** else find the closest value smaller than val and push on top of it
** return the number of the operations 
*/
t_cost	*insert_cost(t_roll *b, int val, t_range *r)
{
	if (val < r->min || val > r->max)
		return (spin_to_max(b, r->max));
	return (spin_to_lower(b, val));
}

// Calculate cost to push back a value into proper position in a
t_cost	*pushback_cost(t_roll *a, int val, t_range *r)
{
	if (val < r->min || val > r->max)
		return (spin_to_min(a, r->min));
	return (spin_to_higher(a, val));
}

int	get_best_combo(t_cost *c1, t_cost *c2, int *a, int *b)
{
	if (!c1 || !c2)
		return (EXIT_FAILURE);
	if (greater_of(c1->cost, c2->cost) < greater_of(c1->rcost, c2->rcost))
	{
		*a = c1->cost;
		*b = c2->cost;
	}
	else
	{
		*a = c1->rcost * -1;
		*b = c2->rcost * -1;
	}
	if (c1->cost + c2->rcost < greater_of(ft_abs(*a), ft_abs(*b)))
	{
		*a = c1->cost;
		*b = c2->rcost * -1;
	}
	if (c1->rcost + c2->cost < greater_of(ft_abs(*a), ft_abs(*b)))
	{
		*a = c1->rcost * -1;
		*b = c2->cost;
	}
	free(c1);
	free(c2);
	return (EXIT_SUCCESS);
}

// Calculate cost to rotate to value in a and push it to right position in b
t_cheap	*lowest_cost(t_roll *a, t_roll *b, t_range *r, int val)
{
	t_cheap	*cost;

	cost = malloc(sizeof(t_cheap));
	if (!cost || get_best_combo(spin_to_value(a, val), \
	insert_cost(b, val, r), &cost->ai, &cost->bi))
		return (NULL);
	if (cost->ai < 0 && cost->bi < 0)
	{
		cost->ci = greater_of(cost->ai, cost->bi);
		cost->ti = ft_abs(lower_of(cost->ai, cost->bi));
		cost->dir = -1;
	}
	else if (cost->ai > 0 && cost->bi > 0)
	{
		cost->ci = lower_of(cost->ai, cost->bi);
		cost->ti = greater_of(cost->ai, cost->bi);
		cost->dir = 1;
	}
	else
	{
		cost->ti = ft_abs(cost->ai) + ft_abs(cost->bi);
		cost->dir = 0;
	}
	return (cost);
}

t_cheap	*find_cheapest(t_roll *a, t_roll *b, t_range *r)
{
	t_cheap	*cheapest;
	t_cheap	*cost;
	int		i;
	int		size;

	cheapest = NULL;
	i = 0;
	size = roll_size(a);
	while (i < size)
	{
		cost = lowest_cost(a, b, r, get_roll_at(a, i));
		if (!cost)
			return (NULL);
		if (!cheapest || cost->ti < cheapest->ti)
		{
			free(cheapest);
			cheapest = cost;
		}
		else
			free(cost);
		if (cheapest->ti < i + 2)
			break ;
		i++;
	}
	return (cheapest);
}
