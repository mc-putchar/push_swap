/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll_ops.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:08:56 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 16:11:04 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROLL_OPS_H
# define FT_ROLL_OPS_H

# include "ft_roll.h"

int	roll_rotate(t_roll **roll);
int	roll_rev_rotate(t_roll **roll);
int	roll_swap(t_roll **roll);

#endif
