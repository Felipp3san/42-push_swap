/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:57:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/29 18:36:07 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty. */

void	push_a(t_stack *a, t_stack *b)
{
	int	item;

	if (is_empty(b))
		return ;
	pop(b, &item);
	push(a, item);
	ft_putstr("pa\n");
}

/** pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty. */

void	push_b(t_stack *a, t_stack *b)
{
	int	item;

	if (is_empty(a))
		return ;
	pop(a, &item);
	push(b, item);
	ft_putstr("pb\n");
}

/** ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one. */


/** rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one. */


/** rr : ra and rb at the same time. */


/** rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one. */

/** rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one. */

/** rrr : rra and rrb at the same time. */

