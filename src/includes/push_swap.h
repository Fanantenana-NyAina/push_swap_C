/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:33:24 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/19 08:55:08 by fanantenana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				rra;
	int				rrb;
	int				rrr;
}					t_ops;

typedef enum e_flag
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_flag;

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
void				ss(t_stack **stack_a, t_stack **stack_b, t_ops *n_ops);
void				rotate(t_stack **stack);
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
long	atoi_ps(char *str);
void				print_bench(t_flag flag, double disorder, t_ops *ops);

t_stack	*find_min(t_stack *stack_a);
t_stack	*find_max(t_stack *stack_a);

void    simple_selection_sort(t_stack **a, t_stack **b, t_ops *n_ops);
void    ft_chunk(t_stack **a, t_stack **b, t_ops *n_ops);
void    radix_sort(t_stack **a, t_stack **b, t_ops *n_ops);
void    adaptive_sort(t_stack **a, t_stack **b, double disorder, t_ops *ops);

void	print_disorder_fd(double disorder);
double	count_disorder(t_stack *a);

void	error_mess(char *mess);
void	error_overflow(void);
void	error_duplicate(void);
void	error_malloc(void);
void	error_flag(void);

t_flag	get_flag(char **argv, int *start);
int		is_flag(char *str);

#endif
