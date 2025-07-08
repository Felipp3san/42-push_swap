/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:34:40 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:50:55 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

// easy_sort.c
void	easy_sort_three(t_data *data);
void	easy_sort_five(t_data *data);

// chunk_utils.c
t_stack	*loc_to_stack(t_data *data, t_loc loc);
int		chunk_value(t_data *data, t_chunk *chunk);
int		chunk_max_value(t_data *data, t_chunk *chunk);
void	init_chunks(t_loc loc, t_chunks *chunks);
void	init_sizes(t_chunks *chunks);

// chunk_sort.c
void	chunk_sort(t_data *data);

// chunk_split.c
void	chunk_split(t_data *data, t_chunk *chunk, t_chunks *dest);

// moves.c
int		move_from_to(t_data *data, t_loc from, t_loc to);

// sort_two.c
void	sort_two(t_data *data, t_chunk *chunk);

// sort_tree.c
void	sort_three(t_data *data, t_chunk *chunk);

// op_list.c
void	print_ops(t_data *data);
void	optimize_ops(t_data *data);
t_op	combine_op_pair(t_op op, t_list *next);

// wrappers
void	ps_swap_a(t_data *data);
void	ps_swap_b(t_data *data);
void	ps_swap_a_b(t_data *data);
void	ps_push_a(t_data *data);
void	ps_push_b(t_data *data);
void	ps_rotate_a(t_data *data);
void	ps_rotate_b(t_data *data);
void	ps_rotate_a_b(t_data *data);
void	ps_reverse_rotate_a(t_data *data);
void	ps_reverse_rotate_b(t_data *data);
void	ps_reverse_rotate_a_b(t_data *data);

#endif
