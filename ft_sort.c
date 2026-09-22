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
	int	max_pos;

	max_pos = ft_get_target_pos((*ctx)->a, 2147483647);
	if (max_pos == 0)
		ra(ctx);
	else if (max_pos == 1)
		rra(ctx);
	if ((*ctx)->a->index > (*ctx)->a->next->index)
		sa(ctx);
}

void	ft_sort_five(t_context **ctx)
{
	int	size;
	int	min_pos;

	size = ft_lstsize((*ctx)->a);
	while (size > 3)
	{
		min_pos = ft_find_min_pos((*ctx)->a);
		ft_rotate_a_target_pos_to_first(ctx, min_pos);
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
