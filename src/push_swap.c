/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 15:33:59 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	integer_check(char **tab)
{
	int		i;
	int		j;

	i = -1;
	if (!tab && errno)
		return (errno);
	else if (!tab)
		return (1);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (j > 10 || (!ft_isdigit(tab[i][j]) && tab[i][j] != '-'))
				return (1);
			if (j == 9 && ft_strncmp(tab[i], "2147483647", 10) > 0)
				return (1);
			if (j == 10 && ft_strncmp(tab[i], "-2147483648", 11) > 0)
				return (1);
		}
	}
	return (0);
}