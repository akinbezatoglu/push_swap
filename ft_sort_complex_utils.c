/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:57:17 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 21:03:40 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_chunk(t_list *stack, int size, int is_a)
{
	while (size-- > 1 && stack && stack->next)
	{
		if (is_a && stack->index > stack->next->index)
			return (0);
		if (!is_a && stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_find_pivot(t_list *stack, int size)
{
	int	min;
	int	i;

	min = stack->index;
	i = 0;
	while (i < size && stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
		i++;
	}
	return (min + (size / 2));
}

static void	ft_sort_three_a(t_context **ctx)
{
	int	a;
	int	c;

	if ((*ctx)->a->index > (*ctx)->a->next->index)
		sa(ctx);
	a = (*ctx)->a->index;
	c = (*ctx)->a->next->next->index;
	if (a > c)
	{
		pb(ctx);
		sa(ctx);
		pa(ctx);
		sa(ctx);
	}
	else if ((*ctx)->a->next->index > c)
	{
		pb(ctx);
		sa(ctx);
		pa(ctx);
	}
}

static void	ft_sort_three_b(t_context **ctx)
{
	int	a;
	int	c;

	if ((*ctx)->b->index < (*ctx)->b->next->index)
		sb(ctx);
	a = (*ctx)->b->index;
	c = (*ctx)->b->next->next->index;
	if (a < c)
	{
		pa(ctx);
		sb(ctx);
		pb(ctx);
		sb(ctx);
	}
	else if ((*ctx)->b->next->index < c)
	{
		pa(ctx);
		sb(ctx);
		pb(ctx);
	}
	pa(ctx);
	pa(ctx);
	pa(ctx);
}

void	ft_sort_small(t_context **ctx, int size, int is_a)
{
	if (is_a)
	{
		if (size == 2 && (*ctx)->a->index > (*ctx)->a->next->index)
			sa(ctx);
		else if (size == 3)
			ft_sort_three_a(ctx);
	}
	else
	{
		if (size == 1)
			pa(ctx);
		else if (size == 2)
		{
			if ((*ctx)->b->index < (*ctx)->b->next->index)
				sb(ctx);
			pa(ctx);
			pa(ctx);
		}
		else if (size == 3)
			ft_sort_three_b(ctx);
	}
}
