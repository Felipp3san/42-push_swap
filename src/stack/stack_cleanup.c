/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:43:27 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/30 12:13:30 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_core.h"

void	clear_stacks(t_stacks *data)
{

	if (data->a.collection)
		free(data->a.collection);
	if (data->b.collection)
		free(data->b.collection);
	if (data->op_list)
		ft_lstclear(&data->op_list, free);
}

void error(t_stacks *data)
{
	clear_stacks(data);
	exit(EXIT_FAILURE);
}
