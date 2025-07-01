/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:41:44 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 18:45:07 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_UTILS_H
# define OP_UTILS_H

# include "push_swap.h"

const char	*op_to_str(t_op op);
t_list		*new_op_node(t_op op);
t_op		combine_op_pair(t_op op, t_list *next);

#endif
