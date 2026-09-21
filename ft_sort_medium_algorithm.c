/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:28:10 by yturkeri          #+#    #+#             */
/*   Updated: 2026/09/21 18:46:44 by yturkeri         ###   ########.fr       */
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
		ft_rotate_max_first_b(ctx);
		pa(ctx);
	}
}

void	ft_assign_indexes(t_list *stack)
{
	t_list	*current_node;
	t_list	*first_node;
	int		index;

	current_node = stack;
	while (current_node)
	{
		index = 0;
		first_node = stack;
		while (first_node)
		{
			if (*(int *)first_node->content < *(int *)current_node->content)
				index++;
			first_node = first_node->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}

void	ft_sort_medium_algorithm(t_context **ctx)
{
	int	stack_size;
	int	chunk_size;
	int	pushed;

	stack_size = ft_lstsize((*ctx)->a);
	chunk_size = ft_sqrt(stack_size) * 1.5f;
	ft_assign_indexes((*ctx)->a);
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
