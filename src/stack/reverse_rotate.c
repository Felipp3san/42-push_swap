/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:39:21 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/28 21:29:08 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

static void	reverse_rotate(t_stack *stack)
{
	int		temp;
	size_t	i;
	size_t	size;

	if (!stack || stack->size <= 1)
		return ;
	size = stack->size;
	temp = stack->collection[0];
	i = 0;
	while (i < size - 1)
	{
		stack->collection[i] = stack->collection[i + 1];
		i++;
	}
	stack->collection[size - 1] = temp;
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one. */

void	reverse_rotate_a(t_stacks *data)
{
	reverse_rotate(&data->a);
	store_op(data, rra);
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one. */

void	reverse_rotate_b(t_stacks *data)
{
	reverse_rotate(&data->b);
	store_op(data, rrb);
}

/* rrr : rra and rrb at the same time. */

void	reverse_rotate_a_b(t_stacks *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	store_op(data, rrr);
}
