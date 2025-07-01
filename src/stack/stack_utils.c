/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:29:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 11:49:06 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

/* True is stack is full, otherwise False */
t_bool	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

/* True is stack is empty, otherwise False */
t_bool	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

/* 0: top value - 1: below top value ...*/
int	value_from_top(t_stack *stack, int position)
{
	if (position <= stack->top)
		return (stack->collection[stack->top - position]);
	else
		return (-1);
}

/* Get next element down from the stack */
size_t	next_down(size_t idx)
{
	if (idx == 0)
		return (idx);
	return (--idx);
}

/* Get next element up in the stack */
size_t	next_up(t_stack *stk, size_t idx)
{
	if (idx >= stk->size - 1)
		return (idx);
	return (++idx);
}
