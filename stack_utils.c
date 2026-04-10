/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:27:25 by tsirakot          #+#    #+#             */
/*   Updated: 2026/03/08 00:07:09 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stack_new(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_node	*ft_stack_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = next->lst;
	return (lst);
}

void	ft_stack_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_stack_last(*lst);
	last->next = new;
}

int	ft_stack_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
