/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:20:05 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/22 09:46:38 by fanantenana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    is_exact(char *str, char *flag)
{
    return (!ft_strncmp(str, flag, ft_strlen(flag) + 1)
        && ft_strlen(str) == ft_strlen(flag));
}

int	is_flag(char *str)
{
	if (is_exact(str, "--simple"))
		return (1);
	if (is_exact(str, "--medium"))
		return (1);
	if (is_exact(str, "--complex"))
		return (1);
	if (is_exact(str, "--adaptive"))
		return (1);
	if (is_exact(str, "--bench"))
		return (1);
	return (0);
}

t_flag	get_flag(char **argv, int *start, 	int *bench)
{
	int		i;
	t_flag	flag;

	i = 1;
	*bench = 0;
	flag = ADAPTIVE;
	while (argv[i] && is_flag(argv[i]))
	{
		if (is_exact(argv[i], "--simple"))
			flag = SIMPLE;
		else if (is_exact(argv[i], "--medium"))
			flag = MEDIUM;
		else if (is_exact(argv[i], "--complex"))
			flag = COMPLEX;
		else if (is_exact(argv[i], "--bench"))
			*bench = 1;
		else if (is_exact(argv[i], "--adaptive"))
			flag = ADAPTIVE;
		// live code : new flag count only !!
		else
			error_flag();
		i++;
	}
	*start = i;
	return (flag);
}
