/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:39:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/01 15:47:19 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_list	*parse_arguments(char *argv[], int argc)
{
	char	**numbers;
	char	*content;
	t_list	*arg_list;
	t_list	*node;
	int		i;
	int		j;
	
	i = 1;
	arg_list = NULL;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
		{
			ft_lstclear(&arg_list, free);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (numbers[j])
		{
			content = ft_strdup(numbers[j]);
			if (!content)
			{
				free_split(numbers);
				ft_lstclear(&arg_list, free);
				exit(EXIT_FAILURE);
			}
			node = ft_lstnew(content);
			if (!node)
			{
				free(content);
				free_split(numbers);
				ft_lstclear(&arg_list, free);
				exit(EXIT_FAILURE);
			}
			ft_lstadd_back(&arg_list, node);
			j++;
		}
		free_split(numbers);
		i++;
	}
	return (arg_list);
}

void	fill_stack(t_stack *stack, t_list *arg_list)
{
	while (arg_list)
	{
		push(stack, ft_atoi((char *)arg_list->content));
		arg_list = arg_list->next;
	}
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
		arg_list = parse_arguments(argv, argc);
		size = ft_lstsize(arg_list);
		init_ps(&data, size);
		fill_stack(&data.a, arg_list);
		ft_lstclear(&arg_list, free);
		normalize_stack(&data.a);
		sort(&data);
		optimize_ops(&data);
		print_ops(&data);
		clear_ps(&data);
	}
	return (EXIT_SUCCESS);
}
