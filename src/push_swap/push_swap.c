/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/04 14:51:52 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	fill_stack(t_ps *data, t_list *arg_list)
{
	t_stack	*a;
	t_stack	*b;

	a = &data->a;
	b = &data->b;
	while (arg_list)
	{
		push(b, ft_atoi((char *)arg_list->content));
		arg_list = arg_list->next;
	}
	while (!is_empty(b))
		push_a(a, b);
}

void	sort(t_ps *data)
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
	t_ps	data;
	t_list	*arg_list;
	size_t	size;

	if (argc > 1)
	{
		arg_list = parse_args(argv, argc);
		validate_args(&arg_list);
		size = ft_lstsize(arg_list);
		init_ps(&data, size);
		fill_stack(&data, arg_list);
		ft_lstclear(&arg_list, free);
		normalize_stack(&data.a);
		sort(&data);
		optimize_ops(&data);
		print_ops(&data);
		clear_ps(&data);
	}
	return (EXIT_SUCCESS);
}
