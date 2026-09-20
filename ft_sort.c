/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:32:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 16:59:11 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_context **ctx)
{
	size_t	max_idx;

	max_idx = ft_find_max((*ctx)->a);
	if (max_idx == 0)
		ra(ctx);
	else if (max_idx == 1)
		rra(ctx);
	if (*(int *)(*ctx)->a->content > *(int *)(*ctx)->a->next->content)
		sa(ctx);
}

void	ft_sort_five(t_context **ctx)
{
	size_t	size;
	size_t	min_idx;

	size = ft_lstsize((*ctx)->a);
	while (size > 3)
	{
		min_idx = ft_find_min((*ctx)->a);
		if (min_idx <= size / 2)
		{
			while (min_idx--)
				ra(ctx);
		}
		else
		{
			min_idx = size - min_idx;
			while (min_idx--)
				rra(ctx);
		}
		pb(ctx);
		size--;
	}
	ft_sort_three(ctx);
	while ((*ctx)->b)
		pa(ctx);
}

void	ft_sort_adaptive_algorithm(t_context **ctx)
{
	if ((*ctx)->disorder < 0.2f)
		ft_sort_simple_algorithm(ctx);
	else if ((*ctx)->disorder < 0.5f)
		ft_sort_medium_algorithm(ctx);
	else
		ft_sort_complex_algorithm(ctx);
}

void	ft_sort(t_context **ctx)
{
	size_t	size;

	size = ft_lstsize((*ctx)->a);
	if (size == 2)
		sa(ctx);
	else if (size == 3)
		ft_sort_three(ctx);
	else if (size <= 5)
		ft_sort_five(ctx);
	else if ((*ctx)->strategy == SIMPLE)
		ft_sort_simple_algorithm(ctx);
	else if ((*ctx)->strategy == MEDIUM)
		ft_sort_medium_algorithm(ctx);
	else if ((*ctx)->strategy == COMPLEX)
		ft_sort_complex_algorithm(ctx);
	else
		ft_sort_adaptive_algorithm(ctx);
}
