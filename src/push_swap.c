/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/28 20:44:44 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	ssize_t	i;

	if (stack->size == 0)
	{
		ft_printf("Stack is empty! \n");
		return ;
	}
	i = stack->size - 1;
	ft_printf("|==== STACK =====|\n");
	while (i >= 0)
	{
		ft_printf("|== %d ==|\n", stack->collection[i]);
		i--;
	}
	ft_printf("|================|\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	size_t	capacity;
	size_t		i;
	int		*collection;
	int		result;

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
			push(b, collection[i]);
			i++;
		}

		print_stack(a);

		while(a->size != 0)
		{
			pop(a, &result);
			ft_printf("Popped number: %d\n", result);
		}
		print_stack(a);
		push(a, 999);
		ft_printf("\n");
		print_stack(a);

		destroy_stack(a);
		destroy_stack(b);
		free(collection);
		collection = NULL;
	}
	return (0);
}
