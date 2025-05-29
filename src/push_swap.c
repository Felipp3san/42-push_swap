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
		print_stacks(a, b);
		rotate_a(a);
		print_stacks(a, b);
		reverse_rotate_a(a);
		print_stacks(a, b);
		destroy_stack(a);
		destroy_stack(b);
		free(collection);
		collection = NULL;
	}
	return (0);
}
