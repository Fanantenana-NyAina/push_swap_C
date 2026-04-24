/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:27:14 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/24 10:04:43 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int total_ops(t_ops *n_ops)
{
    int total_s_p;
    int total_r;

    total_s_p = n_ops->sa + n_ops->sb + n_ops->ss + n_ops->pa + n_ops->pb;
    total_r = n_ops->ra + n_ops->rb + n_ops-> rr + n_ops->rra + n_ops->rrb + n_ops->rrr;

    return (total_s_p + total_r);
}

static void print_operations_s_p(t_ops *n_ops)
{
    ft_putstr_fd("[bench] sa:   ", 2);
    ft_putnbr_fd(n_ops->sa, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("sb:   ", 2);
    ft_putnbr_fd(n_ops->sb, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("ss:   ", 2);
    ft_putnbr_fd(n_ops->ss, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("pa:   ", 2);
    ft_putnbr_fd(n_ops->pa, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("pb:   ", 2);
    ft_putnbr_fd(n_ops->pb, 2);
}

static void print_operations_r(t_ops *n_ops)
{
    ft_putstr_fd("[bench] ra:   ", 2);
    ft_putnbr_fd(n_ops->ra, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rb:   ", 2);
    ft_putnbr_fd(n_ops->rb, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rr:   ", 2);
    ft_putnbr_fd(n_ops->rr, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rra:   ", 2);
    ft_putnbr_fd(n_ops->rra, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rrb:   ", 2);
    ft_putnbr_fd(n_ops->rrb, 2);
    ft_putchar_fd(" ", 2);
    ft_putstr_fd("rrr:   ", 2);
    ft_putnbr_fd(n_ops->rrr, 2);

}

void    print_bench(t_flag flag, double disorder, t_ops *n_ops)
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
    ft_putnbr_fd(total_ops(n_ops), 2);
    print_operations_s_p(n_ops);
    print_operations_r(n_ops);
    write(2, "\n", 1);
}
