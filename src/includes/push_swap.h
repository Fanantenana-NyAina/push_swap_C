/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:33:24 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/22 20:54:38 by tsirakot         ###   ########.fr       */
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
}					t_flag;

typedef struct s_program
{
	t_stack			*a;
	t_stack			*b;
	t_ops			ops;
	t_flag			flag;
	t_flag			used;
	int				bench;
	int				start;
	double			disorder;
}					t_program;

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
long				atoi_ps(char *str);
void				print_bench(t_flag flag, double disorder,
						t_flag used_strategy, t_ops *n_ops);

t_stack				*find_min(t_stack *stack_a);
t_stack				*find_max(t_stack *stack_a);

void				simple_selection_sort(t_stack **a, t_stack **b,
						t_ops *n_ops);
void				ft_chunk(t_stack **a, t_stack **b, t_ops *n_ops);
void				radix_sort(t_stack **a, t_stack **b, t_ops *n_ops);
void				sort_tab(int *tab, int size);
void				loop_tmp(t_stack *a, int *tab, int size);
t_flag				adaptive_sort(t_stack **a, t_stack **b, double disorder,
						t_ops *ops);

void				print_disorder_fd(double disorder);
double				count_disorder(t_stack *a);

void				error(void);

t_flag				get_flag(char **argv, int *start, int *bench);
int					is_flag(char *str);
int					make_index(t_stack **stack_a);

#endif
