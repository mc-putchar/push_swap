/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 08:13:17 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_roll	*stack_a;
	int		*tab;
	int		i;

	if (ac <= 2)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	i = 0;
	if (ac > 2 && integer_check(av + 1))
		error_handler(NULL, NULL);
	if (init_stack(av + 1, &stack_a))
		error_handler(NULL, NULL);
	if (!is_sorted(stack_a))
		error_handler(&destroy_roll, &stack_a);
	tab = get_sorted_array(stack_a, &i);
	if (unique_check(tab, i))
		error_handler(&destroy_roll, &stack_a);
	free(tab);
	if (i <= 3)
		sort_three(&stack_a);
	else if (turbo_sort(&stack_a))
		error_handler(&destroy_roll, &stack_a);
	destroy_roll(&stack_a);
	return (EXIT_SUCCESS);
}
