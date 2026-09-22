/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:45 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/22 14:09:17 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex_algorithm(t_context **ctx)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize((*ctx)->a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*ctx)->a->index >> i) & 1) == 1)
				ra(ctx);
			else
				pb(ctx);
		}
		while ((*ctx)->b)
			pa(ctx);
	}
}
