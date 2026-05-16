/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:40:31 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/16 19:44:44 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *stack, t_stack *target)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp == target)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static void	bring_max_to_top(t_stack **b, t_ops *n_ops)
{
	t_stack	*max;
	int		pos;
	int		size;
	int		rev;

	if (!b || !*b)
		return ;
	max = find_max(*b);
	pos = get_position(*b, max);
	if (pos < 0)
		return ;
	size = ft_stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, n_ops);
	}
	else
	{
		rev = size - pos;
		while (rev-- > 0)
			rrb(b, n_ops);
	}
}

static int	get_chunk_size(int size)
{
	if (size > 100)
		return (35);
	return (15);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk, t_ops *n_ops)
{
	int	next_target;

	if (!a || !*a)
		return ;
	next_target = 0;
	while (*a)
	{
		if ((*a)->index <= next_target)
		{
			pb(a, b, n_ops);
			next_target++;
			rb(b, n_ops);
		}
		else if ((*a)->index <= next_target + chunk)
		{
			pb(a, b, n_ops);
			next_target++;
		}
		else
			ra(a, n_ops);
	}
}

void	ft_chunk(t_stack **a, t_stack **b, t_ops *n_ops)
{
	int	size;
	int	chunk;

	if (!a || !*a)
		return ;
	size = ft_stack_size(*a);
	chunk = get_chunk_size(size);
	push_chunks_to_b(a, b, chunk, n_ops);
	while (*b)
	{
		bring_max_to_top(b, n_ops);
		pa(a, b, n_ops);
	}
}
