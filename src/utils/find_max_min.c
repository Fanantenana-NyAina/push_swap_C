/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:52 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/22 20:55:41 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack_a)
{
	t_stack	*min;

	min = stack_a;
	while (stack_a)
	{
		if (stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack_a)
{
	t_stack	*max;

	max = stack_a;
	while (stack_a)
	{
		if (stack_a->value > max->value)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}
