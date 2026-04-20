/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:20:05 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:05 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libft.h"
#include "error_handling.h"

int	is_flag(char *str)
{
	if (!ft_strncmp(str, "--simple", 8))
		return (1);
	if (!ft_strncmp(str, "--medium", 8))
		return (1);
	if (!ft_strncmp(str, "--complex", 9))
		return (1);
	if (!ft_strncmp(str, "--adaptive", 10))
		return (1);
	if (!ft_strncmp(str, "--bench", 7))
		return (1);
	return (0);
}

t_flag  get_flag(char **argv, int *start)
{
    int     i;
    t_flag  flag;

    i = 1;
    flag = ADAPTIVE;
    while (argv[i] && is_flag(argv[i]))
    {
        if (!ft_strncmp(argv[i], "--simple", 8))
            flag = SIMPLE;
        else if (!ft_strncmp(argv[i], "--medium", 8))
            flag = MEDIUM;
        else if (!ft_strncmp(argv[i], "--complex", 9))
            flag = COMPLEX;
        else if (!ft_strncmp(argv[i], "--adaptive", 10))
            flag = ADAPTIVE;
        else
            error_flag();
        i++;
    }
    *start = i;
    return (flag);
}