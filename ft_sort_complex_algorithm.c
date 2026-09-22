/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:45 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/22 21:03:31 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_partition_a_to_b(t_context **ctx, int size, int pivot)
{
	int	pushed;
	int	rotated;
	int	target;
	int	is_whole;

	pushed = 0;
	rotated = 0;
	target = size / 2;
	is_whole = (size == (int)ft_lstsize((*ctx)->a));
	while (size-- > 0 && pushed < target)
	{
		if ((*ctx)->a->index < pivot && ++pushed)
			pb(ctx);
		else if (++rotated)
			ra(ctx);
	}
	if (!is_whole)
	{
		while (rotated-- > 0)
			rra(ctx);
	}
	return (pushed);
}

static int	ft_partition_b_to_a(t_context **ctx, int size, int pivot)
{
	int	pushed;
	int	rotated;
	int	target;
	int	is_whole;

	pushed = 0;
	rotated = 0;
	target = size - (size / 2);
	is_whole = (size == (int)ft_lstsize((*ctx)->b));
	while (size-- > 0 && pushed < target)
	{
		if ((*ctx)->b->index >= pivot && ++pushed)
			pa(ctx);
		else if (++rotated)
			rb(ctx);
	}
	if (!is_whole)
	{
		while (rotated-- > 0)
			rrb(ctx);
	}
	return (pushed);
}

void	ft_quicksort_a(t_context **ctx, int size)
{
	int	pivot;
	int	pushed;

	if (ft_is_sorted_chunk((*ctx)->a, size, 1))
		return ;
	if (size <= 3)
	{
		ft_sort_small(ctx, size, 1);
		return ;
	}
	pivot = ft_find_pivot((*ctx)->a, size);
	pushed = ft_partition_a_to_b(ctx, size, pivot);
	ft_quicksort_a(ctx, size - pushed);
	ft_quicksort_b(ctx, pushed);
}

void	ft_quicksort_b(t_context **ctx, int size)
{
	int	pivot;
	int	pushed;

	if (ft_is_sorted_chunk((*ctx)->b, size, 0))
	{
		while (size--)
			pa(ctx);
		return ;
	}
	if (size <= 3)
	{
		ft_sort_small(ctx, size, 0);
		return ;
	}
	pivot = ft_find_pivot((*ctx)->b, size);
	pushed = ft_partition_b_to_a(ctx, size, pivot);
	ft_quicksort_a(ctx, pushed);
	ft_quicksort_b(ctx, size - pushed);
}

void	ft_sort_complex_algorithm(t_context **ctx)
{
	ft_quicksort_a(ctx, ft_lstsize((*ctx)->a));
}
