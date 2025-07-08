/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:09:51 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:52:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_pivots(t_chunk *chunk, int	*pivot_mid, int *pivot_max);

void	chunk_split(t_data *data, t_chunk *chunk, t_chunks *dest)
{
	int	pivot_max;
	int	pivot_mid;
	int	max_value;
	int	next_value;

	find_pivots(chunk, &pivot_mid, &pivot_max);
	max_value = chunk_max_value(data, chunk);
	while (chunk->size--)
	{
		next_value = chunk_value(data, chunk);
		if (next_value > max_value - pivot_max)
			dest->max.size += move_from_to(data, chunk->loc, dest->max.loc);
		else if (next_value > max_value - pivot_mid)
			dest->mid.size += move_from_to(data, chunk->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, chunk->loc, dest->min.loc);
	}
}

static void	find_pivots(t_chunk *chunk, int	*pivot_mid, int *pivot_max)
{
	*pivot_mid = (chunk->size / 3) * 2;
	*pivot_max = chunk->size / 3;
}
