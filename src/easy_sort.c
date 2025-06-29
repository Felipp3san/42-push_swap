/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:44:49 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 20:22:22 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	get_max(t_stack *stack)
//{
//	size_t	i;
//	int		max;
//
//	i = 1;
//	max = stack->collection[0];
//	while (i < stack->size)
//	{
//		if (stack->collection[i] > max)
//			max = stack->collection[i];
//		i++;
//	}
//	return (max);
//}

//void	sort_two(t_ps *data)
//{
//	rotate_a(data);
//}

//void	sort_three(t_ps *data)
//{
//	t_stack	*a;
//	int		max;
//
//	a = &data->a;
//	max = get_max(a);
//	while (!is_sorted(a, ASC))
//	{
//		if (a->collection[a->top] == max)
//			rotate_a(data);
//		else if (a->collection[a->top] > a->collection[a->top - 1])
//			swap_a(data);
//		else
//			reverse_rotate_a(data);
//	}
//}

void	sort_five(t_ps *data)
{
	t_stack	*a;
	t_stack	*b;

	a = &data->a;
	b = &data->b;
	while (a->size != 3)
	{
		if (a->collection[a->top] == 1 || a->collection[a->top] == 2)
			push_b(data);
		else
			rotate_a(data);
	}
	if (b->collection[b->top] < b->collection[b->top - 1])
		swap_b(data);
	push_b(data);
	push_b(data);
}
