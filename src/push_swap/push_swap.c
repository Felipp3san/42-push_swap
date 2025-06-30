/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:38:31 by fde-alme         ###   ########.fr       */
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

void	sort(t_stacks *data)
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
	t_stacks	data;
	size_t		size;

	if (argc > 1)
	{
		size = argc - 1;
		init_stacks(&data, size);
		fill_stack(&data.a, argv);
		normalize_stack(&data.a);
		sort(&data);
		print_ops(&data);
		clear_stacks(&data);
	}
	return (EXIT_SUCCESS);
}
