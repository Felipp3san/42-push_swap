/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/29 19:41:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, char *argv[])
{
	size_t	i;

	i = 0;
	while (i < stack->capacity)
	{
		push(stack, ft_atoi(argv[stack->capacity - i]));
		i++;
	}
}

void	clear_program(t_ps *data)
{
	t_list *op;
	t_list *next;

	if (data->a.collection)
		free(data->a.collection);
	if (data->b.collection)
		free(data->b.collection);
	if (data->op_list)
	{
		op = data->op_list;
		while (op)
		{
			next = op->next;
			free(op);
			op = next;
		}
	}
}

void	error(t_ps *data)
{
	clear_program(data);
	exit(EXIT_FAILURE);
}

void	sort(t_ps *data)
{
	if (data->a.size <= 1 || is_sorted(&data->a, ASC))
		return ;
	if (data->a.size == 3)
		return ;
	else if (data->a.size == 5)
		sort_five(data);
	else
		chunk_sort(data);
}

int	main(int argc, char *argv[])
{
	t_ps	data;
	size_t	size;

	if (argc > 1)
	{
		size = argc - 1;
		if (init_stack(&data.a, size) == MALLOC_ERROR)
			error(&data);
		if (init_stack(&data.b, size) == MALLOC_ERROR)
			error(&data);
		fill_stack(&data.a, argv);
		normalize_stack(&data.a);
		sort(&data);
		print_ops(&data);
		clear_program(&data);
	}
	return (EXIT_SUCCESS);
}
