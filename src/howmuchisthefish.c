/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howmuchisthefish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:03:33 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 13:40:06 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** if val is the new min or max push it on top of current max in b
** else find the closest value smaller than val and push on top of it
** return the number of the operations 
*/
int	insert_cost(t_roll *b, int val, t_range *r)
{
	if (val < r->min || val > r->max)
		return (spin_to_max(b, r->max));
	return (spin_to_lower(b, val));
}

// Calculate cost to push back a value into proper position in a
int	pushback_cost(t_roll *a, int val, t_range *r)
{
	if (val < r->min || val > r->max)
		return (spin_to_min(a, r->min));
	return (spin_to_higher(a, val));
}

// Calculate cost to rotate to value in a and push it to right position in b
t_cheap	*lowest_cost(t_roll *a, t_roll *b, t_range *r, int val)
{
	t_cheap	*cost;

	cost = malloc(sizeof(t_cheap));
	if (!cost)
		return (NULL);
	cost->ai = spin_to_value(a, val);
	cost->bi = insert_cost(b, val, r);
	if (cost->ai < 0 && cost->bi < 0)
	{
		cost->ci = greater_of(cost->ai, cost->bi);
		cost->dir = -1;
	}
	else if (cost->ai > 0 && cost->bi > 0)
	{
		cost->ci = lower_of(cost->ai, cost->bi);
		cost->dir = 1;
	}
	else
	{
		cost->ci = ft_abs(cost->ai) + ft_abs(cost->bi);
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
		if (!cheapest || cost->ci < cheapest->ci)
		{
			free(cheapest);
			cheapest = cost;
			cheapest->i = i;
		}
		else
			free(cost);
		i++;
	}
	return (cheapest);
}
