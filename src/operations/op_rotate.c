/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:04 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/16 23:50:35 by tsirakot         ###   ########.fr       */
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
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, t_ops *n_ops)
{
	rotate(stack_b);
	n_ops->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	ra(stack_a, n_ops);
	rb(stack_b, n_ops);
	n_ops->rr++;
	write(1, "rr\n", 3);
}
