/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:31:08 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 20:36:53 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

void	error_handler(void (*f)(), void *arg)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	ft_dprintf(STDERR_FILENO, "Error\n");
	if (f)
		f(arg);
	exit(exit_code);
}
