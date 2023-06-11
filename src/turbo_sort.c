/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:41:37 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 17:16:05 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opposite_run(t_roll **a, t_roll **b, t_cheap *c)
{
	int	i;

	i = ft_abs(c->ai);
	while (i--)
	{
		if (c->ai > 0)
			do_op(a, b, RRA);
		else
			do_op(a, b, RA);
	}
	i = ft_abs(c->bi);
	while (i--)
	{
		if (c->bi > 0)
			do_op(a, b, RRB);
		else
			do_op(a, b, RB);
	}
	do_op(a, b, PB);
}

void	twin_boost(t_roll **a, t_roll **b, t_cheap *c)
{
	int	i;

	i = ft_abs(c->ci);
	if (c->ci > 0)
		while (i--)
			do_op(a, b, RRR);
	else
		while (i--)
			do_op(a, b, RR);
	i = c->ti - ft_abs(c->ci);
	c->ai -= c->ci;
	c->bi -= c->ci;
}

void	spoolup(t_roll **a, t_roll **b, t_cheap *c)
{
	if (c->dir)
		twin_boost(a, b, c);
	if (c->dir == 1)
	{
		while (c->ai--)
			do_op(a, b, RRA);
		while (c->bi--)
			do_op(a, b, RRB);
		do_op(a, b, PB);
	}
	else if (c->dir == -1)
	{
		while (c->ai++)
			do_op(a, b, RA);
		while (c->bi++)
			do_op(a, b, RB);
		do_op(a, b, PB);
	}
	else if (!c->dir)
		opposite_run(a, b, c);
	free(c);
}

void	unspool(t_roll **a, t_roll **b, t_range *r)
{
	t_cost	*cost;
	int		c;
	int		op;

	while (roll_size(*b))
	{
		cost = pushback_cost(*a, (*b)->value, r);
		if (!cost)
			return ;
		c = lower_of(cost->cost, cost->rcost);
		if (c == cost->cost)
			op = RA;
		else
			op = RRA;
		while (c--)
			do_op(a, b, op);
		do_op(a, b, PA);
		update_range(r, (*a)->value);
		free(cost);
	}
	cost = spin_to_min(*a, r->min);
	free(r);
	if (cost && cost->cost < cost->rcost)
		while (cost->cost--)
			do_op(a, b, RA);
	else if (cost)
		while (cost->rcost--)
			do_op(a, b, RRA);
	free(cost);
}

int	turbo_sort(t_roll **a)
{
	t_roll	*b;
	t_range	*r;
	t_cheap	*next;
	int		i;

	b = NULL;
	do_op(a, &b, PB);
	do_op(a, &b, PB);
	r = get_roll_range(b);
	if (!r)
		return (EXIT_FAILURE);
	i = 3;
	while (roll_size(*a) > 3)
	{
		next = find_cheapest(*a, b, r);
		if (!next)
			return (free(r), destroy_roll(&b), EXIT_FAILURE);
		spoolup(a, &b, next);
		update_range(r, b->value);
	}
	free(r);
	sort_three(a);
	r = get_roll_range(*a);
	unspool(a, &b, r);
	return (EXIT_SUCCESS);
}
