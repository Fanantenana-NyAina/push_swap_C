/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:14 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/24 09:45:43 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_stack_last(*stack);
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_a, t_ops *n_ops)
{
	rev_rotate(stack_a);
	n_ops->rra++;
}

void	rrb(t_stack **stack_b, t_ops *n_ops)
{
	rev_rotate(stack_b);
	n_ops->rrb;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	rra(stack_a, n_ops);
	rrb(stack_b, n_ops);
	n_ops->rrr++;
}
