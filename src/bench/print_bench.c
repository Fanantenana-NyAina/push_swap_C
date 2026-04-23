/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:27:14 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/23 15:39:27 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_operations_s_p()
{
    ft_putstr_fd("[bench] sa:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("sb:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("ss:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("pa:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("pb:   ", 2);
    ft_putnbr_fd(, 2);
}

static void print_operations_r()
{
    ft_putstr_fd("[bench] ra:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rb:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rr:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rra:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rrb:   ", 2);
    ft_putnbr_fd(, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rrr:   ", 2);
    ft_putnbr_fd(, 2);

}

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
