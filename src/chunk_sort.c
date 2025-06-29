/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:11:28 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 22:53:46 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_chunks(t_loc loc, t_chunks *chunks);

void	rec_chunk_sort(t_ps *data, t_chunk *chunk)
{
	t_chunks chunks;

	init_chunks(chunk->loc, &chunks);
	if (chunk->size <= 3)
	{
		if (chunk->size == 3)
			sort_three(data, chunk);
		else if (chunk->size == 2)
			sort_two(data, chunk);
		else if (chunk->size == 1)
			sort_one(data, chunk);
		return ;
	}
	chunk_split(data, chunk, &chunks);
	rec_chunk_sort(data, &chunks.max);
	rec_chunk_sort(data, &chunks.mid);
	rec_chunk_sort(data, &chunks.min);
}

void	chunk_sort(t_ps *data)
{
	t_chunk chunk;

	chunk.loc = TOP_A;
	chunk.size = data->a.size;
	rec_chunk_sort(data, &chunk);
}

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
		swap_a(data);
	chunk->size -= 2;
}

void	sort_one(t_ps *data, t_chunk *chunk)
{
	t_loc	from;

	from = chunk->loc;
	if (from == BOTTOM_A || from == TOP_B || from == BOTTOM_B)
		move_from_to(data, from, TOP_A);
	chunk->size -= 1;
}


static void	init_chunks(t_loc loc, t_chunks *chunks)
{
	chunks->min.size = 0;
	chunks->mid.size = 0;
	chunks->max.size = 0;

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
