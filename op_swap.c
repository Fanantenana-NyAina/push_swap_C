/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:38 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/11 00:47:47 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_swap)
{
	t_node	*first;
	t_node	*second;

	if (*stack_swap && (*stack_swap)->next)
	{
		first = *stack_swap;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_swap = second;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

/*void	sa(t_stack **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
}

void	sb(t_stack **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
}*/
