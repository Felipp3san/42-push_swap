/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 11:54:37 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	if (data->a.size <= 1 || is_sorted(&data->a, ASC))
		return ;
	if (data->a.size == 3)
		easy_sort_three(data);
	else if (data->a.size == 5)
		easy_sort_five(data);
	else
		chunk_sort(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*arg_list;
	size_t	size;

	if (argc > 1)
	{
		arg_list = parse_args(argv, argc);
		validate_args(&arg_list);
		size = ft_lstsize(arg_list);
		init_data(&data, size);
		fill_stack(&data, arg_list);
		ft_lstclear(&arg_list, free);
		normalize_stack(&data.a);
		sort(&data);
		optimize_ops(&data);
		print_ops(&data);
		clear_data(&data);
	}
	return (EXIT_SUCCESS);
}
