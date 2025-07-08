/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:38:10 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:45:11 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"
# include "stack_core.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
}	t_data;

#endif
