/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:13:09 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/28 20:41:00 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_stack {
	int		*collection;
	size_t	capacity;
	size_t	size;
}	t_stack;

t_stack			*create_stack(size_t capacity);
void			destroy_stack(t_stack *stack);
unsigned char	is_full(t_stack	*stack);
unsigned char	is_empty(t_stack	*stack);
unsigned char	push(t_stack *stack, int item);
unsigned char	pop(t_stack *stack, int	*item);

#endif
