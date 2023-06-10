/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:31:08 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 14:45:39 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

void	error_handler(int err, char *str, void *arg)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (!err)
		exit_code = EXIT_SUCCESS;
	if (str)
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", \
		PROG_NAME, strerror(err), str);
	else
		ft_dprintf(STDERR_FILENO, "%s: %s\n", PROG_NAME, strerror(err));
	free(arg);
	exit(exit_code);
}
