/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:30:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/31 14:31:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HELPERS_H
# define STACK_HELPERS_H

#include "stack_core.h"

unsigned char	is_full(t_stack *stack);
unsigned char	is_empty(t_stack *stack);

#endif
