/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:40:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 18:42:44 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"

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

t_list	*new_op_node(t_op op)
{
	t_list	*node;
	t_op	*op_ptr;

	op_ptr = (t_op *) malloc(sizeof(t_op));
	if (!op_ptr)
		return (NULL);
	*op_ptr = op;
	node = ft_lstnew((void *) op_ptr);
	if (!node)
	{
		free(op_ptr);
		return (NULL);
	}
	return (node);
}

const char	*op_to_str(t_op op)
{
	const char	*ops[12] = {
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
