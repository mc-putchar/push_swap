/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/13 22:16:57 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_roll *stack_a)
{
	t_roll	*tmp;

	ft_printf("%d\n", stack_a->value);
	tmp = stack_a->next;
	while (tmp != stack_a)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	init_stack(char **tab, t_roll **stack_a)
{
	t_roll	*node;
	int		i;

	if (!tab || !*tab)
		return (EXIT_FAILURE);
	i = 0;
	while (tab[i])
		++i;
	while (i--)
	{
		node = roll_new(ft_atoi(tab[i]));
		if (!node)
			return (destroy_roll(stack_a), EXIT_FAILURE);
		roll_push(stack_a, node);
	}
	return (EXIT_SUCCESS);
}

void	push_swap(t_roll *stack_a)
{
	int		i;

	i = roll_size(stack_a);
	if (i == 2)
		sort_two(&stack_a);
	else if (i == 3)
		sort_three(&stack_a);
	else if (i == 4)
		sort_four(&stack_a);
	else if (turbo_sort(&stack_a))
		error_handler(&destroy_roll, &stack_a);
	destroy_roll(&stack_a);
}
