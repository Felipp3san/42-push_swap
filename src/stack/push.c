/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:57:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/28 21:23:14 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa (push a): Take the first element at the top of b and put it at the
	top of a. Do nothing if b is empty. */

void	push_a(t_ps *data)
{
	int	item;

	if (is_empty(&data->b))
		return ;
	pop(&data->b, &item);
	push(&data->a, item);
	store_op(data, pa);
}

/* pb (push b): Take the first element at the top of a and put it at the
	top of b. Do nothing if a is empty. */

void	push_b(t_ps *data)
{
	int	item;

	if (is_empty(&data->a))
		return ;
	pop(&data->a, &item);
	push(&data->b, item);
	store_op(data, pb);
}
