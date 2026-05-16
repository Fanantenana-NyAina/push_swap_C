/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:30:26 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/16 19:58:30 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    adaptive_sort(t_stack **a, t_stack **b, double disorder, t_ops *ops)
{
    if (disorder < 0.2)
        simple_selection_sort(a, b, ops);
    else if (disorder < 0.5)
        ft_chunk(a, b, ops);
    else
        radix_sort(a, b, ops);
}
