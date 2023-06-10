/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:17:03 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 13:17:48 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROLL_H
# define FT_ROLL_H

# include <stdlib.h>

typedef struct s_roll
{
	int				value;
	unsigned int	rank;
	struct s_roll	*next;
	struct s_roll	*prev;
}	t_roll;

#endif
