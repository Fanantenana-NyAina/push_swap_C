/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/23 10:03:45 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "flags.h"
#include "algorithms.h"

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

int main(int argc, char **argv) // need to be refactor cuz it's too long i think
{
    t_stack *a;
    t_stack *b;
    t_flag  flag;
    int     start;
    int     bench;
    double  disorder;
    int     ops;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    flag = get_flag(argv, &start, bench);
    ft_parse_args(&a, argv + start - 1);
    if (is_sorted(a))
        return (free_stack(&a), 0);
    disorder = count_disorder(a);
    ops = 0;
    if (flag == SIMPLE)
        ops = simple_selection_sort(&a, &b);
    else if (flag == MEDIUM)
        ops = medium_sort(&a); // need to fix later according to what we will gonna do
    else if (flag == COMPLEX)
        ops = complex_sort(&a); // need to fix later according to what we will gonna do
    else
        ops = adaptive_sort(&a); // need to fix later according to what we will gonna do
    if (bench)
        print_bench(flag, disorder, ops);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
