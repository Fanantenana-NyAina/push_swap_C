/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:38 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/16 23:51:05 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a, t_ops *n_ops)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	n_ops->sa++;
}

void	sb(t_stack **stack_b, t_ops *n_ops)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	n_ops->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	sa(stack_a, n_ops);
	sb(stack_b, n_ops);
	n_ops->ss++;
	write(1, "ss\n", 3);
}
