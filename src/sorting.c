/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:46:05 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/13 18:31:02 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_roll *roll)
{
	t_roll	*start;

	if (!roll)
		return (EXIT_FAILURE);
	start = roll->next;
	while (start != roll)
	{
		if (start->value <= start->prev->value)
			return (EXIT_FAILURE);
		start = start->next;
	}
	return (EXIT_SUCCESS);
}

int	is_sorted_tab(int *tab, int size)
{
	int	i;

	if (!tab || size < 2)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

void	quicksort(int *tab, int size)
{
	int	pivot;
	int	i;
	int	j;

	if (size < 2)
		return ;
	pivot = tab[size / 2];
	i = -1;
	j = size;
	while (1)
	{
		while (tab[++i] < pivot)
			;
		while (tab[--j] > pivot)
			;
		if (i >= j)
			break ;
		ft_swap(&tab[i], &tab[j]);
	}
	quicksort(tab, i);
	quicksort(tab + i, size - i);
}

int	*get_sorted_array(t_roll *stack_a, int *size)
{
	int		i;
	int		*tab;
	t_roll	*tmp;

	if (!stack_a || !size)
		return (NULL);
	*size = roll_size(stack_a);
	tab = malloc(sizeof(int) * *size);
	if (!tab)
		return (NULL);
	i = 0;
	tmp = stack_a;
	while (i < *size)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	quicksort(tab, *size);
	return (tab);
}
