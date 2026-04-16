/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:53:52 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/16 06:07:51 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "flags.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_flag	flag;

	a = NULL;
	if (argc < 2)
		return (0);
	flag = get_flag(argv);
	ft_parse_args(&a, argv);
	if (is_sorted(a))
		return (0);
	if (flag == SIMPLE)
		simple_sort(&a);
	else if (flag == MEDIUM)
		medium_sort(&a);
	else if (flag == COMPLEX)
		complex_sort(&a);
	else
		adaptive_sort(&a);
	return (0);
}