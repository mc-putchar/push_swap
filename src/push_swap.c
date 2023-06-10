/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 14:41:54 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	integer_check(char **tab)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-')
				return (1);
	}
	return (0);
}