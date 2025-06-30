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

void	init_stacks(t_stacks *data, size_t capacity)
{
	data->a.collection = (int *) malloc(sizeof(int) * capacity);
	if (!data->a.collection)
		error(data);
	data->a.capacity = capacity;
	data->a.size = 0;
	data->a.top = -1;
	data->a.bottom = 0;
	data->b.collection = (int *) malloc(sizeof(int) * capacity);
	if (!data->b.collection)
		error(data);
	data->b.capacity = capacity;
	data->b.size = 0;
	data->b.top = -1;
	data->b.bottom = 0;
}

t_bool	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

t_bool	is_empty(t_stack *stack)
{
	return (stack->size == 0);
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
