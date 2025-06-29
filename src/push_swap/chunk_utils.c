/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:57:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 23:11:30 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*loc_to_stack(t_ps *data, t_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}

int	chunk_value(t_ps *data, t_chunk *chunk)
{
	t_stack *stack;
	t_loc	from;

	from = chunk->loc;
	stack = loc_to_stack(data, from);
	if (from == TOP_A || from == TOP_B)
		return (stack->collection[stack->top]);
	else
		return (stack->collection[stack->bottom]);
}

int	chunk_max_value(t_ps *data, t_chunk *chunk)
{
	t_stack	*stack;
	size_t	size;
	size_t	i;
	int		max;

	stack = loc_to_stack(data, chunk->loc);
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stack->top;
	else
		i = stack->bottom;
	max = 0;
	size = chunk->size;
	while (size--)
	{
		if (stack->collection[i] > max)
			max = stack->collection[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(i);
		if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(stack, i);
	}
	return (max);
}

void	init_sizes(t_chunks *chunks)
{
	chunks->min.size = 0;
	chunks->mid.size = 0;
	chunks->max.size = 0;
}

void	init_chunks(t_loc loc, t_chunks *chunks)
{
	if (loc == TOP_A)
	{
		chunks->max.loc = BOTTOM_A;
		chunks->mid.loc = TOP_B;
		chunks->min.loc = BOTTOM_B;
	}
	else if (loc == BOTTOM_A)
	{
		chunks->max.loc = TOP_A;
		chunks->mid.loc = TOP_B;
		chunks->min.loc = BOTTOM_B;
	}
	else if (loc == TOP_B)
	{
		chunks->max.loc = TOP_A;
		chunks->mid.loc = BOTTOM_A;
		chunks->min.loc = BOTTOM_B;
	}
	else
	{
		chunks->max.loc = TOP_A;
		chunks->mid.loc = BOTTOM_A;
		chunks->min.loc = TOP_B;
	}
}
