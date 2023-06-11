/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spoolup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:54 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 18:11:12 by mcutura          ###   ########.fr       */
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
