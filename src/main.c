/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 19:41:20 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	main(int ac, char **av)
{
	t_roll	*stack_a;
	char	**tmp;
	int		i;

	if (ac < 2)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	i = 0;
	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		if (!tmp || input_check(tmp) || init_stack(tmp, &stack_a))
			error_handler(NULL, NULL);
		free_tab(tmp);
	}
	else if (input_check(av + 1) || init_stack(av + 1, &stack_a))
		error_handler(NULL, NULL);
	if (!is_sorted(stack_a))
		return (destroy_roll(&stack_a), EXIT_SUCCESS);
	i = roll_size(stack_a);
	if (i <= 3)
		sort_three(&stack_a);
	else if (turbo_sort(&stack_a))
		error_handler(&destroy_roll, &stack_a);
	destroy_roll(&stack_a);
	return (EXIT_SUCCESS);
}
