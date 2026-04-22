/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:54:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/22 09:54:58 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    *stack_to_arr(t_stack *a, int size)
{
    int     *arr;
    int     i;
    t_stack *tmp;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        error_malloc();
    tmp = a;
    i = 0;
    while (tmp)
    {
        arr[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    return (arr);
}

static long    count_mistakes(int *arr, int size)
{
    long    mistakes;
    int     i;
    int     j;

    mistakes = 0;
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return (mistakes);
}

double    compute_disorder(t_stack *a)
{
    int     size;
    int     *arr;
    long    mistakes;
    long    total_pairs;
    double  disorder;

    size = ft_stack_size(a);
    if (size <= 1)
        return (0.0);
    arr = stack_to_arr(a, size);
    total_pairs = (long)size * (size - 1) / 2;
    mistakes = count_mistakes(arr, size);
    disorder = (double)mistakes / (double)total_pairs;
    free(arr);
    return (disorder);
}