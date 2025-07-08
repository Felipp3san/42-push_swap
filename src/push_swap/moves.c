/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:54 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:53:09 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_top_a(t_data *data, t_loc to);
static void	move_from_bottom_a(t_data *data, t_loc to);
static void	move_from_top_b(t_data *data, t_loc to);
static void	move_from_bottom_b(t_data *data, t_loc to);

int	move_from_to(t_data *data, t_loc from, t_loc to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}

static void	move_from_top_a(t_data *data, t_loc to)
{
	if (to == BOTTOM_A)
		ps_rotate_a(data);
	else if (to == TOP_B)
		ps_push_b(data);
	else if (to == BOTTOM_B)
	{
		ps_push_b(data);
		if (!is_empty(&data->b))
			ps_rotate_b(data);
	}
}

static void	move_from_bottom_a(t_data *data, t_loc to)
{
	if (to == TOP_A)
		ps_reverse_rotate_a(data);
	else if (to == TOP_B)
	{
		ps_reverse_rotate_a(data);
		ps_push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		ps_reverse_rotate_a(data);
		ps_push_b(data);
		ps_rotate_b(data);
	}
}

static void	move_from_top_b(t_data *data, t_loc to)
{
	if (to == BOTTOM_B)
		ps_rotate_b(data);
	else if (to == TOP_A)
		ps_push_a(data);
	else if (to == BOTTOM_A)
	{
		ps_push_a(data);
		ps_rotate_a(data);
	}
}

static void	move_from_bottom_b(t_data *data, t_loc to)
{
	if (to == TOP_B)
		ps_reverse_rotate_b(data);
	else if (to == TOP_A)
	{
		ps_reverse_rotate_b(data);
		ps_push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		ps_reverse_rotate_b(data);
		ps_push_a(data);
		ps_rotate_a(data);
	}
}
