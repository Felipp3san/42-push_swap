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

# include <stdlib.h>

# define MALLOC_ERROR -1
# define SUCCESS 0

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* Top is the last element of the stack size - 1.
 * Bottom is the first element from the stack. 0 */
typedef struct s_stack
{
	int		*collection;
	size_t	capacity;
	size_t	size;
	ssize_t	top;
	ssize_t	bottom;
}	t_stack;

// stack_core.c
int		init_stack(t_stack *stack, int capacity);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int item);
void	pop(t_stack *stack, int *item);

// stack_utils.c
int		value_from_top(t_stack *stack, int position);
size_t	next_down(size_t idx);
size_t	next_up(t_stack *stk, size_t idx);
t_bool	is_full(t_stack *stack);
t_bool	is_empty(t_stack *stack);

// swap.c
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_a_b(t_stack *a, t_stack *b);

// push.c
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

// rotate.c
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_a_b(t_stack *a, t_stack *b);

// reverse.c
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_a_b(t_stack *a, t_stack *b);

#endif
