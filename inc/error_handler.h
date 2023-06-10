/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:51:19 by mcutura           #+#    #+#             */
/*   Updated: 2023/06/10 20:37:24 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# define PROG_NAME		"push_swap"
# define USAGE			"usage: ./push_swap [numbers]"
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

void	error_handler(void (*f)(), void *arg);

#endif
