/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:23 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/20 11:39:14 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void	error_mess(char *mess)
{
	write(2, "ERROR:\n", 7);
	write(2, mess, ft_strlen(mess));
	exit(1);
}

void	error_overflow(void)
{
	error_msg("integer overflow");
}

void	error_duplicate(void)
{
	error_msg("duplicate value");
}

void	error_malloc(void)
{
	error_msg("malloc failed");
}

void	error_flag(void)
{
	error_msg("unknown flag");
}
