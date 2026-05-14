/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:40:31 by fananrak          #+#    #+#             */
/*   Updated: 2026/05/14 02:22:58 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_position(t_stack **b, t_stack target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

static void	bring_max_to_top(t_stack **b)
{
	t_stack	*max;
	int		pos;
	int		size;
	int		rev;

	if (!b || !*b)
		return ;
	max = find_max(*b);
	pos = get_position(*b, max);
	size = ft_stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		rev = size - pos;
		while (rev-- > 0)
			rrb(b);
	}
}

void	ft_chunk(t_stack **a, t_stack **b)
{
	int	chunk;
	int	next_target;

	chunk = 15;
	if (ft_stack_size(*a) > 100)
		chunk = 35;
	while (*a > 0)
	{
		if ((*a)->index <= next_target && ++next_target)
		{
			pb(a, b);
			rb(b);
		}
		else if ((*a)->index <= next_target + chunk && next_target)
			pb(a, b);
		else
			ra(a);
	}
	while (*b)
	{
		bring_max_to_top(b);
		pa(a, b);
	}
}
