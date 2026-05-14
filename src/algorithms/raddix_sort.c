/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:51:54 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/14 02:23:00 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	make_index(t_stack **stack_a)
{
	t_stack	*tmp;
	int		*tab;
	int		size;
	int		i;

	size = ft_stack_size(*stack_a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_tab(tab, size);
	free(tab);
}

int	raddix_sort(t_stack **stack_a, t_stack **stack_b, )
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_stack_size(*stack_a);
	max_bits = max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
