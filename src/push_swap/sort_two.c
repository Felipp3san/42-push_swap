/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:41:14 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:17:06 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "wrappers.h"

void	sort_two(t_ps *data, t_chunk *chunk)
{
	t_loc	from;

	from = chunk->loc;
	if (from == BOTTOM_A || from == TOP_B || from == BOTTOM_B)
	{
		move_from_to(data, from, TOP_A);
		move_from_to(data, from, TOP_A);
	}
	if (value_from_top(&data->a, 0) > value_from_top(&data->a, 1))
		ps_swap_a(data);
	chunk->size -= 2;
}
