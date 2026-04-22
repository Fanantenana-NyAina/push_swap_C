/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:04:44 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/22 09:30:19 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_handling.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_mess("not a number!");
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_duplicate(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
		{
			error_duplicate();
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

long	ft_atoi_ps(char *str)
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
			error_overflow();
		if (sign == -1 && - result < (long)INT_MIN)
			error_overflow();
		str++;
	}
	return (sign * result);
}

double	count_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pair;
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;
	int		*arr;

	size = ft_stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_malloc();
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp -> value;
		i++;
		tmp = tmp -> next;
	}
	mistakes = 0;
	total_pair = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pair++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(arr);
	return ((double) mistakes / (double) total_pair);
}
