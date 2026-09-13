/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:59:45 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 16:29:06 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_context **ctx, int should_print)
{
	reverse_rotate(&(*ctx)->a);
	(*ctx)->rra += 1;
	if (should_print)
		write(1, "rra\n", 4);
}

void	rrb(t_context **ctx, int should_print)
{
	reverse_rotate(&(*ctx)->b);
	(*ctx)->rrb += 1;
	if (should_print)
		write(1, "rrb\n", 4);
}

void	rrr(t_context **ctx, int should_print)
{
	reverse_rotate(&(*ctx)->a);
	reverse_rotate(&(*ctx)->b);
	(*ctx)->rrr += 1;
	if (should_print)
		write(1, "rrr\n", 4);
}
