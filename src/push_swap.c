/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 20:39:10 by mcutura          ###   ########.fr       */
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

int	integer_check(char **tab)
{
	int		i;
	int		j;

	i = -1;
	if (!tab)
		return (EXIT_FAILURE);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (j > 10 || (!ft_isdigit(tab[i][j]) && tab[i][j] != '-'))
				return (EXIT_FAILURE);
			if (j == 9 && ft_strncmp(tab[i], "2147483647", 10) > 0)
				return (EXIT_FAILURE);
			if (j == 10 && ft_strncmp(tab[i], "-2147483648", 11) > 0)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	unique_check(int *arr, int size)
{
	int		i;

	i = 0;
	while (++i < size)
		if (arr[i] == arr[i - 1])
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
