/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/16 07:00:34 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "flags.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_flag  flag;
    int     start;

    a = NULL;
    if (argc < 2)
        return (0);
    flag = get_flag(argv, &start);
    ft_parse_args(&a, argv + start - 1);
    if (is_sorted(a))
        return (free_stack(&a), 0);
    if (flag == SIMPLE)
        simple_sort(&a);
    else if (flag == MEDIUM)
        medium_sort(&a);
    else if (flag == COMPLEX)
        complex_sort(&a);
    else
        adaptive_sort(&a);
    free_stack(&a);
    return (0);
}
