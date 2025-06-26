/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:23:15 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:25:15 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap_a(t_stack *a)
{
	swap(a);
	ft_putstr("sa\n");
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one element or none. */

void	swap_b(t_stack *b)
{
	swap(b);
	ft_putstr("sb\n");
}

/* ss : sa and sb at the same time. */

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
