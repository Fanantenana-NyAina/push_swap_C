/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:09 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/22 20:04:26 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	treating_stack(t_stack **stack_a, char *str)
{
	long	num;
	t_stack	*node;

	ft_is_number(str);
	num = atoi_ps(str);
	ft_is_duplicate(*stack_a, (int)num);
	node = ft_stack_new((int)num);
	if (!node)
		error();
	ft_stack_add_back(stack_a, node);
}

static void	handle_split(t_stack **stack_a, char **splited)
{
	int	j;

	j = 0;
	while (splited[j])
	{
		treating_stack(stack_a, splited[j]);
		j++;
	}
}

static void	freeing_all(char **split)
{
	int	i;

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
		if (is_flag(av[i]))
		{
			i++;
			continue ;
		}
		splited = ft_split(av[i], ' ');
		if (!splited || !splited[0])
			error();
		handle_split(stack_a, splited);
		freeing_all(splited);
		i++;
	}
}
