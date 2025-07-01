/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:10:03 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:20:09 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "push_swap.h"

void	ps_swap_a(t_ps *data);
void	ps_swap_b(t_ps *data);
void	ps_swap_a_b(t_ps *data);
void	ps_push_a(t_ps *data);
void	ps_push_b(t_ps *data);
void	ps_rotate_a(t_ps *data);
void	ps_rotate_b(t_ps *data);
void	ps_rotate_a_b(t_ps *data);
void	ps_reverse_rotate_a(t_ps *data);
void	ps_reverse_rotate_b(t_ps *data);
void	ps_reverse_rotate_a_b(t_ps *data);

#endif
