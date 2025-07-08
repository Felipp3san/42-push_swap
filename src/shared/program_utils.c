/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:41:25 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:46:29 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	error(t_data *data)
{
	clear_data(data);
	exit(EXIT_FAILURE);
}

void	clear_data(t_data *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	ft_lstclear(&data->op_list, free);
}

void	init_data(t_data *data, size_t capacity)
{
	if (init_stack(&data->a, capacity) == MALLOC_ERROR)
		error(data);
	if (init_stack(&data->b, capacity) == MALLOC_ERROR)
		error(data);
	data->op_list = NULL;
}
