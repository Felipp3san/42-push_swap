/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:57:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:25:28 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa (push a): Take the first element at the top of b and put it at the
	top of a. Do nothing if b is empty. */

void	push_a(t_stack *a, t_stack *b)
{
	int	item;

	if (is_empty(b))
		return ;
	pop(b, &item);
	push(a, item);
	ft_putstr("pa\n");
}

/* pb (push b): Take the first element at the top of a and put it at the
	top of b. Do nothing if a is empty. */

void	push_b(t_stack *a, t_stack *b)
{
	int	item;

	if (is_empty(a))
		return ;
	pop(a, &item);
	push(b, item);
	ft_putstr("pb\n");
}
