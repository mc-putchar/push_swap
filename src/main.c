/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 17:30:36 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_roll	*stack_a;
	int		*tab;
	int		i;
	int		j;

	if (ac <= 2)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	i = 0;
	j = -1;
	if (ac > 2 && integer_check(av + 1))
		error_handler(NULL);
	if (init_stack(av + 1, &stack_a))
		error_handler(NULL);
	print_stack(stack_a); // TODO remove
	if (!is_sorted(stack_a))
		ft_printf("Stack is sorted\n");
	else
	{
		tab = get_sorted_array(stack_a, &i);
		while (++j < i)
			ft_printf("%d\n", tab[j]);
	}
	destroy_roll(&stack_a);
	return (EXIT_SUCCESS);
}
