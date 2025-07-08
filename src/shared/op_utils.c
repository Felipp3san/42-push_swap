
#include "shared.h"

/* Creates a new t_list node with the provided op and returns it */
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

/* Puts the newly created t_list node at the end of the op_list */
void	store_op(t_data *data, t_op op)
{
	t_list	*new_node;

	new_node = new_op_node(op);
	if (!new_node)
		error(data);
	ft_lstadd_back(&data->op_list, new_node);
}

/* Converts a t_op (ex: pa), to a str (ex: "pa") */
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

/* Converts a str (ex: "pb") to t_op (ex: pb) */
t_op	op_from_str(char *str)
{
	int	i;

	if (!str)
		return (null_op);
	i = 1;
	while (i < ss)
	{
		if (ft_strcmp(str, op_to_str(i)) == 0)
			return ((t_op)i);
		i++;
	}
	return (null_op);
}
