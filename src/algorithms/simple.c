/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:11:30 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/17 06:47:01 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	min;
	int	i;
	int	min_i;

	min = a->value;
	i = 0;
	min_i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_i = i;
		}
		a = a->next;
		i++;
	}
	return (min_i);
}

static void	bring_min_to_top(t_stack **a, t_ops *n_ops)
{
	int	min_index;
	int	size;
	int	steps;

	min_index = find_min_index(*a);
	size = ft_stack_size(*a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(a, n_ops);
	}
	else
	{
		steps = size - min_index;
		while (steps-- > 0)
			rra(a, n_ops);
	}
}

static void	sort_two(t_stack**a, t_ops *n_ops)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, n_ops);
}

static void    sort_three(t_stack **a, t_ops *n_ops)
{
    int    top;
    int    mid;
    int    bot;

    top = (*a)->value;
    mid = (*a)->next->value;
    bot = (*a)->next->next->value;
    if (top > mid && mid < bot && top < bot)
        sa(a, n_ops);
    else if (top > mid && mid > bot)
    {
        sa(a, n_ops);
        rra(a, n_ops);
    }
    else if (top > mid && mid < bot && top > bot)
        ra(a, n_ops);
    else if (top < mid && mid > bot && top < bot)
    {
        sa(a, n_ops);
        ra(a, n_ops);
    }
    else if (top < mid && mid > bot && top > bot)
        rra(a, n_ops);
}

void	simple_selection_sort(t_stack **a, t_stack **b, t_ops *n_ops)
{
	int	size;
	
	size = ft_stack_size(*a);

	// if (size <= 1)
	// 	return ;
	// if(size == 2)
	// 	return (sort_two(a, n_ops));
	// if (size == 3)
	// 	return (sort_three(a, n_ops));
	while (ft_stack_size(*a) > 1)
	{
		bring_min_to_top(a, n_ops);
		pb(a, b, n_ops);
	}
	while (*b)
		pa(a, b, n_ops);
	return ;
}
