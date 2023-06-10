/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 16:35:09 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_roll	*stack_a;

	if (ac <= 2)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	if (ac > 2 && integer_check(av + 1))
		error_handler(NULL);
	if (init_stack(av + 1, &stack_a))
		error_handler(NULL);
	print_stack(stack_a);
	destroy_roll(&stack_a);
	return (EXIT_SUCCESS);
}
