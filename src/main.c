/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:00 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 15:28:05 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**tab;

	if (ac < 2)
		return (0);
	if (ac > 2)
		tab = av + 1;
	else
		tab = ft_split(av[1], ' ');
	if (integer_check(tab))
		error_handler(NULL);
	return (0);
}
