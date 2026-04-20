/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:53:39 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/20 11:39:38 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "push_swap.h"
# include "libft.h"

void    error_mess(char *mess);
void    error_overflow();
void    error_duplicate();
void    error_malloc();
void    error_flag();

#endif