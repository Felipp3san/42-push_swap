/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:13:09 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 14:31:29 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CORE_H
# define STACK_CORE_H

# include <stddef.h>
# include <stdlib.h>

# define MALLOC_ERROR -1
# define SUCCESS 0

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

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

typedef struct s_stack {
	int		*collection;
	size_t	capacity;
	size_t	size;
	ssize_t	top;
	ssize_t	bottom;
}	t_stack;

int		init_stack(t_stack *stack, size_t size);
t_bool	is_full(t_stack *stack);
t_bool	is_empty(t_stack *stack);
void	push(t_stack *stack, int item);
void	pop(t_stack *stack, int *item);

#endif
