/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_wrapper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:33:52 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 10:49:03 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse_rotate_a(t_data *data)
{
	reverse_rotate_a(&data->a);
	store_op(data, rra);
}

void	ps_reverse_rotate_b(t_data *data)
{
	reverse_rotate_b(&data->b);
	store_op(data, rrb);
}

void	ps_reverse_rotate_a_b(t_data *data)
{
	reverse_rotate_a_b(&data->a, &data->b);
	store_op(data, rrr);
}
