/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:51:34 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:27:53 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_top_a(t_stacks *data, t_chunk *chunk, int max);
static void	sort_three_bottom_a(t_stacks *data, t_chunk *chunk, int max);
static void	sort_three_top_b(t_stacks *data, t_chunk *chunk, int max);
static void	sort_three_bottom_b(t_stacks *data, t_chunk *chunk, int max);

void	sort_three(t_stacks *data, t_chunk *chunk)
{
	int		max_value;

	max_value = chunk_max_value(data, chunk);
	if (chunk->loc == TOP_A)
		sort_three_top_a(data, chunk, max_value);
	else if (chunk->loc == BOTTOM_A)
		sort_three_bottom_a(data, chunk, max_value);
	else if (chunk->loc == TOP_B)
		sort_three_top_b(data, chunk, max_value);
	else if (chunk->loc == BOTTOM_B)
		sort_three_bottom_b(data, chunk, max_value);
}

static void	sort_three_top_a(t_stacks *data, t_chunk *chunk, int max)
{
	t_stack	*stack;

	stack = &data->a;
	if (stack->collection[stack->top] == max)
	{
		swap_a(data);
		push_b(data);
		swap_a(data);
		push_a(data);
	}
	else if (stack->collection[stack->top - 1] == max)
	{
		push_b(data);
		swap_a(data);
		push_a(data);
	}
	chunk->loc = TOP_A;
	chunk->size -= 1;
	sort_two(data, chunk);
}

static void	sort_three_bottom_a(t_stacks *data, t_chunk *chunk, int max)
{
	t_stack	*stack;

	stack = &data->a;
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	if (stack->collection[stack->top] == max)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stack->collection[stack->top - 1] == max)
		reverse_rotate_a(data);
	else
	{
		push_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	chunk->loc = TOP_A;
	chunk->size -= 1;
	sort_two(data, chunk);
}

void	sort_three_top_b(t_stacks *data, t_chunk *chunk, int max)
{
	t_stack	*stack;

	stack = &data->b;
	push_a(data);
	if (stack->collection[stack->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stack->collection[stack->top - 1] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
		push_a(data);
	push_a(data);
	chunk->loc = TOP_A;
	chunk->size -= 1;
	sort_two(data, chunk);
}

static void	sort_three_bottom_b(t_stacks *data, t_chunk *chunk, int max)
{
	t_stack	*stack;

	stack = &data->b;
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	if (stack->collection[stack->top] == max)
	{
		push_a(data);
		reverse_rotate_b(data);
	}
	else if (stack->collection[stack->top - 1] == max)
	{
		swap_b(data);
		push_a(data);
		reverse_rotate_b(data);
	}
	else
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	chunk->loc = TOP_B;
	chunk->size -= 1;
	sort_two(data, chunk);
}
