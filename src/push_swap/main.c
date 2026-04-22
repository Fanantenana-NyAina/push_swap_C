/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/20 13:36:59 by fananrak         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_flag  flag;
    int     start;
    double  disorder;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    flag = get_flag(argv, &start);
    ft_parse_args(&a, argv + start - 1);
    if (is_sorted(a))
        return (free_stack(&a), 0);
    disorder = count_disorder(a);
    if (flag == SIMPLE)
        simple_selection_sort(&a, &b);
    else if (flag == MEDIUM)
        medium_sort(&a); // need to fix later according to what we will gonna do
    else if (flag == COMPLEX)
        complex_sort(&a); // need to fix later according to what we will gonna do
    else
        adaptive_sort(&a); // need to fix later according to what we will gonna do
    free_stack(&a);
    free_stack(&b);
    return (0);
}
