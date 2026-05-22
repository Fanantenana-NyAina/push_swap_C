/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:51:54 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/22 19:35:16 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	if (size <= 1)
		return (0);
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

int	make_index(t_stack **stack_a)
{
	t_stack	*tmp;
	int		*tab;
	int		size;
	int		i;

	if (!stack_a || !*stack_a)
		return (0);
	size = ft_stack_size(*stack_a);
	if (size <= 0)
		return (0);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	tmp = *stack_a;
	i = 0;
	while (tmp && i < size)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_tab(tab, size);
	loop_tmp(*stack_a, tab, size);
	free(tab);
	return (0);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	if (!stack_a || !*stack_a)
		return ;
	make_index(stack_a);
	size = ft_stack_size(*stack_a);
	bits = get_max_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a, n_ops);
			else
				pb(stack_a, stack_b, n_ops);
		}
		while (*stack_b)
			pa(stack_a, stack_b, n_ops);
		i++;
	}
}
