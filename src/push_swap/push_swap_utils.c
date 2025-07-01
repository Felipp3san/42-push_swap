/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:45:10 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:44:26 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_ps *data)
{
	clear_ps(data);
	exit(EXIT_FAILURE);
}

void	clear_ps(t_ps *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	ft_lstclear(&data->op_list, free);
}

void	init_ps(t_ps *data, size_t capacity)
{
	if (init_stack(&data->a, capacity) == MALLOC_ERROR)
		error(data);
	if (init_stack(&data->b, capacity) == MALLOC_ERROR)
		error(data);
	data->op_list = NULL;
}

/* Counts how many numbers are smaller than element, and replace it 
 * with the count. */
int	normalize_stack(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		*new_values;

	new_values = (int *) ft_calloc(stack->size, sizeof(int));
	if (!new_values)
		return (MALLOC_ERROR);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->collection[j] < stack->collection[i])
				new_values[i] += 1;
			j++;
		}
		i++;
	}
	free(stack->collection);
	stack->collection = new_values;
	return (0);
}

/* Validates if the stack is sorted on specified direction */
t_bool	is_sorted(t_stack *stack, t_dir direction)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (direction == DESC)
		{
			if (stack->collection[i] > stack->collection[i + 1])
				return (FALSE);
		}
		else
		{
			if (stack->collection[i] < stack->collection[i + 1])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
