/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:54 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:12:34 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_top_a(t_stacks *data, t_loc to);
static void	move_from_bottom_a(t_stacks *data, t_loc to);
static void	move_from_top_b(t_stacks *data, t_loc to);
static void	move_from_bottom_b(t_stacks *data, t_loc to);

int	move_from_to(t_stacks *data, t_loc from, t_loc to)
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

static void	move_from_top_a(t_stacks *data, t_loc to)
{
	if (to == BOTTOM_A)
		rotate_a(data);
	else if (to == TOP_B)
		push_b(data);
	else if (to == BOTTOM_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

static void	move_from_bottom_a(t_stacks *data, t_loc to)
{
	if (to == TOP_A)
		reverse_rotate_a(data);
	else if (to == TOP_B)
	{
		reverse_rotate_a(data);
		push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		reverse_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

static void	move_from_top_b(t_stacks *data, t_loc to)
{
	if (to == BOTTOM_B)
		rotate_b(data);
	else if (to == TOP_A)
		push_a(data);
	else if (to == BOTTOM_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

static void	move_from_bottom_b(t_stacks *data, t_loc to)
{
	if (to == TOP_B)
		reverse_rotate_b(data);
	else if (to == TOP_A)
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		reverse_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}

