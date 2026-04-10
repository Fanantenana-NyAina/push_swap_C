/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:29:04 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/11 00:47:49 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack_rotate)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_rotate || !(stack_rotate)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack_rotate = first->next;
	*stack_rotate->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

/*void	ra(t_stack **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_a || !(stack_a)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	*stack_a->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}*/

/*void	rb(t_stack **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_b || !(stack_b)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	*stack_b->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}*/
