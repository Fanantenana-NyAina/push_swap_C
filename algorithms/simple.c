/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:11:30 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/15 11:17:51 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    find_mind_index(t_stack **a)
{
    
}

void    bring_min_to_top(t_stack **a)
{
    int min_index = find_min_index(*a);
    int size = ft_stack_size(*a);

    if (min_index <= size / 2)
    {
        while (min_index-- > 0)
            ra(a);
    }
    else
    {
        int steps = size - min_index;
        while (steps-- > 0)
            rra(a);
    }
}

void    selection_sort(t_stack **a, t_stack **b)
{
    while (*a)
    {
        bring_min_to_front(a);
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}