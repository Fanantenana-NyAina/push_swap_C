/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:14 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/16 23:50:14 by tsirakot         ###   ########.fr       */
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, t_ops *n_ops)
{
	rev_rotate(stack_b);
	n_ops->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	rra(stack_a, n_ops);
	rrb(stack_b, n_ops);
	n_ops->rrr++;
	write(1, "rrr\n", 4);
}
