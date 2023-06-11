/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:05:39 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 13:26:41 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_roll **stack_a)
{
	t_roll	*tmp;

	if (roll_size(*stack_a) > 3 && ft_printf("Error\n"))
		return ;
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
