/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_core.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:56:11 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 14:39:18 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*to_be_first;
	t_list	*third;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	to_be_first = (*lst)->next;
	third = (*lst)->next->next;
	(*lst)->next->next = *lst;
	(*lst)->next = third;
	*lst = to_be_first;
}
