/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/29 18:57:33 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack *stack)
{
	int		is_sorted;
	size_t	i;

	i = 0;
	is_sorted = 1;
	while (i < stack->size - 1)
	{
		if (stack->collection[i] < stack->collection[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	return (is_sorted);
}

int	normalize_stack(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		*new_coll;

	new_coll = (int *) ft_calloc(stack->size, sizeof(int));
	if (!new_coll)
		return (-1);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->collection[j] < stack->collection[i])
				new_coll[i] += 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
		stack->collection[i] = new_coll[i], i++;
	return (free(new_coll), 0);
}

/* get the max number bit count ex: decimal 10 = binary 1010 and is 4 bits */
size_t	max_nbr_bitsize(t_stack *stack)
{
	int		max_nbr;
	int		bits;
	size_t	i;

	i = 1;
	max_nbr = stack->collection[0];
	while (i < stack->size)
	{
		if (stack->collection[i] > max_nbr)
			max_nbr = stack->collection[i];
		i++;
	}
	bits = 0;
	while (max_nbr > 0)
	{
		max_nbr >>= 1;
		bits++;
	}
	return (bits);
}

/* Verify if all bits in the current shift starts 
 * with 0's and end with 1's or if are all 1's */
int	check_bit_uniformity(t_stack *stack, int bit_shift)
{
	int		last_bit;
	int		bit_changes;
	ssize_t	i;

	bit_changes = 0;
	i = stack->size - 1;
	last_bit = stack->collection[i--] >> bit_shift & 1;
	if (last_bit == 1)
		return (0);
	while (i >= 0)
	{
		if ((stack->collection[i] >> bit_shift & 1) != last_bit)
		{
			last_bit = stack->collection[i] >> bit_shift & 1;
			bit_changes++;
		}
		if (bit_changes > 1)
			return (0);
		i--;
	}
	return (1);
}

size_t	radix_sort(t_stack *a, t_stack *b)
{
	int		bit_shift;
	int		bit_limit;
	size_t	top_idx;
	size_t	steps;

	steps = 0;
	bit_shift = 0;
	bit_limit = max_nbr_bitsize(a);
	while ((bit_shift <= bit_limit) && !is_sorted(a))
	{
		top_idx = a->size - 1;
		while (!check_bit_uniformity(a, bit_shift))
		{
			if(a->collection[top_idx] >> bit_shift & 1)
				rotate_a(a);
			else
			{
				push_b(a, b);
				top_idx--;
			}
			steps++;
		}
		while (!is_empty(b))
		{
			push_a(a, b);
			steps++;
		}
		bit_shift++;
	}
	return (steps);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	max;

	if (a->size == 0 && b->size == 0)
	{
		ft_printf("Stacks are empty!\n");
		return ;
	}
	if (a->size > b->size)
		max = a->size - 1;
	else
		max = b->size - 1;
	i = 0;
	while (i <= max)
	{
		if (a->size > i)
			ft_printf("%-10d", a->collection[(a->size - 1) - i]);
		ft_printf("||");
		if (b->size > i)
			ft_printf("%10d", b->collection[(b->size - 1) - i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("-----------------------\n");
	ft_printf("     a    ||     b    \n\n", 'a', 'b');
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*collection;
	size_t	capacity;
	size_t	i;

	if (argc > 1)
	{
		capacity = argc - 1;
		a = create_stack(capacity);
		b = create_stack(capacity);
		collection = (int *) malloc(sizeof(int) * capacity);
		i = 0;
		while (i < capacity)
		{
			collection[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		i = 0;
		while (i < capacity)
		{
			push(a, collection[i]);
			i++;
		}
		normalize_stack(a);
		print_stacks(a, b);
		printf("Instructions required: %lu\n", radix_sort(a, b));
		printf("===========================\n");
		print_stacks(a, b);
		destroy_stack(a);
		destroy_stack(b);
		free(collection);
		collection = NULL;
	}
	return (0);
}
