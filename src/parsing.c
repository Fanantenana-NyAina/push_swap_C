/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:09 by tsirakot          #+#    #+#             */
/*   Updated: 2026/04/16 01:08:37 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	freeing_all(char **split)
{
    int i;
	
	i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}

void	ft_parse_args(t_stack **stack_a, char **argv)
{
	char	**splited;
	int		i;
	int		j;
	long	num_res;
	t_stack	*new_stack;

	i = 1;
	while (argv[i])
	{
		splited = ft_split(argv[i], ' ');
		if (!splited)
			error();
		j = 0;
		while(splited[j])
		{
			if (!ft_is_number(splited[j]))
				error();
			num_res = ft_atoi_ps(splited[j]);
			if (ft_is_duplicate(*stack_a, (int) num_res))
				error();
			new_stack = ft_stack_new((int) num_res);
			if (!new_stack)
				error();
			ft_stack_add_back(stack_a, new_stack);
			j++;
		}
		freeing_all(splited);
		i++;
	}
	return ;
}
