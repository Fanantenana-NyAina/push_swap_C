/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:27:14 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/23 11:41:19 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_bench(t_flag flag, double disorder, int ops)
{
    print_disorder_fd(disorder);
    if (flag == SIMPLE)
        ft_putstr_fd("[bench] strategy: Simple / O(n2)\n", 2);
    else if (flag == MEDIUM)
        ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n", 2);
    else if (flag == COMPLEX)
        ft_putstr_fd("[bench] strategy: Complex / O(nlogn)\n", 2);
    else
        ft_putstr_fd("[bench] strategy: Adaptive\n", 2);
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(ops, 2);
    // total ra, pa .... all operations total are still missing, need to be added
    write(2, "\n", 1);
}
