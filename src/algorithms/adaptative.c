/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:30:26 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/22 22:38:57 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	adaptive_sort(t_stack **a, t_stack **b, double disorder, t_ops *ops)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 5 || disorder < 0.2)
	{
		simple_selection_sort(a, b, ops);
		return (SIMPLE);
	}
	else if (size <= 100 || disorder < 0.6)
	{
		ft_chunk(a, b, ops);
		return (MEDIUM);
	}
	else
	{
		make_index(a);
		radix_sort(a, b, ops);
		return (COMPLEX);
	}
}
