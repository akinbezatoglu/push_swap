/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:37:21 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/22 14:24:45 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_pos(t_list *stack)
{
	int	current_pos;
	int	min_pos;
	int	min_idx;

	current_pos = 0;
	min_pos = 0;
	min_idx = stack->index;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			min_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (min_pos);
}

int	ft_get_target_pos(t_list *stack, int target_idx)
{
	int		closest_idx;
	int		current_pos;
	int		target_pos;
	t_list	*stack_tmp;

	closest_idx = -1;
	target_pos = -1;
	current_pos = 0;
	stack_tmp = stack;
	while (stack_tmp)
	{
		if (stack_tmp->index < target_idx
			&& stack_tmp->index > closest_idx)
		{
			closest_idx = stack_tmp->index;
			target_pos = current_pos;
		}
		current_pos++;
		stack_tmp = stack_tmp->next;
	}
	if (target_pos == -1)
		return (ft_get_target_pos(stack, 2147483647));
	return (target_pos);
}

void	ft_rotate_a_target_pos_to_first(t_context **ctx, int target_pos)
{
	int	stack_size;

	stack_size = ft_lstsize((*ctx)->a);
	if (target_pos <= stack_size / 2)
	{
		while (target_pos--)
			ra(ctx);
	}
	else
	{
		target_pos = stack_size - target_pos;
		while (target_pos--)
			rra(ctx);
	}
}

void	ft_rotate_b_target_pos_to_first(t_context **ctx, int target_pos)
{
	int	stack_size;

	stack_size = ft_lstsize((*ctx)->b);
	if (target_pos <= stack_size / 2)
	{
		while (target_pos--)
			rb(ctx);
	}
	else
	{
		target_pos = stack_size - target_pos;
		while (target_pos--)
			rrb(ctx);
	}
}

void	ft_rotate_b_max_to_first(t_context **ctx)
{
	int	max_pos;

	max_pos = ft_get_target_pos((*ctx)->b, 2147483647);
	if (max_pos > 0)
		return (ft_rotate_b_target_pos_to_first(ctx, max_pos));
}
