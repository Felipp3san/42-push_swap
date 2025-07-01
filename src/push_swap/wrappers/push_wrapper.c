/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:12:33 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:14:10 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ps_push_a(t_ps *data)
{
	push_a(&data->a, &data->b);
	store_op(data, pa);
}

void	ps_push_b(t_ps *data)
{
	push_b(&data->a, &data->b);
	store_op(data, pb);
}
