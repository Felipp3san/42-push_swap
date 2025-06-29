/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:34:40 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 22:54:01 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "stack_core.h"

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
}	t_ps;

typedef enum e_dir
{
	ASC,
	DESC
}	t_dir;

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

// push_swap.c
void	error(t_ps *data);

// op_utils.c
void		store_op(t_ps *data, t_op op);
void		print_ops(t_ps *data);
const char	*op_to_str(int op);

// push_swap_utils.c
t_bool	is_sorted(t_stack *stack, t_dir direction);
int		normalize_stack(t_stack *stack);

// stack_utils.c
int		value_from_top(t_stack *stack, int position);
size_t	next_down(size_t idx);
size_t	next_up(t_stack *stk, size_t idx);

// swap.c
void	swap_a(t_ps *data);
void	swap_b(t_ps *data);
void	swap_ab(t_ps *data);

// push.c
void	push_a(t_ps *data);
void	push_b(t_ps *data);

// rotate.c
void	rotate_a(t_ps *data);
void	rotate_b(t_ps *data);
void	rotate_a_b(t_ps *data);

// reverse.c
void	reverse_rotate_a(t_ps *data);
void	reverse_rotate_b(t_ps *data);
void	reverse_rotate_a_b(t_ps *data);

// easy_sort.c
//void	sort_two(t_ps *data);
void	sort_five(t_ps *data);

// moves.c
int		move_from_to(t_ps *data, t_loc from, t_loc to);

// sort_tree.c
void	sort_three(t_ps *data, t_chunk *chunk);

// chunk_utils.c
int		chunk_value(t_ps *data, t_chunk *chunk);
int		chunk_max_value(t_ps *data, t_chunk *chunk);
t_stack	*loc_to_stack(t_ps *data, t_loc loc);

// chunk_sort.c
void	chunk_sort(t_ps *data);
void	sort_two(t_ps *data, t_chunk *chunk);
void	sort_one(t_ps *data, t_chunk *chunk);

// chunk_split.c
void	chunk_split(t_ps *data, t_chunk *chunk, t_chunks *dest);

#endif
