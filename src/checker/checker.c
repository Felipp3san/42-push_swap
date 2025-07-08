/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:20:56 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 20:15:03 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	trim_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

void	get_ops(t_data *data)
{
	char	*str;
	t_op	op;

	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		trim_newline(str);
		op = op_from_str(str);
		if (op == null_op)
		{
			free(str);
			ft_dprintf(2, "Error\n");
			error(data);
		}
		store_op(data, op);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
}

void	execute_op(t_stack *a, t_stack *b, t_op op)
{
	if (op == sa)
		swap_a(a);
	else if (op == sb)
		swap_b(b);
	else if (op == ss)
		swap_a_b(a, b);
	else if (op == pa)
		push_a(a, b);
	else if (op == pb)
		push_b(a, b);
	else if (op == ra)
		rotate_a(a);
	else if (op == rb)
		rotate_b(b);
	else if (op == rr)
		rotate_a_b(a, b);
	else if (op == rra)
		reverse_rotate_a(a);
	else if (op == rrb)
		reverse_rotate_b(b);
	else if (op == rrr)
		reverse_rotate_a_b(a, b);
}

void	apply_ops(t_data *data)
{
	t_list	*next;
	t_stack	*a;
	t_stack	*b;
	t_op	op;

	a = &data->a;
	b = &data->b;
	next = data->op_list;
	while (next)
	{
		op = *(t_op *)next->content;
		execute_op(a, b, op);
		next = next->next;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*arg_list;
	size_t	size;

	if (argc > 1)
	{
		arg_list = parse_args(argv, argc);
		validate_args(&arg_list);
		size = ft_lstsize(arg_list);
		init_data(&data, size);
		fill_stack(&data, arg_list);
		ft_lstclear(&arg_list, free);
		normalize_stack(&data.a);
		get_ops(&data);
		apply_ops(&data);
		if (is_empty(&data.b)
			&& is_sorted(&data.a, ASC))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		clear_data(&data);
	}
	return (EXIT_SUCCESS);
}
