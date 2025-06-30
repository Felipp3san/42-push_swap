/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:13:09 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:21:01 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CORE_H
# define STACK_CORE_H

#include "libft.h"

# define MALLOC_ERROR -1
# define SUCCESS 0

typedef enum e_dir
{
	ASC,
	DESC
}	t_dir;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* Top is the last element of the stack size - 1.
 * Bottom is the first element from the stack. 0 */
typedef struct s_stack {
	int		*collection;
	size_t	capacity;
	size_t	size;
	ssize_t	top;
	ssize_t	bottom;
}	t_stack;

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

typedef struct s_stacks 
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
}	t_stacks;

// stack_core.c
void	init_stacks(t_stacks *data, size_t capacity);
void	push(t_stack *stack, int item);
void	pop(t_stack *stack, int *item);
t_bool	is_full(t_stack *stack);
t_bool	is_empty(t_stack *stack);

// stack_utils.c
int		value_from_top(t_stack *stack, int position);
int		normalize_stack(t_stack *stack);
size_t	next_down(size_t idx);
size_t	next_up(t_stack *stk, size_t idx);
t_bool	is_sorted(t_stack *stack, t_dir direction);

// stack_cleanup.c
void	clear_stacks(t_stacks *data);
void	error(t_stacks *data);

// op_utils.c
void	store_op(t_stacks *data, t_op op);
void	print_ops(t_stacks *data);
void	optimize_ops(t_stacks *data);

// swap.c
void	swap_a(t_stacks *data);
void	swap_b(t_stacks *data);
void	swap_ab(t_stacks *data);

// push.c
void	push_a(t_stacks *data);
void	push_b(t_stacks *data);

// rotate.c
void	rotate_a(t_stacks *data);
void	rotate_b(t_stacks *data);
void	rotate_a_b(t_stacks *data);

// reverse.c
void	reverse_rotate_a(t_stacks *data);
void	reverse_rotate_b(t_stacks *data);
void	reverse_rotate_a_b(t_stacks *data);

#endif
