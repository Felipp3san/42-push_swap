/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:30 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 10:48:59 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_a(t_data *data)
{
	swap_a(&data->a);
	store_op(data, sa);
}

void	ps_swap_b(t_data *data)
{
	swap_b(&data->b);
	store_op(data, sb);
}

void	ps_swap_a_b(t_data *data)
{
	swap_a_b(&data->a, &data->b);
	store_op(data, ss);
}
