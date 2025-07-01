/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:44:49 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:16:36 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "wrappers.h"

static int	get_max(t_stack *stack);

void	easy_sort_three(t_ps *data)
{
	t_stack	*a;
	int		max;

	a = &data->a;
	max = get_max(a);
	while (!is_sorted(a, ASC))
	{
		if (a->collection[a->top] == max)
			ps_rotate_a(data);
		else if (a->collection[a->top] > a->collection[a->top - 1])
			ps_swap_a(data);
		else
			ps_reverse_rotate_a(data);
	}
}

void	easy_sort_five(t_ps *data)
{
	t_stack	*a;
	t_stack	*b;

	a = &data->a;
	b = &data->b;
	while (a->size != 3)
	{
		if (value_from_top(a, 0) < 2)
			ps_push_b(data);
		else if (a->collection[0] < 2)
		{
			ps_reverse_rotate_a(data);
			ps_push_b(data);
		}
		else
			ps_rotate_a(data);
	}
	if (value_from_top(b, 0) < value_from_top(b, 1))
		ps_swap_b(data);
	easy_sort_three(data);
	ps_push_a(data);
	ps_push_a(data);
}

static int	get_max(t_stack *stack)
{
	size_t	i;
	int		max;

	i = 1;
	max = stack->collection[0];
	while (i < stack->size)
	{
		if (stack->collection[i] > max)
			max = stack->collection[i];
		i++;
	}
	return (max);
}
