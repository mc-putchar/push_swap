/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 23:35:42 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_roll.h"
# include "error_handler.h"

# define SA		0
# define RA		1
# define RRA	2
# define SB		3
# define RB		4
# define RRB	5
# define SS		6
# define RR		7
# define RRR	8
# define PA		9
# define PB		10

static const char	*g_ops_name[] = {[SA] = "sa", [RA] = "ra", [RRA] = "rra", \
	[SB] = "sb", [RB] = "rb", [RRB] = "rrb", [SS] = "ss", [RR] = "rr", \
	[RRR] = "rrr", [PA] = "pa", [PB] = "pb"};

int		integer_check(char **tab);
int		init_stack(char **tab, t_roll **stack_a);
void	print_stack(t_roll *stack_a);

int		is_sorted(t_roll *stack_a);
void	quicksort(int *tab, int size);
int		*get_sorted_array(t_roll *stack_a, int *size);

int		unique_check(int *arr, int size);
int		integer_check(char **tab);

void	translate(t_roll **a, t_roll **b, int op);
void	tr_pushes(t_roll **a, t_roll **b, int op);

#endif
