/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/14 18:33:08 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "flags.h"
#include "push_swap.h"

static void	parse_input(int argc, char **argv, t_context *ctx)
{
	if (argc < 2)
		exit(0);
	ctx->flag = get_flag(argv, &ctx->start, ctx->bench);
	ft_parse_args(&ctx->a, argv + ctx->start - 1);
	if (is_sorted(ctx->a))
		exit(free_stack(&ctx->a), 0);
}

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

static void	run_sort(t_stack **a, t_stack **b, t_ops *n_ops, t_flag flag)
{
	if (flag == SIMPLE)
		simple_selection_sort(a, b, n_ops);
	else if (flag == MEDIUM)
		ft_chunk(a, b, *n_ops);
	else if (flag == COMPLEX)
		raddix_sort(a, b, *n_ops);
	else
		adaptive_sort(a, b, n_ops);
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

int	main(int argc, char **argv)
{
	t_context	ctx;

	ft_memset(&ctx, 0, sizeof(t_context));
	parse_input(argc, argv, &ctx);
	ctx.disorder = count_disorder(ctx.a);
	run_sort(&ctx.a, &ctx.b, &ctx.n_ops, ctx.flag);
	if (bench)
		print_bench(flag, disorder, &n_ops);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

