/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:45 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/23 11:41:00 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_digit(int idx)
{
	int	count;

	count = 0;
	while (idx != 0)
	{
		idx = idx / 2;
		count++;
	}
	return (count);
}

void	ft_sort_complex_algorithm(t_context **ctx)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize((*ctx)->a);
	max_bits = ft_count_digit(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*ctx)->a->index >> i) & 1) == 1)
				ra(ctx);
			else
				pb(ctx);
			j++;
		}
		while ((*ctx)->b)
			pa(ctx);
		i++;
	}
}
