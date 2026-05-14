/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:52 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/14 16:53:12 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	tmp->prev = NULL;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
}

void	pa(t_stack **stack_b, t_stack **stack_a, t_ops *n_ops)
{
	push(stack_a, stack_b);
	n_ops->pa++;
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	push(stack_b, stack_a);
	n_ops->pb++;
}
