/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 06:46:18 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/16 19:50:27 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_state(t_stack **a, t_stack **b, t_ops *n_ops)
{
	*a = NULL;
	*b = NULL;
	ft_memset(n_ops, 0, sizeof(t_ops));
}

static void	parse_input(int argc, char **argv, t_context *ctx)
{
	if (argc < 2)
		exit(0);
	ctx->flag = get_flag(argv, &ctx->start, ctx->bench);
	ft_parse_args(&ctx->a, argv + ctx->start - 1);
	if (is_sorted(ctx->a))
		exit(free_stack(&ctx->a), 0);
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
		adaptive_sort(a, b, *n_ops);
}

static void	run_benchmark(int bench, t_flag flag, double disorder, t_ops *n_ops)
{
	if (bench)
		print_bench(flag, disorder, n_ops);
}
