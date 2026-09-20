/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:27:41 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/20 21:00:33 by yturkeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple_algorithm(t_context **ctx)
{
	size_t	target_idx;

	pb(ctx);
	while ((*ctx)->a)
	{
		target_idx = ft_find_one((*ctx)->b, *(int *)(*ctx)->a->content);
		ft_rotate_one_first_b(ctx, target_idx);
		pb(ctx);
	}
	ft_rotate_max_first_b(ctx);
	while ((*ctx)->b)
		pa(ctx);
}
