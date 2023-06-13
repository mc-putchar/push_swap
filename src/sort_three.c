/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:05:39 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/13 22:16:39 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_roll **stack_a)
{
	t_roll	*tmp;

	tmp = *stack_a;
	if (tmp->value > tmp->next->value)
		do_op(&tmp, NULL, SA);
	*stack_a = tmp;
}

void	sort_three(t_roll **stack_a)
{
	t_roll	*tmp;

	tmp = *stack_a;
	while (is_sorted(tmp))
	{
		if (tmp->value < tmp->next->value)
		{
			if (tmp->value > tmp->prev->value)
				do_op(&tmp, NULL, RRA);
			else
				do_op(&tmp, NULL, SA);
		}
		else if (tmp->value < tmp->prev->value)
			do_op(&tmp, NULL, SA);
		else if (tmp->next->value < tmp->prev->value)
			do_op(&tmp, NULL, RA);
		else
			do_op(&tmp, NULL, SA);
	}
	*stack_a = tmp;
}

void	sort_four(t_roll **a)
{
	t_roll	*b;
	t_roll	*tmp;
	t_range	*r;

	r = get_roll_range(*a);
	if (!r)
		return ;
	b = NULL;
	realign(a, &b, r);
	tmp = *a;
	do_op(&tmp, &b, PB);
	*a = tmp;
	sort_three(a);
	do_op(a, &b, PA);
}
