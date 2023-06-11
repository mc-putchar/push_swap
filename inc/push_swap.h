/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 15:01:22 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_roll.h"
# include "error_handler.h"
# include "ft_range.h"

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

void	do_op(t_roll **a, t_roll **b, int op);
void	ops_pushes(t_roll **a, t_roll **b, int op);

void	sort_three(t_roll **stack_a);
int		turbo_sort(t_roll **a);

t_cost	*spin_to_max(t_roll *roll, int max);
t_cost	*spin_to_min(t_roll *roll, int min);
t_cost	*spin_to_lower(t_roll *roll, int val);
t_cost	*spin_to_higher(t_roll *roll, int val);
t_cost	*spin_to_value(t_roll *roll, int val);

t_cost	*insert_cost(t_roll *b, int val, t_range *r);
t_cost	*pushback_cost(t_roll *a, int val, t_range *r);
t_cheap	*lowest_cost(t_roll *a, t_roll *b, t_range *r, int val);
t_cheap	*find_cheapest(t_roll *a, t_roll *b, t_range *r);

#endif
