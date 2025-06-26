/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:12:49 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:29:06 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"
#include "stack_helpers.h"

unsigned char	is_full(t_stack	*stack);
unsigned char	is_empty(t_stack	*stack);

t_stack	*create_stack(size_t capacity)
{
	t_stack	*stack;

	if (capacity <= 0)
		return (NULL);
	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->collection = (int *) malloc(sizeof(int) * capacity);
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->collection);
	free(stack);
	stack = NULL;
}

unsigned char	push(t_stack *stack, int item)
{
	if (!stack || is_full(stack))
		return (0);
	stack->collection[stack->size] = item;
	stack->size++;
	return (1);
}

unsigned char	pop(t_stack *stack, int *item)
{
	if (!stack || is_empty(stack))
		return (0);
	stack->size--;
	*item = stack->collection[stack->size];
	return (1);
}
