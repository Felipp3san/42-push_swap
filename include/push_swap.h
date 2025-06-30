/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:34:40 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:41:58 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stack_core.h"

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef	struct s_chunks
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_chunks;

// easy_sort.c
//void	sort_two(t_stacks *data);
void	sort_five(t_stacks *data);

// chunk_utils.c
t_stack	*loc_to_stack(t_stacks *data, t_loc loc);
int		chunk_value(t_stacks *data, t_chunk *chunk);
int		chunk_max_value(t_stacks *data, t_chunk *chunk);
void	init_chunks(t_loc loc, t_chunks *chunks);
void	init_sizes(t_chunks *chunks);

// chunk_sort.c
void	chunk_sort(t_stacks *data);

// chunk_split.c
void	chunk_split(t_stacks *data, t_chunk *chunk, t_chunks *dest);

// moves.c
int		move_from_to(t_stacks *data, t_loc from, t_loc to);

// sort_two.c
void	sort_two(t_stacks *data, t_chunk *chunk);

// sort_tree.c
void	sort_three(t_stacks *data, t_chunk *chunk);

#endif
