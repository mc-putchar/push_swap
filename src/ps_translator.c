/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_translator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:06:20 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 05:22:26 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** op 0-2, 9 on stack a
** op 3-5, 10 on stack b
** op 6-8 on both stacks
** op % 3 = 0: swap
** op % 3 = 1: rotate
** op % 3 = 2: reverse rotate
** op 9 / 10: push [b->a] / [a->b]
*/
void	do_op(t_roll **a, t_roll **b, int op)
{
	static const t_roll_op	ops[] = {[0] = &roll_swap, [1] = &roll_rotate, \
	[2] = &roll_rev_rotate};

	if (op < 0 || op > 10)
		return ;
	if (op < 3)
	{
		if (ops[op](a) || !ft_printf("%s\n", g_ops_name[op]))
			exit(EXIT_FAILURE);
	}
	else if (op < 6)
	{
		if (ops[op - 3](b) || !ft_printf("%s\n", g_ops_name[op]))
			exit(EXIT_FAILURE);
	}
	else if (op < 9)
	{
		if (ops[op - 6](a) || ops[op - 6](b) || \
		ft_printf("%s\n", g_ops_name[op]))
			exit(EXIT_FAILURE);
	}
	else
		ops_pushes(a, b, op);
}

void	ops_pushes(t_roll **a, t_roll **b, int op)
{
	if (op == 9)
	{
		if (roll_push(a, roll_pop(b)) || !ft_printf("%s\n", g_ops_name[op]))
			exit(EXIT_FAILURE);
	}
	else if (op == 10)
	{
		if (roll_push(b, roll_pop(a)) || !ft_printf("%s\n", g_ops_name[op]))
			exit(EXIT_FAILURE);
	}
}
