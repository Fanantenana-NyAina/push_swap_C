/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/22 19:27:28 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

t_flag	run_sort(t_stack **a, t_stack **b, t_flag flag, double disorder, t_ops *n_ops)
{
	if (flag == SIMPLE)
	{
		simple_selection_sort(a, b, n_ops);
		return (SIMPLE);
	}
	else if (flag == MEDIUM)
	{
		ft_chunk(a, b, n_ops);
		return (MEDIUM);
	}
	else if (flag == COMPLEX)
	{
		radix_sort(a, b, n_ops);
		return (COMPLEX);
	}
	else
		return (adaptive_sort(a, b, disorder, n_ops));
}

int main(int argc, char **argv) // need to be refactor cuz it's too long i think
{
    t_stack *a;
    t_stack *b;
    t_flag  flag;
    t_flag  used_strategy;
    t_ops   n_ops;
    int     start;
    int     bench;
    double  disorder;

    ft_memset(&n_ops, 0, sizeof(t_ops));
    a = NULL;
    b = NULL;
    bench = 0;
    if (argc < 2)
        return (0);
    flag = get_flag(argv, &start, &bench);
    ft_parse_args(&a, argv + start - 1);
    if (is_sorted(a))
        return (free_stack(&a), 0);
    disorder = count_disorder(a);
    used_strategy = run_sort(&a, &b, flag, disorder, &n_ops);
    if (bench)
        print_bench(flag, disorder, used_strategy, &n_ops);
     // need to fix later according to what we will gonna do
    free_stack(&a);
    free_stack(&b);
    return (0);
}
