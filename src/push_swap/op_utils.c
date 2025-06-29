/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:05:08 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 23:03:15 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_to_str(int op)
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

void	print_ops(t_ps *data)
{
	t_list *op;

	op = data->op_list;
	while (op)
	{
		ft_printf("%s\n", op_to_str((uintptr_t)op->content));
		op = op->next;
	}
}

void	store_op(t_ps *data, t_op op)
{
	t_list	*node;

	node = ft_lstnew((void *) op);
	if (!node)
		error(data);
	ft_lstadd_back(&data->op_list, node);
}

void	optimize_ops(t_ps *data)
{
	(void) data;
}
