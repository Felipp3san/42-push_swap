/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:03:59 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:16:31 by fde-alme         ###   ########.fr       */
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
