/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:21:21 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:22:33 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

unsigned char	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

unsigned char	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
