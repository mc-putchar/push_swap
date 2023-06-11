/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:00:13 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/11 12:11:35 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANGE_H
# define FT_RANGE_H

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;


typedef struct s_cheap
{
	int	ai;
	int	bi;
	int	ci;
	int	dir;
	int	i;
}	t_cheap;

struct s_roll;

int		greater_of(int a, int b);
int		lower_of(int a, int b);
t_range	*get_roll_range(struct s_roll *b);
void	update_range(t_range *r, int val);

#endif
