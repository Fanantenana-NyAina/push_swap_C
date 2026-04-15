/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:11:30 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/15 17:09:25 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_index(t_stack *a)
{
    int min;
    int i;
    int min_i;
    
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
    return min_i;
}

void    bring_min_to_top(t_stack **a)
{
    int min_index;
    int size;
    int steps;
    
    min_index = find_min_index(*a);
    size = ft_stack_size(*a);
    if (min_index <= size / 2)
    {
        while (min_index-- > 0)
            ra(a);
    }
    else
    {
        steps = size - min_index;
        while (steps-- > 0)
            rra(a);
    }
}

void    selection_sort(t_stack **a, t_stack **b)
{
    while (*a)
    {
        bring_min_to_top(a);
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}
