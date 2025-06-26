/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bit_uniformity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:04:55 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:16:00 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Verify if all bits in the current shift starts 
 * with 0's and end with 1's or if are all 1's */
int	check_bit_uniformity(t_stack *stack, int bit_shift)
{
	int		bit_changes;
	int		starting_bit;
	int		last_bit;
	ssize_t	i;

	bit_changes = 0;
	i = stack->size - 1;
	starting_bit = stack->collection[i--] >> bit_shift & 1;
	last_bit = starting_bit;
	while (i >= 0)
	{
		if ((stack->collection[i] >> bit_shift & 1) != last_bit)
		{
			last_bit = stack->collection[i] >> bit_shift & 1;
			bit_changes++;
		}
		if (starting_bit == 1 && bit_changes > 0)
			return (0);
		else if (starting_bit == 0 && bit_changes > 1)
			return (0);
		i--;
	}
	return (1);
}

/* Verify if all bits in the current shift starts 
 * with 0's and end with 1's or if are all 1's */
//int	check_bit_uniformity(t_stack *stack, int bit_shift)
//{
//	int		first_bit;
//	ssize_t	i;
//
//	i = stack->size - 1;
//	first_bit = stack->collection[i--] >> bit_shift & 1;
//	while (i >= 0)
//	{
//		if ((stack->collection[i] >> bit_shift & 1) != first_bit)
//			return (0);
//		i--;
//	}
//	return (1);
//}

//int	check_bit_uniformity(t_stack *stack, int bit_shift)
//{
//	int		last_bit;
//	int		bit_changes;
//	ssize_t	i;
//
//	bit_changes = 0;
//	i = stack->size - 1;
//	last_bit = stack->collection[i--] >> bit_shift & 1;
//	while (i >= 0)
//	{
//		if ((stack->collection[i] >> bit_shift & 1) == 0 && last_bit == 1)
//			return (0);
//		else if ((stack->collection[i] >> bit_shift & 1) != last_bit)
//		{
//			last_bit = stack->collection[i] >> bit_shift & 1;
//			bit_changes++;
//		}
//		if (bit_changes > 1)
//			return (0);
//		i--;
//	}
//	return (1);
//}
