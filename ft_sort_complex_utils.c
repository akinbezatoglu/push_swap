/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:57:17 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 16:38:00 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_array(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				ft_swap_int(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

int	ft_find_pivot(t_list *stack, int size, int rank)
{
	int	*arr;
	int	i;
	int	pivot;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (stack->index);
	i = 0;
	while (i < size && stack)
	{
		arr[i] = stack->index;
		stack = stack->next;
		i++;
	}
	ft_sort_array(arr, size);
	pivot = arr[rank];
	free(arr);
	return (pivot);
}

static void	ft_sort_three_a_desc(t_context **ctx)
{
	sa(ctx);
	pb(ctx);
	sa(ctx);
	pa(ctx);
	sa(ctx);
}

void	ft_sort_small_a(t_context **ctx, int size)
{
	int	a;
	int	b;
	int	c;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*ctx)->a->index > (*ctx)->a->next->index)
			sa(ctx);
		return ;
	}
	a = (*ctx)->a->index;
	b = (*ctx)->a->next->index;
	c = (*ctx)->a->next->next->index;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		pb(ctx);
		sa(ctx);
		pa(ctx);
	}
	else if (b < a && a < c)
		sa(ctx);
	else if (c < a && a < b)
	{
		pb(ctx);
		sa(ctx);
		pa(ctx);
		sa(ctx);
	}
	else if (b < c && c < a)
	{
		sa(ctx);
		pb(ctx);
		sa(ctx);
		pa(ctx);
	}
	else
		ft_sort_three_a_desc(ctx);
}

void	ft_sort_small_b(t_context **ctx, int size)
{
	if (size <= 0)
		return ;
	if (size == 1)
	{
		pa(ctx);
		return ;
	}
	if ((*ctx)->b->index < (*ctx)->b->next->index)
		sb(ctx);
	pa(ctx);
	pa(ctx);
}
