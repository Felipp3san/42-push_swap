/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:34:35 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:54:13 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"
# include "types.h"
# include "stack_core.h"

// stack_utils.c
void		fill_stack(t_data *data, t_list *arg_list);
int			normalize_stack(t_stack *stack);
t_bool		is_sorted(t_stack *stack, t_dir direction);

// program_utils.c
void		error(t_data *data);
void		clear_data(t_data *data);
void		init_data(t_data *data, size_t capacity);

// parser.c
t_list		*parse_args(char *argv[], int argc);

// validation.c
void		validate_args(t_list **arg_list);

// op_utils.c
const char	*op_to_str(t_op op);
t_list		*new_op_node(t_op op);
void		store_op(t_data *data, t_op op);
t_op		op_from_str(char *str);

#endif
