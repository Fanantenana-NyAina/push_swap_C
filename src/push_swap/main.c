/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/22 19:42:08 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	init_program(t_program *p)
{
	p->a = NULL;
	p->b = NULL;
	p->bench = 0;
	p->start = 0;
	p->disorder = 0;
	ft_memset(&p->ops, 0, sizeof(t_ops));
}

static t_flag	run_sort(t_program *p)
{
	if (p->flag == SIMPLE)
	{
		simple_selection_sort(&p->a, &p->b, &p->ops);
		return (SIMPLE);
	}
	if (p->flag == MEDIUM)
	{
		make_index(&p->a);
		ft_chunk(&p->a, &p->b, &p->ops);
		return (MEDIUM);
	}
	if (p->flag == COMPLEX)
	{
		make_index(&p->a);
		radix_sort(&p->a, &p->b, &p->ops);
		return (COMPLEX);
	}
	return (adaptive_sort(&p->a,
			&p->b, p->disorder, &p->ops));
}

int	main(int argc, char **argv)
{
	t_program	p;

	if (argc < 2)
		return (0);
	init_program(&p);
	p.flag = get_flag(argv, &p.start, &p.bench);
	ft_parse_args(&p.a, argv + p.start - 1);
	if (is_sorted(p.a))
		return (free_stack(&p.a), 0);
	p.disorder = count_disorder(p.a);
	p.used = run_sort(&p);
	if (p.bench)
		print_bench(p.flag, p.disorder, p.used, &p.ops);
	free_stack(&p.a);
	free_stack(&p.b);
	return (0);
}
