/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:59:53 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 16:20:49 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumber(char *val)
{
	if (*val == '-' || *val == '+')
		val++;
	if (*val == '\0')
		return (0);
	while (*val)
	{
		if (!ft_isdigit(*val))
			return (0);
		val++;
	}
	return (1);
}

static int	ft_process_split(t_list **stack, char **splt)
{
	t_list	*new;
	int		*nbr;
	int		i;

	i = 0;
	if (!splt[i])
		return (0);
	while (splt[i])
	{
		if (!ft_isnumber(splt[i]))
			return (0);
		nbr = malloc(sizeof(int));
		if (!nbr)
			return (0);
		*nbr = ft_atoi(splt[i]);
		new = ft_lstnew(nbr);
		if (!new)
		{
			free(nbr);
			return (0);
		}
		ft_lstadd_back(stack, new);
		free(splt[i++]);
	}
	return (1);
}

t_list	*ft_parse_numbers(char **argv)
{
	t_list	*stack;
	char	**splt;

	stack = NULL;
	while (*argv)
	{
		splt = ft_split(*argv++, ' ');
		if (!splt)
			return (NULL);
		if (!ft_process_split(&stack, splt))
			return (NULL);
		free(splt);
	}
	return (stack);
}
