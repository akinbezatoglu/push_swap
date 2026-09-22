/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:45 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/22 16:38:00 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_partition_a_to_b(t_context **ctx, int size, int pivot)
{
	int	i;
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if ((*ctx)->a->index < pivot)
		{
			pb(ctx);
			pushed++;
		}
		else
		{
			ra(ctx);
			rotated++;
		}
		i++;
	}
	if (rotated < (int)ft_lstsize((*ctx)->a))
		while (rotated-- > 0)
			rra(ctx);
	return (pushed);
}

static int	ft_partition_b_to_a(t_context **ctx, int size, int pivot)
{
	int	i;
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if ((*ctx)->b->index >= pivot)
		{
			pa(ctx);
			pushed++;
		}
		else
		{
			rb(ctx);
			rotated++;
		}
		i++;
	}
	if (rotated < (int)ft_lstsize((*ctx)->b))
		while (rotated-- > 0)
			rrb(ctx);
	return (pushed);
}

void	ft_quicksort_a(t_context **ctx, int size)
{
	int	pivot;
	int	pushed;

	if (size <= 3)
	{
		ft_sort_small_a(ctx, size);
		return ;
	}
	pivot = ft_find_pivot((*ctx)->a, size, size / 2);
	pushed = ft_partition_a_to_b(ctx, size, pivot);
	ft_quicksort_a(ctx, size - pushed);
	ft_quicksort_b(ctx, pushed);
}

void	ft_quicksort_b(t_context **ctx, int size)
{
	int	pivot;
	int	pushed;

	if (size <= 2)
	{
		ft_sort_small_b(ctx, size);
		return ;
	}
	pivot = ft_find_pivot((*ctx)->b, size,
			size - size / 2);
	pushed = ft_partition_b_to_a(ctx, size, pivot);
	ft_quicksort_a(ctx, pushed);
	ft_quicksort_b(ctx, size - pushed);
}

void	ft_sort_complex_algorithm(t_context **ctx)
{
	int	size;

	size = ft_lstsize((*ctx)->a);
	ft_quicksort_a(ctx, size);
}
