/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 05:57:59 by tsirakot          #+#    #+#             */
/*   Updated: 2026/05/22 20:55:08 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cmp_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	ia = *(int *)a;
	ib = *(int *)b;
	if (ia < ib)
		return (-1);
	if (ia > ib)
		return (1);
	return (0);
}

void	sort_tab(int *tab, int size)
{
	if (!tab || size <= 1)
		return ;
	qsort(tab, size, sizeof(int), cmp_int);
}

static int	find_index(int *tab, int value, int size)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (tab[mid] == value)
			return (mid);
		if (tab[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	loop_tmp(t_stack *a, int *tab, int size)
{
	if (!a || !tab || size <= 0)
		return ;
	while (a)
	{
		a->index = find_index(tab, a->value, size);
		a = a->next;
	}
}
