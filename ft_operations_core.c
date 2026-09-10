/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_core.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:56:11 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 15:22:21 by abezatog         ###   ########.fr       */
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

void	push(t_list **src, t_list **dst)
{
	t_list	*to_be_first;

	if (!src || !*src)
		return ;
	to_be_first = (*src)->next;
	ft_lstadd_front(dst, *src);
	*src = to_be_first;
}

void	rotate(t_list **lst)
{
	t_list	*to_be_first;
	t_list	*to_be_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	to_be_first = (*lst)->next;
	to_be_last = *lst;
	(*lst)->next = NULL;
	ft_lstadd_back(&to_be_first, to_be_last);
	*lst = to_be_first;
}
