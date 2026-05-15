/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 07:30:24 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/15 13:39:39 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

void    simple_selection_sort(t_stack **a, t_stack **b, t_ops *n_ops);
void    ft_chunk(t_stack **a, t_stack **b, t_ops n_ops);
void    raddix_sort(t_stack **a, t_stack **b, t_ops *n_ops);
void    adaptive_sort(t_stack **a, t_stack **b, double disorder, t_ops *ops);

#endif
