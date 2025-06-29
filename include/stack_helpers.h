/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:30:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/28 21:18:45 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HELPERS_H
# define STACK_HELPERS_H

#include "stack_core.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

t_bool	is_full(t_stack *stack);
t_bool	is_empty(t_stack *stack);

#endif
