/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:33:24 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/14 16:55:52 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "disorder.h"
# include "flags.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct n_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				ra;
	int				rra;
	int				rrb;
	int				rrr;
}					t_ops;

typedef struct s_context
{
	t_stack			*a;
	t_stack			*b;
	t_flag			flag;
	t_ops			n_ops;
	int				start;
	int				bench;
	double			disorder;
}					t_context;

t_stack				*ft_stack_new(int value);
t_stack				*ft_stack_last(t_stack *lst);
void				ft_stack_add_back(t_stack **lst, t_stack *new);
int					ft_stack_size(t_stack *lst);
void				swap(t_stack **stack);
void				sa(t_stack **stack_a, t_ops *n_ops);
void				sb(t_stack **stack_b, t_ops *n_ops);
void				ss(t_stack **stack_a, t_stack stack_b, t_ops *n_ops);
void				rotate(t_stack **stack, t_ops *n_ops);
void				ra(t_stack **stack_a, t_ops *n_ops);
void				rb(t_stack **stack_b, t_ops *n_ops);
void				rr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops);
void				rev_rotate(t_stack **stack);
void				rra(t_stack **stack_a, t_ops *n_ops);
void				rrb(t_stack **stack_b, t_ops *n_ops);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops);
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **stack_b, t_stack **stack_a, t_ops *n_ops);
void				pb(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops);
int					ft_is_number(char *str);
int					ft_is_duplicate(t_stack *stack, int n);
void				ft_parse_args(t_stack **stack_a, char **av);
void				print_bench(t_flag flag, double disorder, t_ops *ops);

#endif
