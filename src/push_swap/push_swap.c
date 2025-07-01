/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:47:19 by fde-alme         ###   ########.fr       */
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

void	sort(t_ps *data)
{
	if (data->a.size <= 1 || is_sorted(&data->a, ASC))
		return ;
	if (data->a.size == 3)
		easy_sort_three(data);
	else if (data->a.size == 5)
		easy_sort_five(data);
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
		init_ps(&data, size);
		fill_stack(&data.a, argv);
		normalize_stack(&data.a);
		sort(&data);
		optimize_ops(&data);
		print_ops(&data);
		clear_ps(&data);
	}
	return (EXIT_SUCCESS);
}
