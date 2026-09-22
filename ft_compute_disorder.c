/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 09:24:22 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 14:29:36 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_list *a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*next_node;

	mistakes = 0.0f;
	total_pairs = 0.0f;
	while (a)
	{
		next_node = a->next;
		while (next_node)
		{
			total_pairs += 1.0f;
			if (a->index > next_node->index)
				mistakes += 1.0f;
			next_node = next_node->next;
		}
		a = a->next;
	}
	if (total_pairs == 0.0f)
		return (0.0f);
	return (mistakes / total_pairs);
}
