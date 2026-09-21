/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:45 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/21 20:31:33 by yturkeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex_algorithm(t_context **ctx)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	ft_assign_indexes((*ctx)->a);
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
