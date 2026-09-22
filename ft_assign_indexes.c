/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_indexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:23:26 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 14:23:51 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_indexes(t_list *stack)
{
	t_list	*current_node;
	t_list	*first_node;
	int		index;

	current_node = stack;
	while (current_node)
	{
		index = 0;
		first_node = stack;
		while (first_node)
		{
			if (*(int *)first_node->content < *(int *)current_node->content)
				index++;
			first_node = first_node->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}
