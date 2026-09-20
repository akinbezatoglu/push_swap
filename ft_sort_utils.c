/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:37:21 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/20 19:07:46 by yturkeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_find_max(t_list *stack)
{
	size_t	current_idx;
	size_t	max_idx;
	int		max_val;

	current_idx = 0;
	max_idx = 0;
	max_val = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max_val)
		{
			max_val = *(int *)stack->content;
			max_idx = current_idx;
		}
		current_idx++;
		stack = stack->next;
	}
	return (max_idx);
}

size_t	ft_find_min(t_list *stack)
{
	size_t	current_idx;
	size_t	min_idx;
	int		min_val;

	current_idx = 0;
	min_idx = 0;
	min_val = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min_val)
		{
			min_val = *(int *)stack->content;
			min_idx = current_idx;
		}
		current_idx++;
		stack = stack->next;
	}
	return (min_idx);
}
