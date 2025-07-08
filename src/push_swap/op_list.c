/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:21:46 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:49:23 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_data *data)
{
	t_list	*op;

	op = data->op_list;
	while (op)
	{
		ft_printf("%s\n", op_to_str(*(t_op *)op->content));
		op = op->next;
	}
}

void	optimize_ops(t_data *data)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*node;
	t_op	new_op;
	t_op	op;

	new_list = NULL;
	node = data->op_list;
	while (node)
	{
		op = *(t_op *) node->content;
		new_op = combine_op_pair(op, node->next);
		new_node = new_op_node(new_op);
		if (!new_node)
		{
			ft_lstclear(&new_list, free);
			error(data);
		}
		ft_lstadd_back(&new_list, new_node);
		node = node->next;
		if (new_op != op && node != NULL)
			node = node->next;
	}
	ft_lstclear(&data->op_list, free);
	data->op_list = new_list;
}

t_op	combine_op_pair(t_op op, t_list *next)
{
	t_op	next_op;
	t_op	new_op;

	if (!next || !next->content)
		return (op);
	next_op = *(t_op *) next->content;
	if ((op == sa && next_op == sb) || (op == sb && next_op == sa))
		new_op = ss;
	else if ((op == ra && next_op == rb) || (op == rb && next_op == ra))
		new_op = rr;
	else if ((op == rra && next_op == rrb) || (op == rrb && next_op == rra))
		new_op = rrr;
	else
		new_op = op;
	return (new_op);
}
