/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:57:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/07/08 10:41:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static t_bool	is_valid_numeric_string(char *str);
static t_bool	in_range(char *str);
static t_bool	is_unique(t_list *arg_list, char *str);

void	validate_args(t_list **arg_list)
{
	t_list	*node;
	char	*str;
	t_bool	err;

	err = FALSE;
	node = *arg_list;
	while (node)
	{
		str = (char *) node->content;
		if (!is_valid_numeric_string(str))
			err = TRUE;
		if (!err && !in_range(str))
			err = TRUE;
		if (!err && !is_unique(node, str))
			err = TRUE;
		node = node->next;
	}
	if (err == TRUE)
	{
		ft_lstclear(arg_list, free);
		ft_dprintf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
}

static t_bool	in_range(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	is_unique(t_list *arg_list, char *str)
{
	t_list	*next;
	int		next_nbr;
	int		nbr;

	nbr = ft_atoi(str);
	next = arg_list->next;
	while (next)
	{
		next_nbr = ft_atoi((char *) next->content);
		if (nbr == next_nbr)
			return (FALSE);
		next = next->next;
	}
	return (TRUE);
}

static t_bool	is_valid_numeric_string(char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (FALSE);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
