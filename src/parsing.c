/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:09 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/16 06:49:15 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	treating_stack(t_stack **stack_a, char *str)
{
	long	num;
	t_stack	*node;

	if (!ft_is_number(str))
		error();
	num = ft_atoi_ps(str);
	if (ft_is_duplicate(*stack_a, (int)num))
		error();
	node = new_node((int)num);
	if (!node)
		error();
	ft_stack_add_back(stack_a, node);
}

static void	handle_split(t_stack **stack_a, char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		treating_stack(stack_a, split[j]);
		j++;
	}
}

static void	freeing_all(char **split)
{
    int i;
	
	i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}

void	ft_parse_args(t_stack **stack_a, char **av)
{
	int		i;
	char	**splited;

	i = 1;
	while (av[i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			error();
		handle_split(stack_a, splited);
		freeing_all(splited);
		i++;
	}
}
