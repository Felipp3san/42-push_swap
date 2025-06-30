/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:23:15 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/28 21:27:38 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

static void	swap(t_stack *stack)
{
	int		temp;
	size_t	size;

	if (!stack || stack->size <= 1)
		return ;
	size = stack->size;
	temp = stack->collection[size - 1];
	stack->collection[size - 1] = stack->collection[size - 2];
	stack->collection[size - 2] = temp;
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one element or none. */

void	swap_a(t_stacks *data)
{
	swap(&data->a);
	store_op(data, sa);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one element or none. */

void	swap_b(t_stacks *data)
{
	swap(&data->b);
	store_op(data, sb);
}

/* ss : sa and sb at the same time. */

void	swap_ab(t_stacks *data)
{
	swap(&data->a);
	swap(&data->b);
	store_op(data, ss);
}
