/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:29:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 21:55:40 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 0: top value - 1: below top value ...*/
int	value_from_top(t_stack *stack, int position)
{
	if (position <= stack->top)
		return (stack->collection[stack->top - position]);
	else
		return (-1);
}

size_t	next_down(size_t idx)
{
	if (idx == 0)
		return (idx);
	return (--idx);
}

size_t	next_up(t_stack *stk, size_t idx)
{
	if (idx >= stk->size - 1)
		return (idx);
	return (++idx);
}
