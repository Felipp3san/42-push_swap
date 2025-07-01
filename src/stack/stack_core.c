/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:12:49 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:14:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

int	init_stack(t_stack *stack, int capacity)
{
	stack->collection = (int *) malloc(sizeof(int) * capacity);
	if (!stack->collection)
		return (MALLOC_ERROR);
	stack->capacity = capacity;
	stack->size = 0;
	stack->top = -1;
	stack->bottom = 0;
	return (SUCCESS);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->collection);
		stack->collection = NULL;
		stack->size = 0;
		stack->top = -1;
		stack->bottom = 0;
	}
}

void	push(t_stack *stack, int item)
{
	if (!stack || is_full(stack))
		return ;
	stack->collection[stack->size] = item;
	stack->size++;
	stack->top++;
}

void	pop(t_stack *stack, int *item)
{
	if (!stack || is_empty(stack))
		return ;
	stack->size--;
	stack->top--;
	*item = stack->collection[stack->size];
}
