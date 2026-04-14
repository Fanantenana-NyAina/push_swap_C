/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:09 by tsirakot          #+#    #+#             */
/*   Updated: 2026/03/07 04:07:02 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ft_atoi_ps(char *str)
{
}

void	ft_parse_args(t_node **stack_a, char **av)
{
}
