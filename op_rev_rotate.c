/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:14 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/11 00:47:49 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack_rev)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_rev || !(*stack_rev)->next)
		return ;
	first = *stack_rev;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *stack_rev;
	*stack_rev = first;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

/*void	rra(t_stack **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *stack_a;
	*stack_a = first;
}

void	rrb(t_stack **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *stack_b;
	*stack_b = first;
}*/
