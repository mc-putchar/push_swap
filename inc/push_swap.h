/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:10:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 16:24:15 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_roll.h"
# include "error_handler.h"

int		integer_check(char **tab);
int		init_stack(char **tab, t_roll **stack_a);
void	print_stack(t_roll *stack_a);

#endif
