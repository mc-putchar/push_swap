/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:42:13 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 19:00:41 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	input_check(char **tab)
{
	int		i;
	int		*arr;
	int		size;

	i = 0;
	if (!tab || !*tab)
		return (EXIT_FAILURE);
	while (tab[i])
		++i;
	size = i;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < size)
		arr[i] = ft_atoi(tab[i]);
	if (integer_check(tab) || !is_sorted_tab(arr, size))
		return (free(arr), EXIT_FAILURE);
	quicksort(arr, size);
	if (unique_check(arr, size))
		return (free(arr), EXIT_FAILURE);
	free(arr);
	return (EXIT_SUCCESS);
}
