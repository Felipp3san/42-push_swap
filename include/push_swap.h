/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:34:40 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:36:09 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_core.h"
# include "libft.h"

typedef enum e_dir
{
	ASC,
	DESC
}	t_dir;

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef enum e_op
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}	t_op;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef struct s_chunks
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_chunks;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
}	t_ps;

// push_swap_utils.c
int		normalize_stack(t_stack *stack);
void	error(t_ps *data);
void	clear_ps(t_ps *data);
void	init_ps(t_ps *data, size_t capacity);
t_bool	is_sorted(t_stack *stack, t_dir direction);

// easy_sort.c
void	easy_sort_three(t_ps *data);
void	easy_sort_five(t_ps *data);

// chunk_utils.c
t_stack	*loc_to_stack(t_ps *data, t_loc loc);
int		chunk_value(t_ps *data, t_chunk *chunk);
int		chunk_max_value(t_ps *data, t_chunk *chunk);
void	init_chunks(t_loc loc, t_chunks *chunks);
void	init_sizes(t_chunks *chunks);

// chunk_sort.c
void	chunk_sort(t_ps *data);

// chunk_split.c
void	chunk_split(t_ps *data, t_chunk *chunk, t_chunks *dest);

// moves.c
int		move_from_to(t_ps *data, t_loc from, t_loc to);

// sort_two.c
void	sort_two(t_ps *data, t_chunk *chunk);

// sort_tree.c
void	sort_three(t_ps *data, t_chunk *chunk);

// op_list.c
void	store_op(t_ps *data, t_op op);
void	print_ops(t_ps *data);
void	optimize_ops(t_ps *data);

#endif
