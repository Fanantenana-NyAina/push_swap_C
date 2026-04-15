/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:25:44 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/16 02:26:06 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

typedef enum e_flag
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_flag;

t_flag	get_flag(char **argv);
int		is_flag(char *str);

#endif