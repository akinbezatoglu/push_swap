/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:10 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/22 14:09:23 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_sqrt(size_t number)
{
	size_t	i;

	if (number < 0)
		return (0);
	i = 1;
	while (i * i <= number && i <= 46340)
		i++;
	return (i - 1);
}

static void	ft_sort_b_to_a(t_context **ctx)
{
	while ((*ctx)->b)
	{
		ft_rotate_b_max_to_first(ctx);
		pa(ctx);
	}
}

void	ft_sort_medium_algorithm(t_context **ctx)
{
	int	stack_size;
	int	chunk_size;
	int	pushed;

	stack_size = ft_lstsize((*ctx)->a);
	chunk_size = ft_sqrt(stack_size) * 1.5f;
	pushed = 0;
	while ((*ctx)->a)
	{
		if ((*ctx)->a->index <= pushed)
		{
			pb(ctx);
			rb(ctx);
			pushed++;
		}
		else if ((*ctx)->a->index <= pushed + chunk_size)
		{
			pb(ctx);
			pushed++;
		}
		else
			ra(ctx);
	}
	ft_sort_b_to_a(ctx);
}
