/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:17:03 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 13:24:08 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROLL_H
# define FT_ROLL_H

# include <stdlib.h>

typedef struct s_roll
{
	int				value;
	struct s_roll	*next;
	struct s_roll	*prev;
}	t_roll;

typedef int	(*t_roll_op)(t_roll **roll);

t_roll	*roll_new(int value);
void	destroy_roll(t_roll **roll);
int		roll_size(t_roll *roll);
int		get_roll_at(t_roll *roll, int index);

int		roll_rotate(t_roll **roll);
int		roll_rev_rotate(t_roll **roll);
int		roll_swap(t_roll **roll);
int		roll_push(t_roll **roll, t_roll *slice);
t_roll	*roll_pop(t_roll **roll);

#endif
