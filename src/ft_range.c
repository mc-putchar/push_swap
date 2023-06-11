/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:59:31 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 08:12:08 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_of(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	lower_of(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	update_range(t_range *r, int val)
{
	if (val < r->min)
		r->min = val;
	if (val > r->max)
		r->max = val;
}

t_range	*get_roll_range(t_roll *b)
{
	t_roll	*tmp;
	t_range	*r;

	r = malloc(sizeof(t_range));
	if (!r)
		return (NULL);
	tmp = b->next;
	r->min = b->value;
	r->max = b->value;
	while (tmp != b)
	{
		if (tmp->value < r->min)
			r->min = tmp->value;
		if (tmp->value > r->max)
			r->max = tmp->value;
		tmp = tmp->next;
	}
	return (r);
}
