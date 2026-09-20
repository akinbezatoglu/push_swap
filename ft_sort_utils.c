/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:37:21 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/20 20:50:03 by yturkeri         ###   ########.fr       */
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

size_t	ft_find_one(t_list *stack, int val)
{
	long	closest_val;
	size_t	current_idx;
	size_t	found_idx;
	t_list	*stack_tmp;

	closest_val = -2147483649;
	current_idx = 0;
	found_idx = 0;
	stack_tmp = stack;
	while (stack)
	{
		if (*(int *)stack->content < val
			&& *(int *)stack->content > closest_val)
		{
			found_idx = current_idx;
			closest_val = *(int *)stack->content;
		}
		current_idx++;
		stack = stack->next;
	}
	if (closest_val == -2147483649)
		return (ft_find_max(stack_tmp));
	return (found_idx);
}

void	ft_rotate_one_first_b(t_context **ctx, size_t idx)
{
	size_t	stack_size;

	stack_size = ft_lstsize((*ctx)->b);
	if (idx <= stack_size / 2)
	{
		while (idx--)
			rb(ctx);
	}
	else
	{
		idx = stack_size - idx;
		while (idx--)
			rrb(ctx);
	}
}

void	ft_rotate_max_first_b(t_context **ctx)
{
	size_t	max_idx;
	size_t	stack_size;

	max_idx = ft_find_max((*ctx)->b);
	stack_size = ft_lstsize((*ctx)->b);
	if (max_idx == 0)
		return ;
	if (max_idx <= stack_size / 2)
	{
		while (max_idx--)
			rb(ctx);
	}
	else
	{
		max_idx = stack_size - max_idx;
		while (max_idx--)
			rrb(ctx);
	}
}
