/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:05:08 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:20:14 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

static const char	*op_to_str(t_op op)
{
	const char *ops[12] = {
		"null_op",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		"sa",
		"sb",
		"ss"
	};

	return (ops[op]);
}

void	print_ops(t_stacks *data)
{
	t_list *op;

	op = data->op_list;
	while (op)
	{
		ft_printf("%s\n", op_to_str(*(t_op *)op->content));
		op = op->next;
	}
}

void	store_op(t_stacks *data, t_op op)
{
	t_list	*node;
	t_op	*op_ptr;

	op_ptr = (t_op *) malloc(sizeof(t_op));
	if (!op_ptr)
		error(data);
	*op_ptr = op;
	node = ft_lstnew((void *) op_ptr);
	if (!node)
	{
		free(op_ptr);
		error(data);
	}
	ft_lstadd_back(&data->op_list, node);
}

void	optimize_ops(t_stacks *data)
{
	(void) data;
}
