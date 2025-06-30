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

/* Validates if the stack is sorted on specified direction */
t_bool	is_sorted(t_stack *stack, t_dir direction)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (direction == DESC)
		{
			if (stack->collection[i] > stack->collection[i + 1])
				return (FALSE);
		}
		else
		{
			if (stack->collection[i] < stack->collection[i + 1])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/* Counts how many numbers are smaller than element, and replace the element
 * with this value. */
int	normalize_stack(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		*new_values;

	new_values = (int *) ft_calloc(stack->size, sizeof(int));
	if (!new_values)
		return (MALLOC_ERROR);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->collection[j] < stack->collection[i])
				new_values[i] += 1;
			j++;
		}
		i++;
	}
	free(stack->collection);
	stack->collection = new_values;
	return (0);
}
