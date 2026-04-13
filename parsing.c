/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:09 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/13 10:36:48 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> // need to be in our .h file

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		return (1);
	while (str)
	{
		if (str[i] > '0' && str[i] < '9')
			return (1);
		i++;
	}
	return (1);
}

int	ft_is_duplicate(t_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		sack = stack->next;
	}
	return (0);
}

long ft_atoi_ps(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > (long)INT_MAX)
			return (INT_MAX);
		if (sign == -1 && - result < (long)INT_MIN)
			return (INT_MIN);
		str++;
	}
	return (sign * result);
}

void	ft_parse_args(t_node **stack_a, char **av)
{
}
