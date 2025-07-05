/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:50:57 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/05 19:58:40 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_split(char **arr);
static void		add_to_list(t_list **arg_list, char **numbers);

t_list	*parse_args(char *argv[], int argc)
{
	t_list	*arg_list;
	char	**numbers;
	int		i;

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
		add_to_list(&arg_list, numbers);
		free_split(numbers);
		i++;
	}
	return (arg_list);
}

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	add_to_list(t_list **arg_list, char **numbers)
{
	t_list	*node;
	char	*content;
	int		i;

	i = 0;
	while (numbers[i])
	{
		content = ft_strdup(numbers[i]);
		if (!content)
		{
			free_split(numbers);
			ft_lstclear(arg_list, free);
			exit(EXIT_FAILURE);
		}
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			free_split(numbers);
			ft_lstclear(arg_list, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(arg_list, node);
		i++;
	}
}
