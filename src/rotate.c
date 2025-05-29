/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:29:31 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/29 18:57:16 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->collection[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->collection[i] = stack->collection[i - 1];
		i--;
	}
	stack->collection[0] = temp;
}

/** ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one. */
void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_putstr("ra\n");
}

/** rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one. */
void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_putstr("rb\n");
}

/** rr : ra and rb at the same time. */
void	rotate_a_b(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
