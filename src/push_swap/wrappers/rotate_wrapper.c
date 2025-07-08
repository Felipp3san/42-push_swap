/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:32:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 10:48:51 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_a(t_data *data)
{
	rotate_a(&data->a);
	store_op(data, ra);
}

void	ps_rotate_b(t_data *data)
{
	rotate_b(&data->b);
	store_op(data, rb);
}

void	ps_rotate_a_b(t_data *data)
{
	rotate_a_b(&data->a, &data->b);
	store_op(data, rr);
}
