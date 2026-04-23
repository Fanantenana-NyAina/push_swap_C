/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:27:14 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/23 09:23:04 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_bench(t_flag flag, double disorder, int ops)
{
    if (flag == SIMPLE)
        ft_putstr_fd("[bench] strategy: Simple / O(n2)\n", 2);
    else if (flag == MEDIUM)
        ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n", 2);
    else if (flag == COMPLEX)
        ft_putstr_fd("[bench] strategy: Complex / O(nlogn)\n", 2);
    else
        ft_putstr_fd("[bench] strategy: Adaptive\n", 2);
    print_disorder_fd(count_disorder(disorder));
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(ops, 2);
    write(2, "\n", 1);
}
