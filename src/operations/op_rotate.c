/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:04 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/24 09:47:24 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **stack_a, t_ops *n_ops)
{
	rotate(stack_a);
	n_ops->ra++;
}

void	rb(t_stack **stack_b, t_ops *n_ops)
{
	rotate(stack_b);
	n_ops->rb++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	ra(stack_a, n_ops);
	rb(stack_b, n_ops);
	n_ops->rr++;
}
