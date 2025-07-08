/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:11:28 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:52:05 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_one(t_data *data, t_chunk *chunk);
static void	rec_chunk_sort(t_data *data, t_chunk *chunk);

void	chunk_sort(t_data *data)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = data->a.size;
	rec_chunk_sort(data, &chunk_all);
}

static void	rec_chunk_sort(t_data *data, t_chunk *chunk)
{
	t_chunks	chunks;

	init_chunks(chunk->loc, &chunks);
	init_sizes(&chunks);
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

static void	sort_one(t_data *data, t_chunk *chunk)
{
	t_loc	from;

	from = chunk->loc;
	if (from == BOTTOM_A || from == TOP_B || from == BOTTOM_B)
		move_from_to(data, from, TOP_A);
	chunk->size -= 1;
}
